/*
THOMAS RULAND
CSCI 3250 ASSIGNMENT 8
COMPILED ON UBUNTU 14.04 USING g++
*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<sstream>
#include"Graph.h"

using namespace std;

int main()
{
	ifstream cityfile;
	string *city;
	string cityA;
	string cityB;
	int dist=-1;
	int cities=0;
	int matrixpop=0;
	int source=-1;
	int destination=-1;
/*HERE BEGINS THE READING IN OF THE FILE*/
	cityfile.open("distances.txt");

	cityfile >> cities;
	Graph mine(cities);
	city=new string[cities];
	for(int i=0; i<cities; i++)
	{
		cityfile >> city[i];//ARRAY TO STORE THE CITY NAMES IN
	}

	cityfile >> matrixpop;
	for(int i=0; i<matrixpop; i++)
	{
		cityfile >> cityA;
		cityfile >> cityB;
		cityfile >> dist;
		for(int j=0; j<cities; j++)
		{
			if(city[j]==cityA)
			{
				source=j;
			}else if(city[j]==cityB)
			{
				destination=j;
			}
		}
		mine.addEdge(source,destination,dist);//ADDING THE EDGE TO THE MATRIX
	}
	cityfile.close();
/*END OF FILE READING*/
/*TAKING CARE OF THE ZEROS ALONG THE DIAGONAL*/
	for(int i=0; i<cities; i++)
	{
		mine.addEdge(i,i,0);
	}
	cout << "DISPLAY TEST------------------------------------------" << endl;
	mine.displayMatrix();//THE ASSIGNMENT DOES NOT SAY I HAVE TO DEMONSTRATE THIS BUT IT DOES WORK

	Graph overload(10);
	overload=mine;
	cout << "OVERLOAD TEST------------------------------------------" << endl;
	overload.displayMatrix();

	Graph cop(mine);
	cout << "COPY TEST------------------------------------------" << endl;
	cop.displayMatrix();


/*BEGINNING USER INPUT*/
	int distances[cities];
	int preds[cities];
	string inputcity;
	bool contains=false;
	int citypoint;

	cout << "Please enter the name of a city?" << endl;

	cin >> inputcity;

//	HANDLING BAD INPUT
	for(int i=0; i<cities; i++)
	{
		if(inputcity==city[i])
		{
			contains=true;
			citypoint=i;
			break;
		}else{
			contains=false;
		}
	}
	if(!contains)
	{
		cerr << "INVALID CITY" << endl;//BAD INPUT
		delete[] city;
		return 0;
	}
	mine.shortestPaths(citypoint,distances,preds);

	for(int i=0; i<cities; i++)
	{
		cout << "TOTAL DIST: " << distances[i] << " ";
		for(int j=i; j!=citypoint; )
		{
			cout << city[j] << "<--" ;
			j=preds[j];
		}
		cout << city[citypoint] << endl;
	}
	delete[]city;//deleting the string array that held city names
	return 0;
}
