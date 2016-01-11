/*
Thomas Ruland
CSCI 3250 assignment#2
compiled on ubuntu 14.04 using g++
*/
#include<iostream>
#include"MyVector.hpp"

using namespace std;

int main()
{
	MyVector <int> test;
	int add=0;

	cout << "How many items do you want to add? \n >>";
	cin >>add;
	cout << "Numbers 0 thru " << add << " will now be added" << endl;

	for(int i=0; i<add; i++)
	{
		test.PushBack(i);
	}

	cout << "Items added: " << test.getSize()
	     << "\nCapacity: " << test.getCap()
	     << "\nUnused Capacity: " << ((test.getCap())-(test.getSize()))
	     << "\nAssignments made: " << test.getAssign()
	     << "\nAssignments/Item: " << ((static_cast<double>(test.getAssign()))/(static_cast<double>(test.getSize()))) << endl;
	
	return 0;
}
