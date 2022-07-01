#pragma once
#include "Book.h"
#include "UserList.h"
class BookList
{
private:
	Book* books;
	int capacity;
	int booksCount;
	int Booknum;
public:
	BookList(const BookList& anotherList);							 //copy constructor take parameter (anotherList) to copy it
	BookList(int capacity);										 	 //constructor take the capacity of the books array
	Book& searchBook(string name);								 	 /*Search for a book using it's title
																	 *Take parameter (name)
																	 *Return a Book type*/
	Book& searchBook(int id);									 	 /*Search for a book using it's id
																	 *Take parameter (id)
																	 *Return a Book type*/
	void deleteBook(int id);									 	 /*Delete a book from the array
																	 *Take parameter (id) */
	Book getTheHighestRatedBook();								 	 /*Gets the highest rated book in the array
																	 *Return a book type*/
	Book* getBooksForUser(User user);							 	 // get all books of this author
	Book& operator[] (int position);							 	 /*Operator overloading []
																	 *Take parameter (position)
																	 *Return a Book type*/
	friend ostream& operator<<(ostream& output, BookList& booklist); //to display all books
	void bookMenu(UserList& ul);									 /*Shows the Book menu on screen
																	 *Take parameter (ul)*/
	void addbook(Book b);											 /*add a book to the array of books
																	 *Take parameter (b)*/
	~BookList();													 //Destructor
};

