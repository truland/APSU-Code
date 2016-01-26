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
#include "VecAddressBook.hpp"

using namespace std;

Contact::Contact()
{
	mFirstName="John";
	mLastName="Doe";
	mEmailAddress="jdoe@my.apsu.edu";
}

Contact::Contact(string first,string last,string email)
{
	mFirstName=first;
	mLastName=last;
	mEmailAddress=email;
}

string Contact::getFirst()
{
	return mFirstName;
}

string Contact::getLast()
{
	return mLastName;
}

string Contact::getEmail()
{
	return mEmailAddress;
}

void AddressBook::addContact(Contact bob)
{
	mBook.push_back(bob);
}

void AddressBook::displayContacts()
{
	Contact temp;
	cout << "| First Name | Last Name | Email |" << endl;
	for(int i=0; i<mBook.size(); i++)
	{
		temp=mBook[i];
		cout << (temp).getFirst() << " | " << (temp).getLast() 
		     << " | " << (temp).getEmail() << endl;
	}
}

Contact* AddressBook::findContact(string trialfirst,string triallast)
{
	Contact* temp=NULL;
	for(int i=0; i<mBook.size(); i++)
	{
		if(mBook[i].getFirst()==trialfirst && mBook[i].getLast()==triallast)
		{
			cout << "Found: " << trialfirst << " " << triallast << endl;
			temp=&mBook[i];
			return temp;
		}
	}
	cout << trialfirst << " " << triallast << " was not found" << endl;
	return temp;
}
