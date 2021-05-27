#pragma once
#include <iostream>
#include <cstring>
#include "User.h"
using namespace std;
class Book
{
private:
	string title;
	string isbn;
	int id;
	string category;
	double averageRating = 0;
	double rate;
	User author;
	int Brate;
public:
	static int count;												//Static counter for the id
	Book();															//Default constructor
	Book(string title, string isbn, string category);				//constructor that takes title, isbn, category of a book as parameter
	Book(const Book& book);											//copy constructor that takes a book and copy it in a new one
	void setTitle(string t);										/*sit t to the title of a book
																	*Take (t)*/
	string getTitle();												//Return the title of the book
	void setISBN(string is);										/*sit is to the isbn of a book
																	*take parameter (is)*/
	string getISBN();												//Return the ISBN of a book
	void setId(int i);											 	/*sit i as ID of a book
																	*take parameter (i)*/
	int getId();										   			//Return the ID of a book
	void setCategory(string c);									  	/*sit c to category of a book
																	*Take parameter (c)*/
	string getCategory();										  	//Return the category of a book
	void setAuthor(User user);									 	/*sit user to the author of a book
																	*Take parameter (User)*/
	User getAuthor();												//Return Author of a book
	void rateBook(double rating);								    /*Rate a book
																	*Take parameter (rating)*/
	double getAverageRating();									    //Return average rate of a book

	bool operator==(const Book& book);							    /*Operator overloading for ==
																	*Take parameter (book)
																	* return bool*/
	friend ostream& operator<<(ostream& output, const Book& book);  /*Operator overloading for <<
																	*Take parameter (book)
																	*return output of book type on the screen*/
	friend istream& operator>>(istream& input, Book& book);			/*operator overloading for >>
																	*Take parameter (book)
																	*Return output of book type on the screen*/
	~Book();														//Destructor
};

