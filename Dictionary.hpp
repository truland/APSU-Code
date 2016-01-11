/* CSCI 3250
 * Programming Assignment 6 - Solution
 * Nicholas Coleman */

#ifndef __Program6__Dictionary__
#define __Program6__Dictionary__

#include <iostream>
#include <string>

// DictionaryNode represents a single node in the tree
struct DictionaryNode {

  // The word in the node
  std::string mWord;

  // The left child
  DictionaryNode *mLeft;

  // The right child
  DictionaryNode *mRight;

  // Constructor
  DictionaryNode(std::string word, DictionaryNode *left = nullptr, DictionaryNode *right = nullptr) {
    mWord = word;
    mLeft = left;
    mRight = right;
  }
};

// The Dictionary class stores a collection of words using a binary search tree
class Dictionary {

public:

  // Default constructor
  Dictionary() {
    mRoot = nullptr;
  }

  // Copy constructor
  Dictionary(const Dictionary &);

  // Destructor
  ~Dictionary();

  // Overloaded assignment operator
  const Dictionary & operator=(const Dictionary &);

  // Check if the dictionary is empty
  bool isEmpty() {
    return mRoot == nullptr;
  }

  // Display the contents of the dictionary
  void display() {
    if(isEmpty())
      std::cout << "(empty)" << std::endl;
    else
      displaySubtree(mRoot, "", "", "");
  }

  // Add a word to the dictionary
  // If the word is already in the dictionary do nothing
  void add(std::string word);

  // Remove a word from the dictionary
  // If the word is not in the dictionary do nothing
  void remove(std::string word);

  // Return true if a word is in the dictionary
  // Return false if a word is not the dictionary
  bool contains(std::string word) const;

private:
  
  // The root node of the dictionary
  DictionaryNode *mRoot;

  // Used by display
  void displaySubtree(DictionaryNode *subtree, std::string above, std::string mid, std::string below) {
    // display the node's right subtree
    if(subtree->mRight != nullptr)
      displaySubtree(subtree->mRight, above + "      ", above + "  /---", above + "  |   ");

    // display the contents of the node
    std::cout << mid << subtree->mWord << std::endl;

    // display the node's left subtree
    if(subtree->mLeft != nullptr)
      displaySubtree(subtree->mLeft, below + "  |   ", below + "  \\---", below + "      ");
  }

  // Used by copy constructor and overloaded assignment operator
  DictionaryNode * copyFrom(DictionaryNode *);

  // Used by destructor and overloaded assignment operator
  void deallocate(DictionaryNode *);

};

#endif
