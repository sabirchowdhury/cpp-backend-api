// #include <stdlib.h>
// #include <iostream>

// #include <jdbc\mysql_driver.h>
// #include <jdbc\mysql_connection.h>
// #include <jdbc\cppconn\prepared_statement.h>


// using namespace std;


// int main()
// {
    

//     cout << "Program start" << endl;

//     try{
//     sql::mysql::MySQL_Driver *driver;
//     sql::Connection *con;
//     sql::Statement *stmt;
//     sql::ResultSet *res;


//     try {
//         // Set connection and schema

//         driver = sql::mysql::get_mysql_driver_instance();
//         con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
//         con->setSchema("mysqldb"); // Switch to your database

//         // Execute SQL queries and handle results here

//         // Prepare SQL insert statement

//         stmt = con->createStatement();


//         // Execute prepared statement

//         res = stmt->executeQuery("SELECT * FROM persons;");
//         try {

//         while (res->next()) {
//             cout << "\t... MySQL replies: ";
//             /* Access column data by alias or column name */
//             cout << res->getString("_message") << endl;
//             cout << "\t... MySQL says it again: ";
//             /* Access column data by numeric offset, 1 is the first column */
//             cout << res->getString(1) << endl;
//         }
//     } catch (sql::SQLException &e) {
//         cout << "errorrror 2";
//     }

//     } catch (sql::SQLException &e) {
//         cout << "errorrororo 1";
//     }
    
//     delete res;
//     delete con;
//     delete stmt;


//     } catch (sql::SQLException &e) {
//     cout << "did not run";
//     // cout << "# ERR: SQLException in " << __FILE__;
//     // cout << "(" << __FUNCTION__ << ") on line "<< __LINE__ << endl;
//     cout << "# ERR: " << e.what();
//     cout << " (MySQL error code: " << e.getErrorCode();
//     cout << ", SQLState: " << e.getSQLState() << " )" << endl;
//     } 
//     return 0;
// }






#include <stdlib.h>
#include <iostream>

// #include <jdbc\mysql_driver.h>
// #include <jdbc\mysql_connection.h>
// #include <jdbc\cppconn\prepared_statement.h>
#include <mysql\jdbc.h>




using namespace std;

int main(void)
{
cout << endl;
cout << "Running 'SELECT 'Hello World!' AS _message'..." << endl;

try {
  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  sql::ResultSet *res;
  cout << "No error in var creation" << endl;

  /* Create a connection */
  driver = get_driver_instance();
  cout << "Driver instance created" << endl;

  con = driver->connect("tcp://127.0.0.1:3306", "root", "password");
  cout << "Successful connection" << endl;

  /* Connect to the MySQL test database */
  con->setSchema("mysqldb");
  cout << "schema set" << endl;


  stmt = con->createStatement();
  cout << "statement created" << endl;

  res = stmt->executeQuery("SELECT 'Hello World!' AS _message");
  cout << "statement executed" << endl;

  while (res->next()) {
    cout << "\t... MySQL replies: ";
    /* Access column data by alias or column name */
    cout << res->getString("_message") << endl;
    cout << "\t... MySQL says it again: ";
    /* Access column data by numeric offset, 1 is the first column */
    cout << res->getString(1) << endl;
  }
  cout << "data read" << endl;

  delete res;
  delete stmt;
  delete con;
  cout << "data is cleaned up" << endl;


} catch (sql::SQLException &e) {
  cout << "# ERR: SQLException in " << __FILE__;
//   cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
  cout << "# ERR: " << e.what();
  cout << " (MySQL error code: " << e.getErrorCode();
  cout << ", SQLState: " << e.getSQLState() << " )" << endl;
}

cout << endl;

return EXIT_SUCCESS;
}