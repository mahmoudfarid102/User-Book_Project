#include "UserList.h"

UserList::UserList(int c) : capacity(c)
{
	User::ucount -= c;
	users = new User[c];
	for (int i = 0; i < c; i++) {
		users[i].setId(0);
		users[i].setAge(0);
		users[i].setEmail("");
		users[i].setName("");
	}
}

void UserList::addUser(User user)
{
	for (int i = 0; i < usersCount; i++) {
		if (users[i].getAge() == 0) {
			users[i] = user;
			break;
		}
	}
}

User& UserList::searchUser(string name)
{
	int k = 0;
	for (int i = 0; i < usersCount; i++) {
		if (users[i].getName() == name) {
			cout << users[i];
			return users[i];
		}
	}
	cout << "Error user not found" << endl;
	userMenu();
}

User& UserList::searchUser(int id)
{
	for (int i = 0; i < usersCount; i++) {
		if (users[i].getId() == id) {
			cout << users[i];
			return users[i];
		}
	}
	cout << "Error user not found" << endl;
}

void UserList::deleteUser(int id)
{
	for (int i = 0; i < usersCount; i++) {
		if (users[i].getId() == id) {
			for (i; i < capacity - 1; i++) {
				users[i] = users[i + 1];
			}
		}
	}
	userMenu();
}

User& UserList::operator[](int n)
{
	if (n > usersCount || n > capacity) {
		cout << "Error" << endl;
		exit(0);
	}
	else
		return users[n];
}

UserList::~UserList() //Delete the list of users after the program exit
{
	if (usersCount > 0) {
		delete[] users;
	}
}

void UserList::userMenu()
{
	static bool uflag = true;
	if (uflag) {
		cout << "How many users will be added" << endl;
		cin >> this->usersCount;
		uflag = false;
	}
	int umenu;
	cout << "User menu\n1- Create a user and add it to the list\n2- Search for a user\n3- Display all users\n4- Back to the main menu" << endl;
	cin >> umenu;
	switch (umenu)
	{
	case 1: { //add user to the list
		if (usersCount >= (User::ucount + 1) && capacity >= (User::ucount + 1)) {
			User s;
			cin >> s;
			this->addUser(s);
		}
		else
			cout << "Error their is no place to add another User" << endl;
		this->userMenu();
		break;
	}
	case 2: //Search for user in the list
		cout << "Search for a user\n1- Search by name\n2- Search by ID\n3- Return to User Menu" << endl;
		cin >> umenu;
		if (umenu == 1)
		{
			string name;
			cout << "Enter user name:" << endl;
			cin >> name;
			User ss;
			User::ucount--;
			ss = this->searchUser(name);
			cout << "\n1- Delete user\n2- Return to user menu" << endl;
			int choice;
			cin >> choice;
			if (choice == 1)
				this->deleteUser(ss.getId());
			else
				userMenu();
		}
		else if (umenu == 2)
		{
			int id;
			cout << "Enter user ID:" << endl;
			cin >> id;
			this->searchUser(id);
			cout << "\n1- Delete user\n2- Return to user menu" << endl;
			int choice;
			cin >> choice;
			if (choice == 1)
				this->deleteUser(id);
			else
				userMenu();
		}
		else
			this->userMenu();
		break;
	case 3: //Display all the users in the lise
		cout << "=========================\n";
		cout << *this;
		userMenu();
	default:
		break;
	}
}

ostream& operator<<(ostream& output, UserList& ul)
{
	for (int i = 0; i < ul.usersCount; i++) {
		if (ul.users[i].getAge() != 0) {
			output << "Name: " << ul.users[i].getName() << "\nAge: " << ul.users[i].getAge()
				<< "\nID: " << ul.users[i].getId() << "\nEmail: " << ul.users[i].getEmail()
				<< "\n===========================\n" << endl;
		}
		else
			break;
	}
	return output;
}
