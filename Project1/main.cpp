#include "includes.h" // Includes all the requirements to run this program

void addAnswer(string question)
{
	string ans; // Hold the new answer

	cout << "New answer: "; 
	cin >> ans; // Takes the answer
	try {
		//MySQL stuff
		sql::Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;

		//Creates a connection 
		driver = get_driver_instance();
		con = driver->connect(URL, USER, PASS);
		// Connect to the MySQL database
		con->setSchema("main");

		//Makes the MySQL statement
		stmt = con->createStatement();
		//Calls MySQL statement
		stmt->execute("CALL addData('"+question+"','"+ans+"')");

		delete stmt;
		delete con;

	}
	catch (sql::SQLException &e) {
		//Only Triggered if an error occures 
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

}

void getAnwer(string quest1)
{
	try {
		sql::Driver *driver;
		sql::Connection *con;
		sql::Statement *stmt;
		sql::ResultSet *res;

		/* Create a connection */
		driver = get_driver_instance();
		con = driver->connect(URL, USER, PASS);
		/* Connect to the MySQL test database */
		con->setSchema("main");

		stmt = con->createStatement();
		stmt->execute("CALL getData('" + quest1 +"', @ans)");
		res = stmt->executeQuery("SELECT @ans AS _message");
		while (res->next()) {
			if (res->getString("_message") == "")
			{
				string a;
				cout << "Do you want to answer the question? (Y/[n]) ";
				cin >> a;
				if (a == "Y" || a == "y")
				{
					addAnswer(quest1);
				}
				break;
			}
			cout << "Answer: ";
			/* Access column data by alias or column name */
			cout << res->getString("_message") << endl;
		}
		delete res;
		delete stmt;
		delete con;

	}
	catch (sql::SQLException &e) {
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}

	cout << endl;
}


void StandUser()
{
	while (true)
	{
		system("CLS");
		cout << "QUESTION: ";

		char q[50] = "";
		cin.getline(q, 50);

		getAnwer(q);

		system("pause");
	}
}

void AdminUser2()
{
	//TODO: make admin pannel
}


void AdminUser1()
{
	string x;
	cout << "PASSWORD: ";
	cin >> x;
	if (x == ADMINPASS)
	{
		cout << "APPROVED\n";
		system("PAUSE");
		AdminUser2();
	}
	else
	{
		cout << "DENIED\n";
		system("PAUSE");
		StandUser();
	}
}

int main(void)
{
	cout << disclaimer << endl;
	system("pause");
	cout << "User Type: Admin / Normal (A/[n]): ";
	string x;
	cin >> x;
	if (x == "n" || x == "N") {
		StandUser();
	}
	else if (x == "A")
	{
		AdminUser1();
	}
	return EXIT_SUCCESS;
}