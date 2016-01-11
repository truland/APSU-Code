/*
THOMAS RULAND
DATA STRUCTURES AND ALGORITHMS CSCI 3250
PROGRAMMING ASSIGNMENT 4
COMPILED USING g++ ON UBUNTU 14.04
*/
#include<iostream>
#include "IntStack.hpp"

using namespace std;

//main program
int main()
{
	IntStack mine(1000);	//stack
	char menuchoice;	//menu choice chooser
	bool exit=false;	//exit flag
	bool test;		//testing flag
	bool enough;		//enough numbers flag
	
	while(!exit)		//while the flag for exit is not raised
	{
		cout << " Welcome to the weirdest way to do maths. "
		     << "\n What would you like to do human: "
		     << "\n [E]nter an integer " 
		     << "\n [P]erform an operation (+,-,*,/) "
		     << "\n [V]iew result so far "
		     << "\n [C]lear stack for more maths "
		     << "\n [D]isplay stack "
		     << "\n e[X]it program because you're tired of doing integer maths" << endl;
		cout << ">> ";
		cin >> menuchoice;	//recieving input for the menu

		switch(menuchoice)	//yes im going to be evil and use a switch case
		{
			case 'E':	//allowing for both capital and lower case letters becuase i got tired of pressing shift
			case 'e':
					cout << "You have chosen E" << endl;
					int add;
					test=mine.isFull();	//testing for fullness of the stack
					if(test)		//error for when the stack is full
					{
						cout << "Cannot add to stack it is full"
						     << "\nPlease either perform operations or clear stack" << endl;
					}			//adding onto the stack otherwise
					cout << "Enter the integer you'd like to add to the stack" << endl;
					cin >> add;
					mine.push(add);		//actually adding
					break;
			case 'P':	//again i got tired of pressing shift
			case 'p':
					cout << "You have chosen P" << endl;
					char oper;		//choice for choosing the operation
					int alpha;		//top item
					int beta;		//second top item
					int result;		//result from the operation of the top two items
					enough=true;		//assuming there are enough for the operations
					cout << "Which operation would you like to do" << endl;
					cin >> oper;
						switch(oper)
						{
							case '+':	//addition
									cout << "You would like to add the top two numbers" << endl;
									enough=mine.top(alpha);//checking to see if there are any items in stack
									if(enough)
									{
										mine.pop(alpha);//apparently there were
										enough=mine.top(beta);//checking to see if there were two items on the stack
										if(enough)
										{
											mine.pop(beta);//apparently there were
											result=beta+alpha;//adding
											mine.push(result);//pushing reult back onto stack
										}else{
											mine.push(alpha);//there were not two items on the stack so i have to put
											cout << "NOT ENOUGH NUMBERS" << endl;//the first one taken off bakc on
										}
									}else{
										cout << "NOT ENOUCH NUMBERS" << endl;//there werent any items you dingus
									}
									break;
							case '-':	//subtraction
									cout << "You would like to subtract the top two numbers" << endl;
									enough=mine.top(alpha);//same as in addition
									if(enough)
									{
										mine.pop(alpha);//same as in addition
										enough=mine.top(beta);//same as in addition
										if(enough)
										{
											mine.pop(beta);//same as in addition
											result=alpha-beta;//subtracting the top item from the second most top item
											mine.push(result);//same as addition
										}else{
											mine.push(alpha);//same ass addition
											cout << "NOT ENOUGH NUMBERS" << endl;//same as addition
										}
									}else{
										cout << "NOT ENOUCH NUMBERS" << endl;//same as addition

									}
	
									break;
							case '*':	//multiplication
									cout << "You would like to multiply the top two numbers" << endl;
									enough=mine.top(alpha);//same as addition

									if(enough)
									{
										mine.pop(alpha);//same as addition

										enough=mine.top(beta);//same as addition
										if(enough)
										{
											mine.pop(beta);//same as addition
											result=beta*alpha;//multiplying the top two items
											mine.push(result);//same as addition
										}else{
											mine.push(alpha);//same as addition
											cout << "NOT ENOUGH NUMBERS" << endl;//same as addition
										}
									}else{
										cout << "NOT ENOUCH NUMBERS" << endl;//same as addition
									}
	
									break;
							case '/':	//division
									cout << "You would like to divide the top two numbers" << endl;
									enough=mine.top(alpha);//same as addition
									if(enough)
									{
										mine.pop(alpha);//same as addition
										enough=mine.top(beta);//same as addition
										if(enough)
										{
											mine.pop(beta);//same as addition
											result=alpha/beta;//dividing top item by second top most item
											mine.push(result);//same as addition
										}else{
											mine.push(alpha);//same as addition
											cout << "NOT ENOUGH NUMBERS" << endl;//same as addition
										}
									}else{
										cout << "NOT ENOUCH NUMBERS" << endl;//same as addition
									}
	
									break;
							default:	//you have fat fingers like me and pressed the wrong key probably
									cout << "ERROR INVALID OPERATION" << endl;
									break;
						}
					break;
			case 'V':
			case 'v':	//viewing the top most item in the stack
					cout <<"You have chosen V" << endl;
					int peak;//local variable
					test=mine.top(peak);//testing to see if the stack is empty
					if(test)
					{
						cout << peak << endl;//outputting the topmost item if not empty
					}else{
						cout << "Stack is empty" << endl;//its empty why did you try to view an empty list
					}
					break;
			case 'C':
			case 'c':	//clearing the stack
					cout << "You have chosen C" << endl;
					mine.clear();//tis cleared now
					break;
			case 'D':
			case 'd':	//displaying the entire stack
					cout << "You have chosen D" << endl;
					mine.display();//tis displayed
					break;
			case 'X':
			case 'x':	//exit the program
					cout << "You have chosen X" << endl;
					exit=true;
					break;
			default:	//force exiting the program because you pressed the wrong key
					cout << "ERROR INVALID CHiOICE" << endl;
					cout << "EXITING NOW" << endl;
					exit=true;
					break;
		}
	}//end of switch(menuchoice)
	
	return 0;
}
