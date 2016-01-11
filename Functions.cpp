/* CSCI 3250
 * Programming Assignment 5
 * The file Functions.hpp contains prototypes for several functions used to manipulate lists
 THOMAS RULAND
 */

#include "Scheme.hpp"
#include "Functions.hpp"

// The length function returns the number of Symbols contained in list.
int length( List *list )
{
	if(null(list))
	{
		return 0;	//base case null list
	}else{
		return 1 + length(cdr(list));	//recursion YEAH!!!
	}
}

// The member function returns true of item appears in list and false otherwise.
bool member( Symbol *item, List *list )
{
	if(null(list))
	{
		return false;	//baseish case
	}
	if(eqv(item,car(list)))
	{
		return true;	//baseish case also
	}else{
		member(item,cdr(list)); //recursion YEAH!!!
	}
}

// The append function returns a list consisting of the Symbols in list1 followed by the
// symbols in list2.
List *append( List *list1, List *list2 )
{
	if(null(list1))
	{
		return list2;		//base case
	}else{
		cons(car(list1),append(cdr(list1),list2));	//appendingt the lists
	}
}

// The reverse function returns a list consisting of the Symbols in list in reverse order.
List *reverse( List *list )
{
	List* temp=nil();
	if(null(list))
	{
		return temp;	//base case
	}else{
		append(reverse(cdr(list)),cons(car(list),temp));	//appending the reverse of the list to the head of the list
	}
}
