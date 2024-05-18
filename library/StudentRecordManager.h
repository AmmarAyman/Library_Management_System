#ifndef STUDENTRECORDMANAGER_H
#define STUDENTRECORDMANAGER_H
#include <iostream>
#include <string>
#include "sqlite3.h"
#include "BookManager.h"

using namespace std;

class StudentRecordManager : public BookManager { 
protected:
	string studentName;
	string department;
	int studentID;

	sqlite3* db2;


	int executeQuery(const string& sql) {                  // Function For Applying SQLite Commands
		char* errorMessage;
		int r = sqlite3_exec(db2, sql.c_str(), NULL, NULL, &errorMessage);
		if (r != SQLITE_OK) {
			cerr << "SQL error: " << errorMessage << endl;
			sqlite3_free(errorMessage);
		}
		return r;
	}


public:
	StudentRecordManager() {

		studentName = "";
		department = "";
		studentID = 0;

		int r = sqlite3_open("student_db.db", &db2);
		if (r) {
			cerr << "Can't open database: " << sqlite3_errmsg(db2) << endl;
		}
		else {
			cout << "Opened database successfully" << endl;
		}

		string createTableSQL = "CREATE TABLE IF NOT EXISTS students(department TEXT, name TEXT, student_id INTEGER, book_id INTEGER)";
		executeQuery(createTableSQL);
	}



	~StudentRecordManager() {
		sqlite3_close(db2);
	}

	void issuerecord() {

		cout << "Please provide your credentials\n" << "Name: ";
		cin.ignore();
		getline(cin, studentName);
		cout << "\nID: ";
		cin >> studentID;
		cout << "\nDepartment: ";
		cin >> department;
		cout << "\nWrite the ID of the book: ";
		cin >> bookID;
		if (issueBook(bookID)) {

			cout << " the book succesfully issued ";

			string sql = "INSERT INTO students (department, name, student_id, book_id) VALUES ('" + department + "', '" + studentName + "', " + to_string(studentID) + ", " + to_string(bookID) + ")";
			int r = executeQuery(sql);
			if (r == SQLITE_OK) {
				cout << "Student record added successfully!" << endl;
			}
		}
	}
};

#endif
