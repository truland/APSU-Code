/*
THOMAS RULAND
CSCI 3250 ASSIGNMENT 6
COMPILED ON UBUNTU 14.04 USING g++
*/
#include<iostream>
#include<string>
#include"Dictionary.hpp"

using namespace std;

int main()
{
	string Jabberwocky[]={"twas", "brillig", "and", "the", "slithy", "toves",
			      "did", "gyre", "and", "gimble", "in", "the", "wabe",
		              "all", "mimsy", "were", "the", "borogoves",
         	              "and", "the", "mome", "raths", "outgrabe"};
	Dictionary mine;
/*
	Dictionary large;
	for(int i=50; i<100; i++)
	{
		large.add(to_string(i));
	}
	for(int i=25; i>0; i--)
	{
		large.add(to_string(i));
	}
	for(int i=25; i<50; i++)
	{
		large.add(to_string(i));
	}
	large.display();
*/
	cout << "--------------------EMPTY TREE CURRENTLY--------------------------------" << endl;
	cout << "Is \"twas\" in the current dictionary: " << mine.contains("twas") << endl;
	cout << "Is \"outgrabe\" in the current dictionary: " << mine.contains("outgrabe") << endl;
	cout << "Is \"were\" in the current dictionary: " << mine.contains("were") << endl;
	cout << "Is \"poppycock\" in the current dictionary: " << mine.contains("poppycock") << endl;
	cout << "------------------------------------------------------------------------" << endl;



	for(int i=0;i<23;i++)
	{
		mine.add(Jabberwocky[i]);
	}

	cout << "------------------TREE DISPLAY------------------------------------------" << endl;
	mine.display();
	cout << "------------------------------------------------------------------------" << endl;

	
	cout << "--------------------FULL TREE CURRENTLY--------------------------------" << endl;
	cout << "Is \"twas\" in the current dictionary: " << mine.contains("twas") << endl;
	cout << "Is \"outgrabe\" in the current dictionary: " << mine.contains("outgrabe") << endl;
	cout << "Is \"were\" in the current dictionary: " << mine.contains("were") << endl;
	cout << "Is \"poppycock\" in the current dictionary: " << mine.contains("poppycock") << endl;
	cout << "------------------------------------------------------------------------" << endl;

	mine.remove("were");
	mine.remove("twas");
	mine.remove("mome");
	mine.remove("poppycock");

	cout << "After trying to remove \"were\",\"poppycock\",\"mome\",\"twas\" " << endl;
	cout << "------------------TREE DISPLAY------------------------------------------" << endl;
	mine.display();
	cout << "------------------------------------------------------------------------" << endl;

	Dictionary copyTest(mine);

	cout << "After copying previous tree over to a new tree" << endl;
	copyTest.display();

	cout << "COPY------------------------------------------------------------------------" << endl;
	copyTest.display();
	cout << "ORIGINAL------------------------------------------------------------------------" << endl;
	mine.display();

	Dictionary eqtest;
	eqtest=mine;
	eqtest.display();
	cout << "ORIGINAL------------------------------------------------------------------------" << endl;
	mine.display();
	cout << "COPY------------------------------------------------------------------------" << endl;
	copyTest.display();
	cout << "EQUAL OVERLOAD------------------------------------------------------------------------" << endl;
	eqtest.display();

	return 0;
}
