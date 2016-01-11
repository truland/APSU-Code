/*
Thomas Ruland
CSCI 3250 Data Structures and Algorithms
Programming Assignment 1
g++ on ubuntu
*/

#ifndef AddressBook_hpp
#define AddressBook_hpp

#include <string>

//contact structure like we need 
struct Contact{

	std::string mFirst;	//first name
	std::string mLast;	//last name
	std::string mEmail;	//email address
	Contact *next;		//next item in the LL

	Contact();		//constructor
	Contact(std::string f,std::string l,std::string e);//constructor also
	Contact operator=(const Contact& rhs);	//= sign overload
};

class AddressBook{
private:
	Contact *head;		//head of the list
public:
	AddressBook();		//default constructor
	~AddressBook();		//destructor
	AddressBook(const AddressBook& old);	//copy constructor
	void addContact(Contact bob);		//add contact
	void displayContacts();			//display contact
	void hasContact(std::string f,std::string l);//seriously?
	AddressBook operator=(const AddressBook& rhs);	//= sign overload
};

#endif
