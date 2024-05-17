#include <iostream>
#include "BookManager.h"
#include "MainMenu.h"

// How to use GitHub
// git status
// git add "name of file"
// git commit -m "Description of what you did"
// git push origin master
// https://github.com/AmmarAyman/Library_Management_System/tree/master


using namespace std;


int main() {


	BookManager test;
	mainmenu menu;


	int n;
	int id;

	while (true) {

		menu.display_main_menu();
		cout << "Type your Choice: ";
		cin >> n;
		if (n == 1) {
			cout << "\n=============================\n";
			test.addBook();
			cout << "\n=============================\n";
		}
		else if (n == 2) {
			cout << "write the id of the book you want to delete : ";
			cin >> id;
			cout << "\n=============================\n";
			test.deleteBook(id);
			cout << "\n=============================\n";

		}
		else if (n == 3) {
			cout << " write the id of the book : ";
			cin >> id;
			cout << "\n=============================\n";
			test.editBook(id);
			cout << "\n=============================\n";

		}
		else if (n == 4) {
			cout << "\n=============================\n";
			test.searchBook();
			cout << "\n=============================\n";
		}
		else if (n == 5) {
			cout << "\n=============================\n";
			continue;           // Till adding the issue book;
			cout << "\n=============================\n";

		}
		else if (n == 6) {
			cout << "\n=============================\n";
			test.viewBooks();
			cout << "\n=============================\n";
		}
		else if (n == 7) {
			cout << "\n=============================\n";
			cout << " Type the ID: ";
			cin >> id;
			if (test.checkID(id) == 1) {
				cout << "Book EXISTS !";
			}
			else {
				cout << "Book Doesn't EXISTS !";
			}
			cout << "\n=============================\n";
		}

		else {
			break;
		}

	}

	return 0;
}
