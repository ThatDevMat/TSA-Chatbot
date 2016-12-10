#pragma once

//start System Includes
#include <stdlib.h>
#include <iostream>
#include <string.h>
//end System Includes

//Start MySQL
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
//end MySQL

//start NameSpaces
using namespace std;
//end NameSpaces

//Disclaimer
const string disclaimer = "DISCLAIMER!\n-This service is not designed for cheating.\ngoogle the answer for more info.\nThis service is designed as an aid not for cheating.";

//Start PreDefined Variables 
#define URL "127.0.0.1"
#define USER "root"
#define PASS "TSA!"
#define ADMINPASS "TSA!1" //Change this to change admin password.
/*
* TODO:
* - Make admin password only in database
*/
//End PreDefined Variables