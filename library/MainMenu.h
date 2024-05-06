#include <iostream>
using namespace std;
#ifndef MAINMENU_H
#define MAINMENU_H


class mainmenu {
public :
	void display_main_menu() {
		cout << "what is in your mind \n 1- add book\n 2-delete book\n 3- edit book\n 4- search book\n 5- issue book\n 6- view books"
			<< " write the number of the command";
	}
};
#endif // !MAINMENU_H
