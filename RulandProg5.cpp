/*
THOMAS RULAND
DATA STRUCTURES AND ALGORITHMS CSCI 3250
COMPILED ON UBUNTU 14.04 USING G++ -STD=C++11
PROGRAMMING ASSIGNMENT 5
*/
#include<iostream>
#include<string>
#include"Scheme.hpp"
#include"Functions.hpp"

using namespace std;

int main()
{
	Symbol *a=new Symbol("a");
	Symbol *b=new Symbol("b");
	Symbol *c=new Symbol("c");

	List *list1=nil();
	List* list2=cons(a,list1);
	List* list3=cons(b,list2);
	List* list4=cons(c,list3);

	cout << "list2: " << list2 << endl;
	cout << "list3: " << list3 << endl;
	cout << "list4: " << list4 << endl;

	int l=length(list2);
	cout << "length of list2: " << l << endl;
	l=length(list3);
	cout << "length of list3: " << l << endl;
	l=length(list4);
	cout << "length of list4: " << l << endl;

	bool val=member(c,list2);
	cout << "is 'c' in list2: " << val << endl;
	val=member(c,list3);
	cout << "is 'c' in list3: " << val << endl;
	val=member(c,list4);
	cout << "is 'c' in list4: " << val << endl;

	List* list5=append(list4,list4);
	cout << "append list4 to itself in list5: " << list5 << endl;

	List* list6=reverse(list4);
	cout << "reverse of list4: " << list6 << endl;

	return 0;
}
