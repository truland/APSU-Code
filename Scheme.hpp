/* CSCI 3250
 * Programming Assignment 5
 * The file Scheme.hpp contains declarations of the Symbol, ConsCell and List 
 * structures as well as prototypes for several functions for building and
 * manipulating lists.
 */

#include <iostream>
#include <string>

#ifndef __SCHEME_H__
#define __SCHEME_H__

// The Symbol structure represents a symbol in Scheme
struct Symbol
{
  std::string name;
  Symbol( std::string _name ) {
    name = _name;
  }
};

// The ConsCell structure is a structure used to build lists
// It contains a pointer to a symbol as well as a pointer to the next ConsCell in the list.
struct ConsCell 
{
  Symbol *first;
  ConsCell *second;
  ConsCell( Symbol *_first, ConsCell *_second = nullptr ) {
    first = _first; second = _second;
  }
};

// The List structure represents a list in Scheme
// It contains a pointer to the first ConsCell inx the list.
// If the head is set to nullptr, then the list is empty.
struct List
{
  ConsCell *head;
  List( ConsCell *_head = nullptr ) { 
    head = _head; 
  }
};

// The null function returns true if list is empty and false otherwise.
bool null( List *list );

// The eqv function returns true if symbol1 is the same as symbol2 and false otherwise.
bool eqv( Symbol *symbol1, Symbol *symbol2 );

// The cons function creates a List starting with item followed by the Symbols in list.
List *cons( Symbol *item, List *list );

// The car function returns the Symbol at the head of list.
// If the list is empty it displays an error and returns nullptr.
Symbol *car( List *list );

// The cdr function returns a List consisting the symbols in the tail of list.
// If the list is empty it displays an error and returns nullptr.
List *cdr( List *list );

// The nil function generates an empty list.
List *nil( );

// The << operators can be used to display a symbol or a list.
std::ostream & operator<<( std::ostream &out, Symbol *sym );
std::ostream & operator<<( std::ostream &out, List *list );

#endif
