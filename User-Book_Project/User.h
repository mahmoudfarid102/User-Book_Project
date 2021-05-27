#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class User
{
private:
	string name;
	int age;
	int id;
	string password;
	string email;
public:
	static int ucount;						//Static variable to count the number of users and assigne the ID
	User();									//default constructor
	User(string name, int age, string email, string password); /*Constructor
																*parametars  name, age, e-mail & password of the user*/
	User(const User& user);					//Copy constructor to copy the user data to another user
	void setName(string n);					/*Take parameter (n)
											*sit it as name for the user*/
	string getName() const;					//Return the name of the user 
	void setPassword(string pass);			/*Take parameter (pass)
											*sit it as password for the user*/
	string getPassword();					//Return the password of the user
	void setEmail(string em);				/*Take parameter (em)
											*sit it as e-mail for the user*/
	string getEmail();						//Return the e-mail of the user
	void setAge(int a);						/*Take parameter (a)
											*sit it as age of user*/
	int getAge();							//Return the age of the user
	void setId(int i);						/*Take parameter (i)
											*sit it as a new ID for the user*/
	int getId();							//Return the ID of the user
	bool operator==(const User& user);		/*Check if two users are equal
											*return boolean value*/
	friend ostream& operator<<(ostream& output, const User& user); //print the user data
	friend istream& operator>>(istream& input, User& user);		   //receive the users data 
	~User();								//Destructor
};
