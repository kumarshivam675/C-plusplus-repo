#include <sys/stat.h>
#include<iostream>
#include<fstream>

using namespace std;

bool fileExists(const std::string& filename)
{
    struct stat buf;
    if (stat(filename.c_str(), &buf) != -1)
    {
	return true;
    }
    return false;
}

struct Book{
	int isbn;
	char name[25];
	char author[25];
public:
	void showBook() const{
		cout << isbn << ":" << name << ":" << author << endl;
	}
};

class BookManager{
private:
	fstream book_str;
public:
	BookManager( string book_file_name );
	void storeBook(const Book& book);
	bool getBook( int isbn, Book& book );
};

BookManager::BookManager( string book_file_name )
{
	if( fileExists(book_file_name) )
		book_str.open(book_file_name, ios::in | ios::out | ios::binary);
	else{
		// Just create the file using output mode if it does not exist
		book_str.open(book_file_name, ios::out | ios::binary);
		// Close and reopen file in input / ooutput mode
		book_str.close();
		book_str.open(book_file_name, ios::in | ios::out | ios::binary);
	}		
		
	if( !book_str.good() )
		cout << "Stream not good " << endl;
}

void BookManager::storeBook( const Book& book )
{
	book_str.seekp(0,ios::end);
	book_str.write ((char*) &book, sizeof (Book));
}

bool BookManager::getBook( int isbn, Book& book )
{
	book_str.seekg(0,ios::beg);
	bool found = false;
	while(!found){
		if(book_str.read ((char*) &book, sizeof (Book))){
			if( book.isbn == isbn )
				found = true;
		}
		//else
			//break;
	}
	return found;
}

main()
{
	BookManager book_mgr ("iodemo.bin");

	Book b1 = {111, "Book111", "Auth111"};
	Book b2 = {222, "Book222", "Auth222"};
	Book b3 = {333, "Book333", "Auth333"};

	book_mgr.storeBook(b1);
	book_mgr.storeBook(b2);
	book_mgr.storeBook(b3);

	bool result = false;
	Book newBook;

	int isbn = 111;
	result = book_mgr.getBook(isbn, newBook);
	if( result )
		newBook.showBook();
	else
		cout << "Book with ISBN " << isbn << " not found" << endl;
}
