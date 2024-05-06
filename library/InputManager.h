#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include "BookManager.h"
#include <iostream>

using namespace std;

class InputManager : public BookManager {

public:
	void getData() {

		cout << "Type The Department: ";
		cin >> department;

		cout << "Type the Author: ";
		cin >> author;

		cout << "Type the title: ";
		cin >> title;

		cout << "Type the Book ID: ";
		cin >> bookID;
	}


	// How can this check for ID in main ?!?! [it must be an Object to be used in main]
	bool checkID(int BookID) {        // Copied (viewBooks) and resued [we msh fahimha barod]
		string path = department + ".txt";
		ifstream file(path);
		if (!file.is_open()) {
			cout << "Could not open file: " << path << endl;
			return;
		}

		string line;
		cout << "[ ";
		while (getline(file, line)) {
			stringstream ss(line);
			string title, author;
			int id;
			getline(ss, title, '\t');
			getline(ss, author, '\t');
			ss >> id;
			cout << title << " , ";

			if (BookID == id) {        // The Check
				return true;
			}
		}
		cout << " ]" << endl;
		file.close();

		return false;
	}

};


#endif