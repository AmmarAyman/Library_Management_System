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

};


#endif