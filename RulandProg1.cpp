/*
Thomas Ruland
CSCI 3250 Data Structures and Algorithms
Programming Assignment 1
g++ on ubuntu
*/
#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include "AddressBook.hpp"

using namespace std;

void AddToBook(AddressBook& tempbook);
void Search(AddressBook tempbook);

int main()
{
	int menu_choice=0;
	AddressBook personal;
	
	while(menu_choice!=4)
	{
		cout << "What would you like to do?" << endl;
		cout << "1) Add a contact" << endl;
		cout << "2) Search for a contact" << endl;
		cout << "3) Display all contacts" << endl;
		cout << "4) Exit program" << endl;
		cout << "Please enter your choice: ";
		cin >> menu_choice;
		if(menu_choice<1 || menu_choice>4)
		{
			cout << "Error Invalid Input" << endl;
			menu_choice=0;
		}
		if(menu_choice==1)
		{
			AddToBook(personal);
		}
		if(menu_choice==2)
		{
			Search(personal);
		}
		if(menu_choice==3)
		{
			personal.displayContacts();
		}
	}

	return 0;
}

void AddToBook(AddressBook& tempbook)
{
	string firsttemp;
	string lasttemp;
	string emailtemp;

	cout << endl;
	cout << "Please enter contact's first name: ";
	cin >> firsttemp;
	cout << endl;
	cout << "Please enter contact's last name: ";
	cin >> lasttemp;
	cout << endl;
	cout << "Please enter contact's email address: ";
	cin >> emailtemp;
	cout << endl;

	Contact tempcontact(firsttemp,lasttemp,emailtemp);
	tempbook.addContact(tempcontact);

	cout << "Contact added" << endl;
}

void Search(AddressBook tempbook)
{
	string tempfirst;
	string templast;
	Contact* tempcontact;
	cout << "Please enter the first name: ";
	cin >> tempfirst;
	cout << endl;
	cout << "Please enter the last name: ";
	cin >> templast;
	cout << endl;
	tempbook.findContact(tempfirst,templast);
	tempcontact=NULL;
}
