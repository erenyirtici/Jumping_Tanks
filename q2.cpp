#include<iostream>
#include <vector>
#include<string.h>


using namespace std ; 

class Book 
{
	private:
	 
	// all public variables	
	public:	
	string title, author ; 
	int public_year ; 
	static int counter_book ;
	
	// constructor
	Book() 
	{
	
		cout << "Enter book title: ";
		cin.ignore();
		getline(cin,title)  ;
		
		
		cout << "Enter author name: ";
		//cin.ignore();
		getline(cin,author)  ;
		
		
		cout << "Publication year: ";
		cin >> public_year ; 
	} 
	
};

// set to zero 
int Book :: counter_book{0} ; 


int main() 
{
	int choice , num ; 
	vector<Book> books;
	vector<Book>::iterator position ; 
	do 
		{
			cout << "Library Management System " << endl ;
			cout << "1. Add a book " << endl ; 
			cout << "2. Remove a book" << endl ; 
			cout << "3. Display all books" << endl ;
			cout << "4. Exit" << endl ;
			cout << "Enter the choice:" ;
						
			cin >> choice ; 
						
			switch (choice)
				{
					case 1 :
						{
						Book booker ; 
						books.push_back(booker);
						Book::counter_book ++ ; 	
						cout << "A new book " << "'" << booker.title << "'" << " has been added" << endl ; 
						}
					break;
							
					case 2 :
						
						{
						for ( int c1 = 0 ; c1 < books.size() ; c1 ++ )
						{
							cout << c1 + 1 << "." << "Title: " <<	books[c1].title << ", " << "Author: " <<  books[c1].author << ", " << "Publication Year: " << books[c1].public_year << endl ; 
						}
						
						
					 	cout << "Please enter which book you want to remove ( 1 , 2 , 3 )" << endl ;
					 	cin >> num ; 
					 	position = books.begin() + num - 1 ;  
					 	books.erase(position);
						Book::counter_book -- ; 
						}
					break; 
							
					case 3 :
						{
						for ( int c1 = 0 ; c1 < books.size() ; c1 ++ )
						{
							cout << c1 + 1 << "." << "Title: " <<	books[c1].title << ", " << "Author: " <<  books[c1].author << ", " << "Publication Year: " << books[c1].public_year << endl ; 
						}
						}
					break;
				}
				
				}while(choice != 4  ) ;
				
	cout << "May God give you clarity of mind...";
	
	
	return 0 ; 
}