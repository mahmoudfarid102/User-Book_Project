#include "BookList.h"

BookList::BookList(const BookList& anotherList)		//Copy Constructor
{
	capacity = anotherList.capacity;
	User s;
	User::ucount--;
	Book::count -= capacity;
	books = new Book[capacity];
	for (int i = 0; i < capacity; i++) {
		books[i] = anotherList.books[i];
	}
}

BookList::BookList(int c) : capacity(c)				//Constructor
{
	User s;
	User::ucount -= c + 1;
	Book::count -= capacity;
	books = new Book[c];
	for (int i = 0; i < c; i++) {
		books[i].setTitle("");
		books[i].setISBN("");
		books[i].setCategory("");
		books[i].setAuthor(s);
		books[i].setId(0);
		books[i].rateBook(0);
	}
}

//Search for a book by name

Book& BookList::searchBook(string name)
{
	for (int i = 0; i < capacity; i++) {
		if (books[i].getTitle() == name)
			return books[i];
	}
	cout << "Error book not found" << endl;
}

//Search for a book by id

Book& BookList::searchBook(int id)
{
	for (int i = 0; i < booksCount; i++) {
		if (books[i].getId() == id)
			return books[i];
	}
	cout << "Error book not found" << endl;
}

//Delete a book by id

void BookList::deleteBook(int id)
{
	for (int i = 0; i < capacity; i++) {
		if (books[i].getId() == id) {
			for (i; i < capacity - 1; i++) {
				books[i] = books[i + 1];
			}
		}
	}
}

//Find the book with highest Rate of the array

Book BookList::getTheHighestRatedBook()
{
	double max = 0;
	int k = 0;
	for (int i = 0; i < capacity; i++)
	{
		if (books[i].getAverageRating() >= max) {
			max = books[i].getAverageRating();
			k = i;
		}
	}
	cout << books[k];
	return books[k];
}

//Printing all books of a user

Book* BookList::getBooksForUser(User user)
{
	BookList list(capacity);
	int k = 0;
	for (int i = 0; i < booksCount; i++) {
		if (books[i].getAuthor() == user) {
			list.books[k] = books[i];
			cout << list.books[i];
			k++;
		}
	}
	return list.books;
}

//operator [] overloading

Book& BookList::operator[](int position)
{
	if (position < 0 || position > capacity) {
		cout << "Error" << endl;
		exit(0);
	}
	else
		return books[position];
}

//Books Menu

void BookList::bookMenu(UserList& ul)
{
	static bool Bflag = true;
	if (Bflag) {
		cout << "How many books will be added" << endl;		//number of books
		cin >> this->booksCount;
		Bflag = false;
	}
	cout << "Books menu\n1- Create a book and add it to the list\n2- Search for a book\n3- Display all books\n"
		<< "4- Get the highest rating book" << "\n5- Get all books os user"
		<< "\n6- Copy the current book list to a new book list and switch to it" << "\n7- Back to the main menu" << endl;
	int bmenu;
	cin >> bmenu;
	switch (bmenu)
	{
	case 1: {
		Book b;
		cin >> b;
		this->addbook(b);									//Adding a book to the array
		cout << "\n1- Assigen author\n2- continue" << endl;
		int n;
		cin >> n;
		if (n == 1) {  //Setting author with ID
			int id;
			cout << "Enter the author ID:" << endl;
			cin >> id;
			books[Booknum].setAuthor(ul.searchUser(id));
			this->bookMenu(ul);
		}
		this->bookMenu(ul);
		break;
	}
	case 2:
		cout << "Search for a book\n1- Search by name\n2- Search by ID\n3- Return to Book Menu" << endl;
		cin >> bmenu;
		if (bmenu == 1) {
			string title;
			cout << "Enter the book title:" << endl;  //Search for a book by it's title
			cin >> title;
			Book bb;
			Book::count--;
			bb = this->searchBook(title);
			cout << "\n1- update author\n2- update name\n3- update categoty\n4- Delete book\n5- Rate book\n6- Get back to book menu" << endl;
			int choice;
			cin >> choice;
			if (choice == 1)
			{
				int id;
				cout << "Enter the new auther ID:" << endl;  //Author update
				cin >> id;
				this->books[bb.getId() - 1].setAuthor(ul.searchUser(id));
				cout << this->books[bb.getId() - 1];
				bookMenu(ul);
			}
			else if (choice == 2) {							//Book name update
				string s;
				cout << "Enter new book name" << endl;
				cin >> s;
				this->books[bb.getId() - 1].setTitle(s);
				cout << this->books[bb.getId() - 1];
				bookMenu(ul);
			}
			else if (choice == 3) {							//Book category update
				string s;
				cout << "Enter new book category" << endl;
				cin >> s;
				this->books[bb.getId() - 1].setCategory(s);
				cout << this->books[bb.getId() - 1];
				bookMenu(ul);
			}
			else if (choice == 4) {							//Delete a book
				this->deleteBook(bb.getId());
				bookMenu(ul);
			}
			else if (choice == 5) {							//Rating a book
				cout << "Enter your rate for book" << endl;
				int r;
				cin >> r;
				books[bb.getId() - 1].rateBook(r);
				cout << books[bb.getId() - 1];
				bookMenu(ul);
			}
			else
				bookMenu(ul);
		}
		else if (bmenu == 2)
		{
			int id;
			cout << "Enter book ID:" << endl;		//Search for a book by it's ID
			cin >> id;
			this->searchBook(id);
			cout << "\n1- update author\n2- update name\n3- update categoty\n4- Delete book\n5- Rate book\n6- Get back to book menu" << endl;
			int choice;
			cin >> choice;
			if (choice == 2) {
				string s;
				cout << "Enter new book name" << endl;
				cin >> s;
				this->books[id - 1].setTitle(s);
				cout << this->books[id - 1];
				bookMenu(ul);
			}
			else if (choice == 1) {
				cout << "Enter the new author ID:" << endl;
				int id;
				cin >> id;
				this->books[id - 1].setAuthor(ul.searchUser(id));
				cout << this->books[id - 1];
				bookMenu(ul);
			}
			else if (choice == 3) {
				string s;
				cout << "Enter new book category" << endl;
				cin >> s;
				this->books[id - 1].setCategory(s);
				cout << this->books[id - 1];
				bookMenu(ul);
			}
			else if (choice == 4) {
				this->deleteBook(id);
				bookMenu(ul);
			}
			else if (choice == 5) {
				cout << "Enter your rate for the book" << endl;
				int r;
				cin >> r;
				books[id - 1].rateBook(r);
				cout << books[id - 1];
				bookMenu(ul);
			}
			else
				bookMenu(ul);
		}
		else
			this->bookMenu(ul);
		break;
	case 3:
		cout << *this;
		bookMenu(ul);
		break;
	case 4:
		cout << this->getTheHighestRatedBook();
		bookMenu(ul);
		break;
	case 5:
		cout << "Enter the user ID" << endl;		//Print all books of one user
		int id;
		cin >> id;
		getBooksForUser(ul.searchUser(id));
		this->bookMenu(ul);
		break;
	case 6:
	{
		cout << "Copied the current list to a new list and switched to it" << endl;		//copy current list to a new one and switch to it
		BookList b1(*this);
		b1.bookMenu(ul);
		break;
	}
	default:
		break;
	}
}


void BookList::addbook(Book b)				//Add a book to array
{
	for (int i = 0; i < booksCount; i++) {
		if (books[i].getTitle() == "") {
			books[i] = b;
			Booknum = i;
			break;
		}
	}
}

ostream& operator<<(ostream& output, BookList& booklist)		//Operator << overloading
{
	for (int i = 0; i < booklist.capacity; i++) {
		if (booklist.books[i].getId() != 0) {
			output << "===========Book " << booklist.books[i].getId() << " ================" << "\nTitle: "
				<< booklist.books[i].getTitle() << "\nISBN: " << booklist.books[i].getISBN()
				<< "\nID: " << booklist.books[i].getId() << "\nCategory: " << booklist.books[i].getCategory()
				<< "\nRate: " << booklist.books[i].getAverageRating() << "\nAuthor: " << booklist.books[i].getAuthor().getName() << endl;
			if (booklist.books[i].getAuthor().getAge() != 0)
			{
				cout << booklist.books[i].getAuthor() << endl;
			}
		}
		else
			break;
	}
	return output;
}


BookList::~BookList()			//Destructor
{
	if (booksCount > 0)
		delete[] books;
}