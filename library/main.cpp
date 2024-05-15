#include <iostream>
#include <string>
#include <fstream>
#include "BookManager.h"
#include "InputManager.h"

// How to use GitHub
// git status
// git add "name of file"
// git commit -m "Description of what you did"
// git push origin master
// https://github.com/AmmarAyman/Library_Management_System/tree/master


using namespace std;


int main() {

	BookManager test1("Electronics", "THE DEAD", "AMMAR AYMAN", 235103);
	test1.addBook();

	BookManager test2("Electronics", "BRUH", "Sameh", 56187);
	test2.addBook();

	BookManager test3("Electronics", "NIGGA", "WHAAT", 219561);
	test3.addBook();

	cout << "Added" << endl;

	cout << "TEST" << endl;

	test1.viewBooks("Electronics");

	return 0;
}
