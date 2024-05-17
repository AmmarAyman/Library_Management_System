#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include <iostream>
#include <string>

using namespace std;


class InputManager{

public:

	string dep;
	string auth;
	string tit;
	int id;

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



};

#endif
