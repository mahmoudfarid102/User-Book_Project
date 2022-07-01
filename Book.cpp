#include "Book.h"

int Book::count = 0;

//counter for id

Book::Book() : averageRating(0.0)
{
	count++;
	id = count;
	Brate = 0;
}

//constructor to set title, isbn, category, averagerating

Book::Book(string title, string isbn, string category) : title(title), isbn(isbn), category(category), averageRating(0.0)
{
	count++;
	id = count;
	Brate = 0;
}

//copying constructor in a new object

Book::Book(const Book& book)
{
	title = book.title;
	isbn = book.isbn;
	id = book.id;
	category = book.category;
	averageRating = book.averageRating;
	author = book.author;
}

//setting title

void Book::setTitle(string t)
{
	title = t;
}

//returning title to main

string Book::getTitle()
{
	return title;
}

//setting isbn

void Book::setISBN(string is)
{
	isbn = is;
}

//returning isbn to main

string Book::getISBN()
{
	return isbn;
}

//setting id

void Book::setId(int i)
{
	id = i;
}

//returning id to main

int Book::getId()
{
	return id;
}

//setting category

void Book::setCategory(string c)
{
	category = c;
}

//returning category to main

string Book::getCategory()
{
	return category;
}

//setting author

void Book::setAuthor(User user)
{
	author = user;
}

//returning author to main

User Book::getAuthor()
{
	return author;
}

//calculating book rate

void Book::rateBook(double rating)
{
	rate = rating;
	Brate++;
	averageRating = ((averageRating * (Brate - 1)) + rate) / Brate;
}

//returning averagerating to main

double Book::getAverageRating()
{
	return averageRating;
}

//overloading for operator == 

bool Book::operator==(const Book& book)
{
	bool k = false;
	if (title == book.title && isbn == book.isbn && id == book.id && category == book.category && author == book.author)
		k = true;
	return k;
}

//destructor

Book::~Book()
{
}

//output system format

ostream& operator<<(ostream& output, const Book& book)
{
	output << "==========Book " << book.id << " info=========\n" << "Title: " << book.title << "\nISBN: "
		<< book.isbn << "\nID: " << book.id << "\nCategory: " << book.category << "\nAvg rating = "
		<< book.averageRating << endl;
	if (book.author.getName() != "")
	{
		cout << "\nAuthor: " << book.author.getName() << "\n========================\n";
	}
	return output;
}

//output system format

istream& operator>>(istream& input, Book& book)
{
	cout << "Lets create a book\nEnter the book information in this order\nTitle ISBN Category(space separated)" << endl;
	input >> book.title >> book.isbn >> book.category;
	return input;
}
