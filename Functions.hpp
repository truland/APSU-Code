/* CSCI 3250
 * Programming Assignment 5
 * The file Functions.hpp contains prototypes for several functions used to manipulate lists
 */

#include "Scheme.hpp"

#ifndef __FUNCTIONS_H__
#define __FUNCTIONS__

// The length function returns the number of Symbols contained in list.
int length( List *list );

// The member function returns true of item appears in list and false otherwise.
bool member( Symbol *item, List *list );

// The append function returns a list consisting of the Symbols in list1 followed by the
// symbols in list2.
List *append( List *list1, List *list2 );

// The reverse function returns a list consisting of the Symbols in list in reverse order.
List *reverse( List *list );

#endif
