#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H
#include "sqlite3.h"
#include <string>

using namespace std;


class BookManager {

protected:
	string department;
	string title;
	string author;
	int bookID;

	sqlite3* db;

	int executeQuery(const string& sql) {                  // Function For Applying SQLite Commands
		char* errorMessage;
		int rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, &errorMessage);
		if (rc != SQLITE_OK) {
			cerr << "SQL error: " << errorMessage << endl;
			sqlite3_free(errorMessage);
		}
		return rc;
	}


public:

	BookManager() {
		department = "";
		title = "";
		author = "";
		bookID = 0;

		int rc;
		rc = sqlite3_open("books_data.db", &db);       // Opening The Data Base

	}

	BookManager(string dep, string tit, string auth, int ID) {
		department = dep;
		title = tit;
		author = auth;
		bookID = ID;

		int rc;
		rc = sqlite3_open("books_data.db", &db);
	}

	~BookManager () {         // Closing the Data Base
		sqlite3_close(db);
	}

	void addBook(const string& department) {
		string sql = "INSERT INTO Books (department, title, book_id, author) VALUES ('" + department + "', '" + title + "', " + to_string(bookID) + ", '" + author + "')";
		int rc = executeQuery(sql);
		if (rc == SQLITE_OK) {
			cout << "Book added successfully!" << endl;
		}
	}

	void deleteBook(int bookID) {
		string sql = "DELETE FROM Books WHERE book_id = " + to_string(bookID);
		int rc = executeQuery(sql);
		if (rc == SQLITE_OK) {
			cout << "Book deleted successfully!" << endl;
		}
	}

	void editBook(int bookID) {

		string title, author, department;

		cin.sync();
		cout << "Type the New Title: ";
		getline(cin, title);

		cin.sync();
		cout << "Type the New Author: ";
		getline(cin, author);

		cin.sync();
		cout << "Type the New depatment: ";
		getline(cin, department);


		string sql = "UPDATE Books SET department = '" + department + "', title = '" + title + "', author = '" + author + "' WHERE book_id = " + to_string(bookID);
		int rc = executeQuery(sql);
		if (rc == SQLITE_OK) {
			cout << "Book edited successfully!" << endl;
		}
	}


};

#endif
