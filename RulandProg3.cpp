/*
Thomas Ruland
CSCI 3250 Data Structures and Algorithms
Programming Assignment 1
g++ on ubuntu
*/
#include<iostream>
#include<vector>
#include<string>
#include "AddressBook.hpp"

using namespace std;


int main()
{
	AddressBook personal;		//addressbook for storing thingies
	string tempF;			//temp string for storing other thingies
	string tempL;			//guess what this also stores thingies
	string tempE;			//you guessed correctly this does store thingies
	int menu_choice=0;		//this is a menu choice selector i dont know why you need a comment to know that just look at its name

	while(menu_choice!=4)		//menu loop
	{
		cout << "What would you like to do?" << endl;
		cout << "1) Add a contact" << endl;
		cout << "2) Search for a contact" << endl;
		cout << "3) Display all contacts" << endl;
		cout << "4) Exit program" << endl;
		cout << "Please enter your choice: ";
		cin >> menu_choice;
		if(menu_choice<1 || menu_choice>4)	//throwing away bad input because people are stupid sometimes or have fat fingers
		{
			cout << "Error Invalid Input" << endl;
			menu_choice=0;
		}
		if(menu_choice==1)			//choice number one why dont you just look at the menu list
		{
			cout << "Enter first name: ";	//people have first names id like to know what this guys is 
			cin >> tempF;
			cout << endl;
			cout << "Enter last name: ";	//most everyone has a last name also i kinda need to know this 
			cin >> tempL;
			cout << endl;
			cout << "Enter email address: ";//not everyone has an email address but ill ask for it anyway
			cin >> tempE;
			cout << endl;
		
			Contact input(tempF,tempL,tempE);//creating a contact to use in the addcontact function
			
			personal.addContact(input);	//adding the previously made contact into the LL
			
			cout << tempF << " " << tempL << " @  " << tempE << " has been added." << endl;
		}
		if(menu_choice==2)			//this is choice #2, seriously did you not read the above menu
		{
			cout << "Enter first name: ";	//asking for the first name of the person im searching for
			cin >> tempF;
			cout << endl;
			cout << "Enter last name: ";	//i kinda need to know their last name also because people can have matching first names but
			cin >> tempL;			//different last names hopefully
			cout << endl;

			personal.hasContact(tempF,tempL);	//searching for the person

		}
		if(menu_choice==3)			//im not even going to tell you what this one does you should have read the menu by now
		{
			personal.displayContacts();	//displaying the contacts in the LL
		}
	}

	AddressBook newbook(personal);			//demonstating that the copy constructor works and doesnt crash everything
/*
	newbook.displayContacts();
	personal.displayContacts();

	Contact tempC("bob","ross"," ");

	Contact tempR("b","rs"," ");

	newbook.addContact(tempC);
	newbook.displayContacts();
	personal.displayContacts();

	personal.addContact(tempR);
	newbook.displayContacts();
	personal.displayContacts();
*/
	return 0;
}
