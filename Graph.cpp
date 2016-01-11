/*
THOMAS RULAND
CSCI 3250 ASSIGNMENT 8
COMPILED ON UBUNTU 14.04 USING g++
*/
#include<iostream>
#include<iomanip>
#include"Graph.h"

//The number of vertices in the graph\
int mNumVertices;
// The adjacency matrix for the graph\
int** mMatrix;
// The maximum weight for an edge in the graph (used for non-adjacent vertices)\
static const int MAX_WEIGHT = 9999;

// Constructor
Graph::Graph( int numVertices )
{
	mNumVertices=numVertices;//setting number of vertices
	mMatrix=new int *[mNumVertices];
	for(int i=0; i<mNumVertices; i++)
	{
		mMatrix[i]=new int[mNumVertices];	//dynamic 2d array	
	}
	for(int i=0; i<mNumVertices; i++)
	{
		for(int j=0; j<mNumVertices; j++)
		{
			mMatrix[i][j]=MAX_WEIGHT;//initially everything is infinity
		}
	}
}

// Copy Constructor
Graph::Graph( const Graph & copy)
{
	mNumVertices=copy.mNumVertices;
	mMatrix=new int*[mNumVertices];
	for(int i=0; i<mNumVertices; i++)
	{
		mMatrix[i]=new int[mNumVertices];//dynamic 2d array
	}

	for(int i=0; i<mNumVertices; i++)
	{
		for(int j=0; j<mNumVertices; j++)
		{
			mMatrix[i][j]=copy.mMatrix[i][j];//copying over values
		}
	}
}
  
// Destructor
Graph::~Graph()
{
	deallocate();//deletion
}

// Overloaded Assignment Operator
const Graph & Graph::operator=(const Graph & rhs)
{

	deallocate();//deleting old array
	mNumVertices=rhs.mNumVertices;
	mMatrix=new int*[mNumVertices];
	for(int i=0; i<mNumVertices; i++)
	{
		mMatrix[i]=new int[mNumVertices];//creating new 2d dynamic array
	}

	for(int i=0; i<mNumVertices; i++)
	{
		for(int j=0; j<mNumVertices; j++)
		{
			mMatrix[i][j]=rhs.mMatrix[i][j];//transferring data over
		}
	}

	return *this;
}

// Adds an edge to the graph
// Returns false if vertices are out of range or weight is negative
bool Graph::addEdge( int sourceVertex, int targetVertex, int weight )
{
	if(weight<0 || ((sourceVertex < 0) || (sourceVertex > (mNumVertices-1))) || ((targetVertex < 0) || (targetVertex > (mNumVertices-1))))
	{
//		std::cout << "false" << std::endl;
		return false;
	}else
	{
//		std::cout << "not true" << std::endl;
		mMatrix[sourceVertex][targetVertex]=weight;//these two things are connected
		mMatrix[targetVertex][sourceVertex]=weight;//these are also connected
//		std::cout << "true" << std::endl;
		return true;
	}
}
  
// Computes the shortest paths from source_vertex to all other vertices
// using Dijkstra's shortest path algorithm
// Distances are stored in currDist
// Predecessors in path are stored in predecessor
void Graph::shortestPaths( int sourceVertex, int currDist[], int predecessor[] )
{
	bool checked[mNumVertices];
	bool allchecked=true;
	int currV;
	int minDist;
	for(int i=0; i<mNumVertices; i++)
	{
		currDist[i]=MAX_WEIGHT;
		checked[i]=true;
	}
	currDist[sourceVertex]=0;//source is zero from itself
	predecessor[sourceVertex]=sourceVertex;//the source's predecessor is itself

	do
	{
		minDist=MAX_WEIGHT;//settign min to max
		for(int i=0; i<mNumVertices; i++)
		{
			if(checked[i])//if the item has not been checked
			{
				if(minDist>currDist[i])//if the distance is less than the mindist
				{
					minDist=currDist[i];//update crap
					currV=i;//keep track of the index that i updated crap on
				}
			}
		}
		checked[currV]=false;//set the one thing im checking to checked
		for(int i=0; i<mNumVertices; i++)//iterating through all the neighbors
		{
			if((currDist[currV]+mMatrix[i][currV])<currDist[i])//if the distance from the new choice is shorter update
			{
				currDist[i]=currDist[currV]+mMatrix[i][currV];
				predecessor[i]=currV;//update the predecessor
			}
		}
		for(int i=0; i<mNumVertices; i++)//check to see if we went through everything
		{
			if(checked[i]==true)
			{
				allchecked=true;
			}else{
				allchecked=false;
			}
		}
	}while(allchecked);
}

// Displays the contents of the adjacency matrix
void Graph::displayMatrix()//displaying stuff nice and pretty like
{
	for(int i=0; i<mNumVertices; i++)
	{
		for(int j=0; j<mNumVertices; j++)
		{
			std::cout << mMatrix[i][j] << "    ";
		}
		std::cout << std::endl;
	}
}


// Deallocate the matrix
void Graph::deallocate()//deleting dynamic 2d array
{
	for(int i=0; i<mNumVertices; i++)
	{
		delete [] mMatrix[i];
	}
	delete [] mMatrix;
}
/*
// Copy data from an existing Graph object
void Graph::copyFrom(const Graph &);		//I REFUSE TO USE THIS
*/
