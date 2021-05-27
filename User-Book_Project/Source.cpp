#include <iostream>
#include "User.h"
#include "Book.h"
#include "UserList.h"
#include "BookList.h"
using namespace std;
static void run(BookList& b, UserList& u)/*Parameters: BookList(b), UserList(u)
										 *control the run of the entire program*/
{
	cout << "Select one of the following choices:\n1- Book menu\n2- User menu\n3- Exit" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		b.bookMenu(u);
		run(b, u);
	case 2:
		u.userMenu();
		run(b, u);
	default:
		exit(0);
	}
}
int main()
{
	UserList s(20);
	BookList b(20);
	run(b, s);
	return 0;
}
