#include "User.h"

int User::ucount = 0;

//counter for id
User::User() : name(""), age(0)
{
	ucount++;
	id = ucount;
}

//constructor to set name, age, email, password

User::User(string name, int age, string email, string password) : name(name), age(age), email(email), password(password)
{
	ucount++;
	id = ucount;
}

//copying constructor in a new object

User::User(const User& user)
{
	name = user.name;
	age = user.age;
	id = user.id;
	password = user.password;
	email = user.email;
}

//settingg name

void User::setName(string n)
{
	name = n;
}

//returning name to main

string User::getName() const
{
	return name;
}

//setting password

void User::setPassword(string pass)
{
	password = pass;
}

//returning password to main

string User::getPassword()
{
	return password;
}

//setting email

void User::setEmail(string em)
{
	email = em;
}

//returning email to main

string User::getEmail()
{
	return email;
}

//setting age

void User::setAge(int a)
{
	age = a;
}

//returning age to main

int User::getAge()
{
	return age;
}

//setting id

void User::setId(int i)
{
	id = i;
}

//returning id to main

int User::getId()
{
	return id;
}



bool User::operator==(const User& user)
{
	bool k = false;
	if (name == user.name && age == user.age && id == user.id && email == user.email && password == user.password)
		k = true;
	return k;
}

//destructor

User::~User()
{
}

//output system format

ostream& operator<<(ostream& output, const User& user)
{
	output << "========user " << user.id << " info======\n" << "Name: " << user.name << ", age: " << user.age
		<< ", ID: " << user.id << ", email: " << user.email << "\n=======================\n";
	return output;
}

//input system format

istream& operator >>(istream& input, User& user)
{
	cout << "Lets add User\n" << "Enter the user information in this order\nName Age Email Password (space separated)" << endl;
	input >> user.name >> user.age >> user.email >> user.password;
	return input;
}
