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
mainmenu test1;



int n;
int id;
string type;
test1.display_main_menu();
cin >> n;
if (n == 1) {
	cout << " what type of books you want to add : ";
	cin >> type;
	test.addBook(type);


}
else if (n ==2){
	cout << "write the id of the book you want to delete : ";
	cin >> id;
	test.deleteBook(id);

}
else if (n == 3) {
	cout << " write the id of the book : ";
	cin >> id;
	test.editBook(id);

}
else if (n == 4) {
	test.searchBook();

}

else{
	test.viewBooks();
}



	return 0;
}
