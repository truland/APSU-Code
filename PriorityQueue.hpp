/*
THOMAS RULAND
CSCI 3250 PROGRAMMING ASSIGNMENT 7
COMPILED ON UBUNTU 14.04 USING g++
*/
#include<iostream>

#ifndef PRIORITYQ
#define PRIORITYQ

template<class T>
class PriorityQueue{
private:
	T* marr;//ARRAY TO HOLD THE ITEMS IN THE MAX HEAP
	int mfront;//KEEPING TRACK OF THE FRONT ITEM
	int mback;//KEEPING TRACK OF THE NEXT OPEN SPOT
	int mcap;//CAPACITY OF THE HEAP

public:
	PriorityQueue(int newcap)//SINGLE ARGUEMENT CONSTRUCTOR THAT TAKES THE CAPACITY OF THE HEAP
	{
		mcap=newcap;//SETTING THE CAPACITY OF THE HEAP
		mfront=-1;//NO ITEMS ADDED YET FRONT IS -1 FOR THE ISFULL AND ISEMPTY FUNCTIONS
		mback=0;//NEXT OPEN SLOT IN THE ARRAY/HEAP
		marr=new T[mcap];//THE ACTUAL HEAP
	}

	PriorityQueue(T newarr[],int curritems,int newcap)//TAKES THREE ARGUEMENTS AN ARRAY OF T ITEMS, THE NUMBER OF ITEMS IN THE ARRAY AND THE WANTED CAPACITY
	{
		if(newcap < curritems)
		{
			std::cerr << "ERROR LIST OF ITEMS IS LESS THAN CAPACITY CHANGING BECUASE YOU'RE AN IDIOT" << std::endl;
			newcap=curritems;
		}
		mcap=newcap;//INTENDED CAPACITY OF THE ARRAY
		mfront=0;//THE FRONT IS AT ITEM 0
		marr=new T[mcap];//THE ARRAY HAS CAPACITY
		mback=0;//BACK IS KEEPING TRACK OF THE NEXT OPEN POSITION IN THE ARRAY
		bool moved=true;//USED FOR THE LINEAR TIME ALGORITHM TO FORCE ALL ITEMS TO BE MOVED CORRECTLY
		
		for(int i=0; i<curritems; i++)//ADDING THE ITEMS TO THE ARRAY
		{
			marr[i]=newarr[i];//ARBITRARILY PUTTING THE ITEMS OF THE PASSED IN ARRAY INTO THE QUEUE
			mback++;//INCREMENTING THE BACK OF THE ARRAY TO KEEP TRACK OF THE NEXT OPEN INDEX
		}
		while(moved)//BOOLEAN LOOP TO FORCE ALL ITEMS IN APPROPRIATE ORDER
		{
			moved=false;//PART OF THE ALGORITHM TO FORCE THINGS INTO A CERTAIN ORDER
			for(int i=((mback-2)/2); i>-1; i--)//LOOP TO ITERATE THROUGH EVERY ITEM IN THE ARRAY 
			{
				if(((2*i)+2) <= mback)//MAKING SURE IM NOT LEAVING THE ARRAY BOUNDS AND USING BAD VALUES
				{
					if(marr[i] < marr[(2*i)+1] || marr[i] < marr[(2*i)+2])//IF CURRENT IS LESS THAN EITHER LEFT OR RIGHT CHILD
					{
						if(marr[(2*i)+1] > marr[(2*i)+2] && marr[(2*i)+1] > marr[i])//IF CURRENT LESS THAN LEFT CHILD
						{
							moved=true;//AN ITEM WAS MOVED WE STILL NEED TO ITERATE
							T temp=marr[i];//STANDARD RUN OF THE MILL SWAPPING ALGORITHM
							marr[i]=marr[(2*i)+1];
							marr[(2*i)+1]=temp;
						}else if(marr[(2*i)+2] > marr[(2*i)+1] && marr[(2*i)+2] > marr[i])//THE RIGHT CHILD IS LARGER THAN THE PARENT
						{
							moved=true;//AN ITEM WAS MOVED
							T temp=marr[i];//STANDARD SWAPPING ALGORITHM
							marr[i]=marr[(2*i)+2];
							marr[(2*i)+2]=temp;
						}
					}
				}else if(marr[(2*i)+1] > marr[i])//SPECIAL CASE WHERE THERE IS ONLY A LEFT CHILD OF THE LAST NON LEAF NODE
				{
					moved=true;//AN ITEM WAS MOVED IF IT ENTERS HERE
					T temp=marr[i];//STANDARD SWAPPING ALGORITHM
					marr[i]=marr[(2*i)+1];
					marr[(2*i)+1]=temp;
				}
			}
		}
	}
	//DESTRUCTOR
	~PriorityQueue()
	{
		delete [] marr;//DELETE THE ARRAY|QUEUE
		marr=0;//SET THE ARRAY POINTER TO ZERO
	}
	//EMPTY TEST
	bool isEmpty()
	{
		if(mfront<0)//IF EMPTY THE FRONT OF THE ARRAY IS LESS THAN ZERO
		{
			return true;
		}else{//OTHERWISE IT SHOULD BE 0
			return false;
		}
	}
	//FULL TEST
	bool isFull()
	{
		if((mback)==mcap)//THE BACK POSITION WHICH IS THE LAST POSITON OF THE ARRAY SHOULD EQUAL THE CAPACITY
		{
			return true;
		}else{//OTHERWISE IT'S NOT FULL
			return false;
		}
	}
	//ADDING JUST AN ITEM NORMALLY
	bool push(T item)
	{	//IF IT'S FULL YOU CAN'T DO THAT YOU IDIOT
		if(isFull())
		{
			return false;
		}else{//OTHERWISE YOU'RE OKAY
			marr[mback]=item;

			if(mback==0)//SPECIAL CASE WHERE WE PUSH ONTO AN EMPTY QUEUE
			{
				mback++;//WE INCREMENT BACK
				mfront=0;//FRONT IS NOW AT INDEX 0
				return true;
			}else{//OTHERWISE WERE ADDING NORMALLY
				int i=mback;//ADDING TO THE BACK OF THE QUEUE INITIALLY
				while(marr[i]>marr[(i-1)/2])//MOVE IT UP THE TREE WHILE IT IS LARGER THAN IT'S PARENT
				{
					T temp=marr[(i-1)/2];
					marr[(i-1)/2]=marr[i];
					marr[i]=temp;
					i=(i-1)/2;
				}
				mback++;//INCREMENT THE BACK ONCE
				mfront=0;//FRONT IS SET TO ZERO
				return true;
			}
		}
	}
	//THE TOP OF THE QUEUE 
	T top()
	{
		if(!isEmpty())//IF THE QUEUE IS NOT EMPTY RETURN THE VALUE AT INDEX ZERO
		{
			return marr[0];
		}else{//OTHERWISE YOU'RE AN IDIOT
			std::cerr << "ERROR EMPTY HEAP" << std::endl;
		}
	}
	//REMOVING AN ITEM HAS TO BE DONE FROM THE VERY TOP INDEX
	bool pop()
	{
		if(isEmpty())//IF THE QUEUE IS EMPTY YOU CAN'T DO THIS EITHER STUPID
		{
			return false;
		}else{//OTHERWISE
			T temp=marr[mfront];//SWAP THE LAST LEAF AND THE TOP ITEM
			marr[mfront]=marr[mback-1];
			marr[mback-1]=temp;
			mback--;//DECREMENT THE BACK SO WE PRETEND THAT THE NEWLY SWAPPED ITEM IS NOT THERE ANYMORE

			bool moved=true;//BOOLEAN TO FORCE THINGS
			while(moved)
			{
				moved=false;//BOOLEAN FORCING ALGORITHM
				for(int i=mfront; i<mback; i++)//ITERATING THROUGH EVERY ITEM IN THE QUEUE
				{
					if(((2*i)+2) < mback)//MAKING SURE I DONT ACCIDENTALLY ACCESS THE RIGHT LEAF NODE WHICH MAY OR MAY NOT EXIST
					{
						if((marr[i] < marr[(2*i)+1] || marr[i] < marr[(2*i)+2]))//IF EITHER LEAF IS LARGER THAN THE PARENT
						{
							if(marr[i] < marr[(2*i)+1] && marr[(2*i)+1] > marr[(2*i)+2])//IF THE LEFT CHILD IS THE LARGEST
							{
								moved=true;//PERFORM SWAPPING ALGORITHM AND SET BOOLEAN TO TRUE BECAUSE WE MOVED THINGIES
								temp=marr[i];
								marr[i]=marr[(2*i)+1];
								marr[(2*i)+1]=temp;
							}else if(marr[i]<marr[(2*i)+2] && marr[(2*i)+2] > marr[(2*i)+1])//OTHERWISE THE RIGHT CHILD EXISTS 
							{
								moved=true;//AND IS LARGER SO WE SWAP IT WITH IT'S PARENT AND SET BOOLEAN TO TRUE CAUSE WE MOVED
								temp=marr[i];//THINGIES
								marr[i]=marr[(2*i)+2];
								marr[(2*i)+2]=temp;
							}
						}
					}
				}
			}
			return true;
		}
	}
	//DISPLAYING THE QUEUE AS IT APPEARS IN THE ARRAY
	void display()
	{
		if(isEmpty())//IF IT'S EMPTY I CAN'T DISPLAY THINGS
		{
			std::cerr << "ERROR EMPTY HEAP" << std::endl;
			return;
		}else{//OTHERWISE WE DISPLAY UP TO BACK BUT NOT INCLUDING BACK OF THE ARRAY
			std::cout << marr[0] << std::endl;
			for(int i=1; i<mback; i++)
			{
				std::cout << marr[i] << std::endl;
			}
		}
	}
	//COPY CONSTRUCTOR
	PriorityQueue(const PriorityQueue<T>& copy)
	{
		marr=new T[copy.mcap];//CREATING NEW ARRAY
		mcap=copy.mcap;//COPYING OVER OTHER ARRAY'S CAPACITY
		mfront=0;//FRONT IS AT INDEX ZERO
		mback=copy.mback;//BACK IS COPIED OVER
		for(int i=0; i<mback; i++)
		{
			marr[i]=copy.marr[i];//INDIVIDUAL ITEMS ARE COPIED OVER
		}
	}
	//OVERLOADED ASSIGNMENT OPERATOR
	const PriorityQueue operator=(const PriorityQueue<T> &rhs)
	{
		if(this->marr!=rhs.marr)//MAKING SURE THE TWO THINGS ARE NOT EQUAL ALREADY
		{
			delete [] this->marr;//DELETE LHS ARRAY
			this->mcap=rhs.mcap;//SET LHS CAP TO RHS CAP
			this->mfront=rhs.mfront;//SAME THING FOR FRONT
			this->mback=rhs.mback;//AND BACK 
			this->marr=new T[mcap];//REALLOCATE LHS ARRAY
			for(int i=0; i<rhs.mback; i++)
			{
				this->marr[i]=rhs.marr[i];//COPY OVER VALUES INTO THE ARRAY
			}
		}
		return *this;//RETURN THIS
	}
};

#endif
