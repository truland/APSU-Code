/*
THOMAS RULAND
CSCI 3250 ASSIGNMENT 6
COMPILED ON UBUNTU 14.04 USING g++
*/
#include<iostream>
#include<string>
#include"Dictionary.hpp"

using namespace std;

//ADDING WORDS TO  YOUR DICTIONARY
void Dictionary::add(string word)
{
	DictionaryNode* curr=mRoot;//STARTING SEARCH AT ROOT
	DictionaryNode* parent=nullptr;//KEEPTING TRACK OF PARENT

	while(curr!=nullptr)//CHECKING TO SEE IF TREE IS EMPTY
	{
		parent=curr;//MOVING PARENT TO CURRENT NODE OF THE NON-EMPTY TREE
		if(word<curr->mWord)//IF THE WORD WE'RE ADDING IS LESS THAN THE CURRENT NODES WORD MOVE TO THE LEFT SUBTREE
		{
			curr=curr->mLeft;
		}else{//ELSE MOVE TO THE RIGHT SUBTREE
			if(word==curr->mWord)//SPECIAL CASE WHERE THE WORD IS REPEATED
			{
				break;
			}
			curr=curr->mRight;
		}
	}
	
		if(mRoot==nullptr)//WERE STARTING WITH AN EMPTY TREE
		{
			mRoot=new DictionaryNode(word,nullptr,nullptr);//SET THE ROOT'S WORD TO OUR WORD
		}else if(word<parent->mWord)//IF OUR WORD IS SMALLER THAN THE PARENT'S WORD ADD TO THE LEFT SUBTREE
		{
			parent->mLeft=new DictionaryNode(word,nullptr,nullptr);
		}else if(word>parent->mWord)//ELSE ADD TO THE PARENT'S RIGHT SUBTREE
		{
			parent->mRight=new DictionaryNode(word,nullptr,nullptr);
		}else{
			return;//SPECIAL CASE WHERE WORD IS REPEATED
		}
}

//SEARCHING FOR WORDS IN THE DICTIONARY "I PROBABLY SHOULD HAVE DONE THIS ONE FIRST IT PROBABLY WOULD'VE MADE THE OTHERS EASIER
bool Dictionary::contains(string word) const
{
	DictionaryNode* curr=mRoot;//STARTING AT ROOT NODE
	if(curr==nullptr)//EMPTY TREE OBCIOUSLY NOTHING IS IN IT
	{
		return false;//RETURNING FALSE FOR EMPTY TREE
	}
	
	while(curr!=nullptr)//SEACHING THROUGH THE TREE THAT IS NOT EMPTY
	{
		if(word==curr->mWord)//IF THE WORD IS AT THE CURRENT NODE RETURN TRUE
		{
			return true;
		}else if(word < curr->mWord)//ELSE MOVE TO THE LEFT TREE IF SEARCH TERM IS SMALLER AND REPEAT
		{
			curr=curr->mLeft;
		}else{//ELSE MOVE TO THE RIGHT SUBTREE
			curr=curr->mRight;
		}
	}
	return false;//RETURNING FALSE WHEN THE WORD IS NOT FOUND

}

//REMOVING WORDS FROM THE DICTIONARY
void Dictionary::remove(string word)
{
	DictionaryNode* curr=mRoot;//STARTING AT THE ROOT
	DictionaryNode* parent=curr;//KEEPING TRACK OF THE PARENT

	if(!contains(word) || curr==nullptr)//CHECKING FOR EMPTY TREE AND IF THE WORD EXISTS IN THE TREE
	{
		return;
	}

	while(curr!=nullptr)//STARTING SEARCH
	{
		if(word==curr->mWord)//IF WORD IS THE ROOT BREAK OUT OF SEARCH
		{
			break;
		}else if(word<curr->mWord)//IF THE WORD IS SMALLER THAN THE CURRENT NODE MOVE LEFT
		{
			curr=curr->mLeft;
			if(word==curr->mWord)//IF THE WORD IS AT THE LEFT NODE BREAK
			{
				break;
			}
			parent=curr;//ELSE MOVE THE PARENT
		}else{			  //ELSE MOVE TO THE RIGHT NODE OF THE TREE
			curr=curr->mRight;
			if(word==curr->mWord)//IF THE WORD IS AT THE RIGHT NODE OF THE TREE BREAK
			{
				break;
			}
			parent=curr;//ELSE MOVE THE PARENT
		}
	}
//	cout << "Parent: " << parent->mWord << " Curr: " << curr->mWord << endl;//DEBUGGING STATEMENT IGNORE

	if(curr->mRight==nullptr && curr->mLeft==nullptr)//LEAF CASE
	{
		if(word<parent->mWord)//IF THE WORD IS SMALLER THAN THE PARENT'S WORD
		{
			parent->mLeft=nullptr;//RESET THE PARENT'S LEFT NODE TO NULL
			delete curr;//AND DELETE THE CURRENT NODE
		}else{
			parent->mRight=nullptr;//ELSE SET THE PARENT'S RIGHT NODE TO NULL
			delete curr;//AND DELETE THE CURRENT NODE
		}
	}else if(curr->mRight==nullptr && curr->mLeft!=nullptr)//EMPTY RIGHT SUBTREE CASE
	{
		if(word<parent->mWord)//IF THE WORD IS SMALLER THAN THE PARENT'S WORD
		{
			parent->mLeft=curr->mLeft;//MOVE CURRENT'S LEFT SUBTREE TO THE PARENT'S LEFT SUBTREE
		}else{
			parent->mRight=curr->mLeft;//ELSE MOVE THE CURRENT'S RIGHT SUBTREE TO THE PARENT'S LEFT SUBTREE
		}
		delete curr;//DELETE CURRENT
	}else if(curr->mLeft==nullptr && curr->mRight!=nullptr)//EMPTY LEFT SUBTREE CASE
	{
		if(word<parent->mWord)//IF WORD IS SMALLER THAN THE PARENT'S WORD
		{
			parent->mLeft=curr->mRight;//MOVE CURRENT'S RIGHT SUBTREE TO THE PARENT'S LEFT SUBTREE
		}else{
			parent->mRight=curr->mRight;//ELSE MOVE CURRENT'S RIGHT SUBTREE TO THE PARENT'S RIGHT SUBTREE
		}
	}else{//FINAL CASE WHERE NODE HAS BOTH SUBTREE'S
		DictionaryNode* temp=curr->mLeft;//THIS IS FOR DELETION BY COPY METHOD
		parent=temp;//SETTING TEMPORARY VARIABLE TO CURRENT'S LEFT SUBTREE AND KEEPING TRACK OF TEMP'S PARENT NOW
		if(temp->mRight==nullptr)//SPECIAL CASE WHERE CURRENT'S LEFT NODE HAS NO RIGHT NODE
		{
			curr->mLeft=temp->mLeft;//SETTING CURRENT'S LEFT NODE TO CURRENT'S LEFT NODE'S LEFT NODE 
			curr->mWord=temp->mWord;//CHANGING THE VALUES SO THEY'RE CORRECT
			delete temp;//DELETING TEMP
			return;//EXITING FOR SAFETY
		}
		while(temp->mRight!=nullptr)//OTHER CASES WHERE CURRENT'S LEFT NODE HAS AT LEAST ONE RIGHT NODE
		{
			parent=temp;//MOVING TO CURRENT'S LEFT NODE'S RIGHT MOST NODE
			temp=temp->mRight;//KEEPING TRACK OF THE PARENT OF THE RIGHT MOST NODE
		}
		curr->mWord=temp->mWord;//REPLACING THE CURRENT WORD
		parent->mRight=temp->mLeft;//ADJUSTING CURRENT'S LEFT NODE'S RIGHTMOST NODE TO NULL
		delete temp;//DELETING TEMP
	}
}

//DESTRUCTOR
Dictionary::~Dictionary()
{
	deallocate(mRoot);//DEALLOCATE FROM ROOT NODE
}

//DEALLOCATION
void Dictionary::deallocate(DictionaryNode* curr)
{
	if(curr!=nullptr)//BASE CASE IS WHEN POINTER IS NULL SO DEALLOCATE WHEN NOT NULL
	{
		deallocate(curr->mLeft);//DEALLOCATE ALL THE WAY LEFT
		deallocate(curr->mRight);//THEN DEALLOCATE ALL THE WAY RIGHT
		delete curr;//DELETING CURRENT NODE
	}
}

DictionaryNode* Dictionary::copyFrom(DictionaryNode* curr)
{
	if(curr)//IF NOT NULL
	{
		add(curr->mWord);//ADD THE VALUE TO THE TREE
		copyFrom(curr->mLeft);//COPY FROM LEFT DOWN
		copyFrom(curr->mRight);//COPY FROM RIGHT DOWN
	}
	return curr;//RETURN CURRENT VALUE
}

Dictionary::Dictionary(const Dictionary& copy)
{
	mRoot=nullptr;//SETTING THE DICTIONARYS ROOT TO NULL
	copyFrom(copy.mRoot);//COPYING FROM THE COPY'S ROOT ALL THE WAY THROUGH
}

const Dictionary & Dictionary::operator=(const Dictionary &rhs)
{
	if(this->mRoot!=rhs.mRoot)//CHECKING TO MAKE SURE THIS DOESNT EQUAL RHS
	{
		deallocate(mRoot);//DEALLOCATE THIS'S ROOT
		mRoot=nullptr;//SET IT TO NULL
		copyFrom(rhs.mRoot);//COPY FROM RHS'S ROOT DOWN
	}
	return *this;//RETURN THIS
}
