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
		cout << "Type the New department: ";
		getline(cin, department);


		string sql = "UPDATE Books SET department = '" + department + "', title = '" + title + "', author = '" + author + "' WHERE book_id = " + to_string(bookID);
		int rc = executeQuery(sql);
		if (rc == SQLITE_OK) {
			cout << "Book edited successfully!" << endl;
		}
	}

	void searchBook() {

		int search_option;
		string search_key;
		string search_parameter;

		cout << "1 : Search by title\n2 : Search by author\n3 : Search by ID";
		cin >> search_option;

		if (search_option == 1) {
			search_key == "title";
			cin.sync();
			getline(cin, search_parameter);
		}
		else if (search_option == 2) {
			search_key == "author";
			cin.sync();
			getline(cin, search_parameter);
		}
		else if (search_option == 3) {
			search_key == "book_id";
			int id;
			cin >> id;
			search_parameter = to_string(id);
		}
		else {
			cout << "Wrong Choice, Now by default you will search by title: ";
			cin.sync();
			getline(cin, search_parameter);
		}
		

		string sql = "SELECT * FROM Books WHERE title = '" + title + "'";
		char** results = NULL;
		int rows, columns;
		int rc = sqlite3_get_table(db, sql.c_str(), &results, &rows, &columns, NULL);
		if (rc == SQLITE_OK) {
			if (rows > 0) {
				cout << "Search results:" << endl;
				for (int i = 0; i < rows; i++) {
					cout << "Title: " << results[(i + 1) * columns + 1] << ", Department: " << results[(i + 1) * columns + 2] << ", Book ID: " << results[(i + 1) * columns + 3] << ", Author: " << results[(i + 1) * columns + 4] << endl;
				}
			}
			else {
				cout << "Book not found!" << endl;
			}
			sqlite3_free_table(results);
		}
	}


};

#endif
