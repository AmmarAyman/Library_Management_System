#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include <iostream>
#include <string>
#include "sqlite3.h"

using namespace std;


class InputManager{

private:
	sqlite3* db;

public:

	string dep;
	string auth;
	string tit;
	int id;

	InputManager () {
		sqlite3_open("books_data.db", &db);
	}

	~InputManager() {
		sqlite3_close(db);
	}

	void getData() {

		cin.ignore();
		cout << "Type The Department: ";
		getline(cin, dep);

		cout << "Type the Author: ";
		getline(cin, auth);

		cout << "Type the title: ";
		getline(cin, tit);

		cout << "Type the Book ID: ";
		cin >> id;
	}

	// virtual void checkID(int id) = 0;             // Handling the Check of ID will be MUCH Easier in BookManager


	bool checkID(int bookID) {
		if (!db) {
			cerr << "Database connection is not initialized." << endl;
			return false;
		}

		sqlite3_stmt* stmt;
		string sql = "SELECT * FROM Books WHERE book_id = " + to_string(bookID);
		if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) == SQLITE_OK) {
			if (sqlite3_step(stmt) == SQLITE_ROW) {
				sqlite3_finalize(stmt);
				return true; // ID exists
			}
			sqlite3_finalize(stmt);
		}
		return false; // ID does not exist
	}
};

#endif
