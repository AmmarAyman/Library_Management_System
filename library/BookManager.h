#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H
#include <iostream>
#include <fstream>

using namespace std;


class BookManager {

protected:
	string department;
	string title;
	string author;
	int bookID;

public:

	BookManager() {
		department = "";
		title = "";
		author = "";
		bookID = 0;
	}

	BookManager(string dep, string tit, string auth, int ID) {
		department = dep;
		title = tit;
		author = auth;
		bookID = ID;
	}

	void addBook() {
		// Majors: Computer, Electrical, Civil, Electronics, Mechanical and Architecture

		if (department == "Electronics") {
			ofstream file("Electronics.txt", ios_base::app);
			file << title << "\t" << author << "\t" << bookID << endl;
			file.close();
		}

		else if (department == "Computer") {
			ofstream file("Computer.txt", ios_base::app);
			file << title << "\t" << author << "\t" << bookID << endl;
			file.close();
		}

		else if (department == "Electrical") {
			ofstream file("Electrical.txt", ios_base::app);
			file << title << "\t" << author << "\t" << bookID << endl;
			file.close();
		}

		else if (department == "Civil") {
			ofstream file("Civil.txt", ios_base::app);
			file << title << "\t" << author << "\t" << bookID << endl;
			file.close();
		}

		else if (department == "Mechanical") {
			ofstream file("Mechanical.txt", ios_base::app);
			file << title << "\t" << author << "\t" << bookID << endl;
			file.close();
		}

		else if (department == "Architecture") {
			ofstream file("Architecture.txt", ios_base::app);
			file << title << "\t" << author << "\t" << bookID << endl;
			file.close();
		}

	}

	void viewBooks(string department) { // Not Working
		string path = "";
		path += department;
		path += ".txt";

		ifstream file(path);

		string title, author;
		int id;

		cout << "[ ";

		while ((file >> title >> author >> id)) {       // !file.eof()
			// file >> title >> author >> id;
			cout << title << " , ";
		}
		file.close();

		cout << " ]";
	}


};

#endif
