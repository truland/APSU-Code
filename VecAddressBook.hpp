/*
Thomas Ruland
CSCI 3250 Data Structures and Algorithms
Programming Assignment 1
g++ on ubuntu
*/

#ifndef AddressBook_hpp
#define AddressBook_hpp

#include <string>
#include <vector>

struct Contact{

	std::string mFirstName;
	std::string mLastName;
	std::string mEmailAddress;
	Contact();
	Contact(std::string first,std::string last,std::string email);
	std::string getFirst();
	std::string getLast();
	std::string getEmail();
};

class AddressBook{
private:
	std::vector <Contact> mBook;
public:
	void addContact(Contact bob);
	void displayContacts();
	Contact* findContact(std::string trialfirst,std::string triallast);
};

#endif
