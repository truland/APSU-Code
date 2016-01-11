/*
THOMAS RULAND
CSCI 3250 PROGRAMMING ASSIGNMENT 7
COMPILED ON UBUNTU 14.04 USING g++
*/
#include<iostream>
#include"PriorityQueue.hpp"

using namespace std;

int main()
{
	PriorityQueue <int> mine(10);
	//DEMONSTRATING THE PUSH AND DISPLAY FUNCTIONS
	cout << "ADDING 10------------------------------------------------" << endl;
	mine.push(10);
	mine.display();
	cout << "ADDING 5,7,1,3,6------------------------------------------------" << endl;
	mine.push(5);
	mine.push(7);
	mine.push(1);
	mine.push(3);
	mine.push(6);
	mine.display();

	cout << "AFTER ADDING 12------------------------------------------------" << endl;
	mine.push(12);
	mine.display();
	//DEMONSTRATING THE POP FUNCTIONS
	cout << "AFTER POP 12------------------------------------------------" << endl;
	mine.pop();
	mine.display();
	cout << "AFTER POP 10------------------------------------------------" << endl;
	mine.pop();
	mine.display();
	cout << "AFTER POP-----------------------------------------------" << endl;
	mine.pop();
	mine.display();

	//DEMONSTRATING FULL AND EMPTY
	cout << "Is the current heap full " << mine.isFull() << endl;
	cout << "Is the current heap empty " << mine.isEmpty() << endl;
	//DEMONSTRATING COPY CONS
	PriorityQueue <int> copytest(mine);
	cout << "DEMONSTATING COPY CONSTRUCTOR------------------------------------------------" << endl;
	copytest.display();
	//DEMONSTRATING THREE ARG CONS AND EMPTY AND FULL
	int arr[11]={1,11,2,3,4,5,6,7,8,9,10};
	PriorityQueue <int> ThreeArgConsTest(arr,11,11);
	cout << "DEMONSTRATING THREE ARGUEMENT CONSTRUCTOR------------------------------------------------" << endl;
	ThreeArgConsTest.display();
	cout << "Is the three arg heap full " << ThreeArgConsTest.isFull() << endl;
	cout << "Is the three arg heap empty " << ThreeArgConsTest.isEmpty() << endl;
	//DEMONSTRATING OVERLOAD
	PriorityQueue <int> overloadTest=mine;
	cout << "DEMONSTATING THE OVERLOADED ASSIGNMENT OPERATOR-----------------------------------------" << endl;
	overloadTest.display();
	//RETURN EVEN THOUGH IT'S NOT REQUIRED
	return 0;
}
