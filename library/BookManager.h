#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H
#include "sqlite3.h"
#include <string>
#include "InputManager.h"

using namespace std;


class BookManager : public InputManager {

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

		string createTableSQL = "CREATE TABLE IF NOT EXISTS Books (department TEXT, title TEXT, book_id TEXT, author TEXT)";
		executeQuery(createTableSQL);

	}

	BookManager(string dep, string tit, string auth, int ID) {
		department = dep;
		title = tit;
		author = auth;
		bookID = ID;

		int rc;
		rc = sqlite3_open("books_data.db", &db);

		string createTableSQL = "CREATE TABLE IF NOT EXISTS Books (department TEXT, title TEXT, book_id TEXT, author TEXT)";
		executeQuery(createTableSQL);

	}

	~BookManager () {         // Closing the Data Base
		sqlite3_close(db);
	}

	void addBook() {

		InputManager inp;
		inp.getData();

		department = inp.dep;
		title = inp.tit;
		author = inp.auth;
		bookID = inp.id;

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

		cin.ignore();
		cout << "Type the New Title: ";
		getline(cin, title);

		// cin.sync();
		cout << "Type the New Author: ";
		getline(cin, author);

		// cin.sync();
		cout << "Type the New department: ";
		getline(cin, department);


		string sql = "UPDATE Books SET department = '" + department + "', title = '" + title + "', author = '" + author + "' WHERE book_id = " + to_string(bookID);
		int rc = executeQuery(sql);
		if (rc == SQLITE_OK) {
			cout << "Book edited successfully!" << endl;
		}
	}

	void viewBooks() {
		sqlite3_stmt* stmt;
		const char* sql = "SELECT * FROM Books";
		if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK) {
			cout << "Listing all books:" << endl;
			while (sqlite3_step(stmt) == SQLITE_ROW) {
				cout << "Department: " << sqlite3_column_text(stmt, 0) << endl;
				cout << "Title: " << sqlite3_column_text(stmt, 1) << endl;
				cout << "Book ID: " << sqlite3_column_text(stmt, 2) << endl;
				cout << "Author: " << sqlite3_column_text(stmt, 3) << endl << endl;
			}
			sqlite3_finalize(stmt);
		}
		else {
			cerr << "Failed to retrieve books." << endl;
		}
	}


	void searchBook() {
		int choice;
		string input;
		string sql;
		sqlite3_stmt* stmt;

		cout << "Choose your search Option:" << endl;
		cout << "1. By Title" << endl;
		cout << "2. By Author" << endl;
		cout << "3. By Book ID" << endl;
		cout << "Enter your choice (1-3): ";
		cin >> choice;
		cin.ignore();

		switch (choice) {
		case 1:
			cout << "Enter the title: ";
			getline(cin, input);
			sql = "SELECT * FROM Books WHERE title LIKE '%" + input + "%'";
			break;
		case 2:
			cout << "Enter the author: ";
			getline(cin, input);
			sql = "SELECT * FROM Books WHERE author LIKE '%" + input + "%'";
			break;
		case 3:
			cout << "Enter the book ID: ";
			getline(cin, input);
			sql = "SELECT * FROM Books WHERE book_id = " + input;
			break;
		default:
			cout << "Invalid choice." << endl;
			return;
		}

		if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) == SQLITE_OK) {
			bool found = false;
			while (sqlite3_step(stmt) == SQLITE_ROW) {
				found = true;
				cout << "Department: " << sqlite3_column_text(stmt, 0) << endl;
				cout << "Title: " << sqlite3_column_text(stmt, 1) << endl;
				cout << "Book ID: " << sqlite3_column_text(stmt, 2) << endl;
				cout << "Author: " << sqlite3_column_text(stmt, 3) << endl << endl;
			}
			if (!found) {
				cout << "No books found." << endl;
			}
			sqlite3_finalize(stmt);
		}
		else {
			cerr << "Failed to search for books." << endl;
		}
	}



};

#endif
