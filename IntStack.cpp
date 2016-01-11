/*
THOMAS RULAND
DATA STRUCTURES AND ALGORITHMS CSCI 3250
PROGRAMMING ASSIGNMENT 4
COMPILED USING g++ ON UBUNTU 14.04
*/
#include<iostream>
#include "IntStack.hpp"

using namespace std;

//default constructor that sets the capacity to 30 using dynamic array
IntStack::IntStack()
{
	mCap=30;
	mTop=0;
	mArr=new int[mCap];
}

//one arguement constructor that sets the capacity of the dynamic array to mycap
IntStack::IntStack(int mycap)
{
	mCap=mycap;
	mTop=0;
	mArr=new int[mCap];
}

//copy constructor it copies things
IntStack::IntStack(const IntStack& copy)
{
	this->mCap=copy.mCap;
	this->mTop=copy.mTop;
	this->mArr=new int[mCap];

	//here is said copying taking place
	for(int i=0; i<this->mTop; i++)
	{
		this->mArr[i]=copy.mArr[i];
	}
}

//destructor because of dynamic array
IntStack::~IntStack()
{
	delete [] mArr;
}

//is empty returns whether or not the stack is empty
bool IntStack::isEmpty()
{
	if(mTop==0)
	{
		return true;
	}else{
		return false;
	}
}

//tells me whether or not the stack is full
bool IntStack::isFull()
{
	if(mTop==mCap)
	{
		return true;
	}else{
		return false;
	}
}

// "clears" the stack by setting the top to [0]
void IntStack::clear()
{
	mTop=0;
}

//removing the top value of the stack if not empty by first decrementing top then accessing the value
bool IntStack::pop(int &val)
{
	if(mTop==0)
	{
		return false;
	}else{
		mTop--;
		val=mArr[mTop];
		return true;
	}
}

//adding to the top of the stack if not full by putting into the [mTop] then incrementing top
bool IntStack::push(int& val)
{
	if(mTop < mCap)
	{
		mArr[mTop]=val;
		mTop++;
		return true;
	}else{
		return false;
	}
}

//accesses the top of the stack if not empty 
bool IntStack::top(int &val)
{
	if(mTop==0)
	{
		return false;
	}else{
		int temp=mTop-1;
		val=mArr[temp];
		return true;
	}
}

//displays the stack no matter what because if empty it wont ouput anything
void IntStack::display()
{
	for(int i=0; i<mTop; i++)
	{
		cout << mArr[i] << endl;
	}
}

//overloading the = operator because it seemed like the best thing to overload
IntStack IntStack::operator=(const IntStack& rhs)
{
	delete [] mArr;
	mCap=rhs.mCap;
	mArr=new int[mCap];
	mTop=rhs.mTop;

	for(int i=0; i<mTop; i++)
	{
		mArr[i]=rhs.mArr[i];
	}

	return rhs;
}
