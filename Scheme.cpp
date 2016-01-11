/* CSCI 3250
 * Programming Assignment 5
 * The file Scheme.cpp contains implementations of several functions used to
 * build and manipulate lists.
 */

#include "Scheme.hpp"

using namespace std;

// The null function returns true if list is empty and false otherwise.
bool null( List *list ) {
  return list->head == nullptr;
}

// The eqv function returns true if symbol1 is the same as symbol2 and false otherwise.
bool eqv( Symbol *list1, Symbol *list2 ) {
  return list1->name == list2->name;
}

// The cons function creates a List starting with item followed by the Symbols in list.
List *cons( Symbol *item, List *list ) {
  return new List( new ConsCell( item, list->head ));
}

// The car function returns the Symbol at the head of list.
// If the list is empty it displays an error and returns nullptr.
Symbol *car( List *list ) {
  if( null( list ) ) {
    cout << "Error: attempted to call car on nil value" << endl;
    return nullptr;
  }
  else return list->head->first;
}

// The cdr function returns a List consisting the symbols in the tail of list.
// If the list is empty it displays an error and returns nullptr.
List *cdr( List *list ) {
  if( null( list ) ) {
    cout << "Error: attempted to call cdr on nil value" << endl;
    return nullptr;
  }
  else return new List( list->head->second );
}

// The nil function generates an empty list.
List *nil( ) {
  return new List;
}


// This << operator displays a symbol
ostream & operator<<( ostream &out, Symbol *sym ) {
  out << "'" << sym->name;
  return out;
}

// This << operator displays a list
ostream & operator<<( ostream &out, List *list ) {
  out << "'(";
  ConsCell *curr = list->head;
  while( curr != nullptr ) {
    out << curr->first->name;
    if( curr->second != nullptr )
      cout << " ";
    curr = curr->second;
  }
  out << ")";
  return out;
}
