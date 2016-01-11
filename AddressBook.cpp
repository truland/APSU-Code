/*
Thomas Ruland 
CSCI 3250 Data Structures and Algorithms
Programming Assignment 1
g++ on ubuntu
*/
#include<iostream>
#include<string>
#include "AddressBook.hpp"

using namespace std;

//default constructor
Contact::Contact()
{
	mFirst="John";	//generic name
	mLast="Doe";	//also generic name
	mEmail="jdoe@my.apsu.edu";	//generic email
}

//fancier constructor
Contact::Contact(string first,string last,string email)
{
	mFirst=first;	//your name
	mLast=last;	//also your name
	mEmail=email;	//email that you use
}

Contact Contact::operator=(const Contact &rhs)
{
	mFirst=rhs.mFirst;
	mLast=rhs.mLast;
	mEmail=rhs.mEmail;
	next=rhs.next;

	return rhs;
}

//default constructor
AddressBook::AddressBook()
{
	head=NULL;	//head has to by null
}

//destructor
AddressBook::~AddressBook()
{
	Contact *temp=head;	//temp pointer for indirection
	while((temp->next)!=NULL)	//while loop if you couldnt tell by the key word while
	{
		temp=head->next;
		delete head;	//deleting head after we keep track of its next then setting heads to its old next
		head=temp;
	}
	head=NULL;
}

//copy constructor
AddressBook::AddressBook(const AddressBook& old)
{
	head=old.head;		//im not going to make the joke
}

void AddressBook::addContact(Contact bob)
{
	Contact *newcontact=new Contact;	//allocating new contact
	newcontact->mFirst=bob.mFirst;		//setting first name
	newcontact->mLast=bob.mLast;		//setting last name
	newcontact->mEmail=bob.mEmail;		//setting email
	newcontact->next=head;			//putting the newly allocated contact into the LL
	head=newcontact;
}

void AddressBook::displayContacts()
{
	Contact *temp=head;			//almost the same thing as the destructor except it doesnt delete things
	while(temp != NULL)
	{
		cout << temp->mFirst 
		     << " " << temp->mLast 
		     << " @ " << temp->mEmail
		     << endl;
		temp=temp->next;
	}
}

void AddressBook::hasContact(string f,string l)
{
	Contact *temp=head;		//temp
	bool found=false;
	while(temp!=NULL)		//while loop
	{
		if(temp->mFirst == f)
		{
			if(temp->mLast == l)
			{
				cout << temp->mFirst
				     << "    "
				     << temp->mLast
				     << " exists" << endl;
				     found=true;		//if object found it doesnt display the error message below
			}
		}
		temp=temp->next;
	}
	if(!found)						//this is the error message talked about above
	{
		cout << f << "   " << l 
	       	     << " is not in your contacts" << endl;
	}
}

//operator overload
AddressBook AddressBook::operator=(const AddressBook& rhs)
{
	head=NULL;
	Contact *temp=rhs.head;
	while(temp!=NULL)			//while looping
	{
	Contact replacement((temp->mFirst),(temp->mLast),(temp->mEmail));
		addContact(replacement);		//adding the newly copied contact to the newly created LL
		temp=temp->next;		
	}
	return rhs;				//returning thingies is good
}
