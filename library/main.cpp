#include <iostream>
#include "BookManager.h"

// How to use GitHub
// git status
// git add "name of file"
// git commit -m "Description of what you did"
// git push origin master
// https://github.com/AmmarAyman/Library_Management_System/tree/master


using namespace std;


int main() {


	BookManager test ("computer", "program", "essam", 5962);

	// test.addBook("computer");

	test.editBook(5962);

	test.viewBooks();

	test.searchBook();

	return 0;
}
