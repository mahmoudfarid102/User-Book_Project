#pragma once
#include "User.h"
class UserList
{
private:
	User* users;
	int capacity;
	int usersCount;
public:
	UserList(int c);				//Constructor with parameter (c) as the capacity of the list of users
	void addUser(User user);		/*Take parameter (user) of type User
									 *add it to the list*/
	User& searchUser(string name);	/*Search for a user in the list with the name
									 *Take patameter (name),
									 *return user*/
	User& searchUser(int id);		/*Search for a user in the list with the ID
									 *Take patameter (id)
									 *return user*/
	void deleteUser(int id);		/*Delete a specific user from the list with the ID
									 *Take patameter (id)*/
	User& operator[](int n);		/*Modify the list of users by setting or getting elements from it
									 *Take parameter (n) as the index of the user in the list
									 *Return user with index (n)*/
	friend ostream& operator<<(ostream& output, UserList& userList); //print the data of the list
	void userMenu();				//Display the User Menu with choices to modify the list
	~UserList();					//Destructor
};
