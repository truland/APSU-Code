/*
THOMAS RULAND
DATA STRUCTURES AND ALGORITHMS CSCI 3250
PROGRAMMING ASSIGNMENT 4
*/
#ifndef INTSTACK
#define	INTSTACK

#include<iostream>

class IntStack{
private:
	int mCap;	//capacity of the array
	int mTop;	//next available index of the array
	int* mArr;	//dynamic array for the stack
public:
	IntStack();	//default constructor
	IntStack(int mycap);	//single arguement constructor
	IntStack(const IntStack& copy);	//copy constructor
	~IntStack();	//destructor
	bool isEmpty();	//empty
	bool isFull();	//full
	void clear();	//clear
	bool pop(int &val);	//removing from top
	bool push(int& val);	//adding to top
	bool top(int &val);	//accessing top
	void display();	//displaying
	IntStack operator=(const IntStack& rhs);	//= sign overload
};

#endif
