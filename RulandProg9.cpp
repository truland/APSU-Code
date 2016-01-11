/* CSCI 3250
 * Programming Assignment 9
 * THOMAS RULAND
 * Implements and tests six different sorting algorithms
	COMPILED ON UBUNTU 14.04 USING g++
 */

#include<iostream>
#include "SortStats.hpp"

using namespace std;

void insertionSort(int arr[], int size, SortStats &stats);
void selectionSort(int arr[], int size, SortStats &stats);
void bubbleSort(int arr[], int size, SortStats &stats);
void heapSort(int arr[], int size, SortStats &stats);
void quickSort(int arr[], int size, SortStats &stats);
void partition(int arr[],int low,int high,SortStats &stats);
void mergeSort(int arr[], int size, SortStats &stats);
void merge(int arr[],int low,int high,SortStats &stats);
void actuallymerging(int arr[],int low,int high,SortStats &stats);

int main()
{
  const int SIZE = 20;

  // Tests each algorithm using four different orderings.
  // Set the last argument to true to display contents of array before and after sorting
  testSort("insertion sort", SIZE, insertionSort, false);
  testSort("selection sort", SIZE, selectionSort, false);
  testSort("bubble sort", SIZE, bubbleSort, false);
  testSort("heapsort", SIZE, heapSort, false);
  testSort("quicksort", SIZE, quickSort, false);
  testSort("mergesort", SIZE, mergeSort, true);

  return 0;
}

void insertionSort(int arr[], int size, SortStats &stats) {
  /* YOUR CODE HERE */
  int j;
  int i;
  for(stats.assign(i,0); stats.less(i,size); stats.assign(i,i+1))
  {
	stats.assign(j,i);
	while(stats.less(0,j) && stats.less(arr[j],arr[j-1]))
	{
		stats.swap(arr[j],arr[j-1]);
		stats.assign(j,j-1);
	}
  }
}

void selectionSort(int arr[], int size, SortStats &stats) {
  /* YOUR CODE HERE */
  int i;
  int j;
  int min;
  for(stats.assign(j,0); stats.less(j,size-1); stats.assign(j,j+1))
  {
	  stats.assign(min,j);
	  for(stats.assign(i,j+1); stats.less(i,size); stats.assign(i,i+1))
	  {
		  if(stats.less(arr[i],arr[min]))
			  stats.assign(min,i);
	  }
	  if(stats.less(min,j) || stats.less(j,min))
		  stats.swap(arr[j],arr[min]);
  }
}

void bubbleSort(int arr[], int size, SortStats &stats) {
  /* YOUR CODE HERE */
  bool swapped=true;
  int i;

  while(swapped)
  {
	  swapped=false;
	  for(stats.assign(i,1); stats.less(i,size); stats.assign(i,i+1))
	  {
		if(stats.less(arr[i],arr[i-1]))
		{
			stats.swap(arr[i],arr[i-1]);
			swapped=true;
		}
	  }
  }
}

void heapSort(int arr[], int size, SortStats &stats) {
  /* YOUR CODE HERE */
  int root;
  int child;
  int i;

  for(stats.assign(i,((size-2)/2)); stats.less(-1,i); stats.assign(i,i-1))
  {
	stats.assign(root,i);
	while(stats.less(((root*2)+1),size))
	{
		stats.assign(child,(2*root)+1);
		if((stats.less(child+1,size)) && (stats.less(arr[child],arr[child+1])))
		{
			stats.assign(child,child+1);
		}
		if(stats.less(arr[root],arr[child]))
		{
			stats.swap(arr[root],arr[child]);
			stats.assign(root,child);
		}else{
			break;
		}
	}
  }
  for(stats.assign(i,size-1); stats.less(0,i); stats.assign(i,i-1))
  {
	  stats.swap(arr[i],arr[0]);
	  root=0;
          while(stats.less(((root*2)+1),i))
	  {
		stats.assign(child,(2*root)+1);
		if((stats.less(child+1,i)) && (stats.less(arr[child],arr[child+1])))
		{
			stats.assign(child,child+1);
		}
		if(stats.less(arr[root],arr[child]))
		{
			stats.swap(arr[root],arr[child]);
			stats.assign(root,child);
		}else{
			break;
		}
	 } 
  }
}

void quickSort(int arr[], int size, SortStats &stats) {
  /* YOUR CODE HERE */
  partition(arr,0,size,stats);
}

void partition(int arr[],int low,int high,SortStats &stats)
{
	int pivot;
	int i;
	int j;
	stats.assign(i,low+1);
	stats.assign(j,high);
	stats.swap(arr[low],arr[(low+high)/2]);
	stats.assign(pivot,arr[low]);

	while(stats.less(i,j+1))
	{
		while(stats.less(arr[i],pivot))
		{
			stats.assign(i,i+1);
		}
		while(stats.less(pivot,arr[j]))
		{
			stats.assign(j,j-1);
		}
		if(stats.less(i,j))
		{
			stats.swap(arr[i++],arr[j--]);
		}else{
			stats.assign(i,i+1);
		}
	}
	stats.swap(arr[low],arr[j]);
	if(stats.less(low,j-1))
	{
		partition(arr,low,j-1,stats);
	}
	if(stats.less(j+1,high))
	{
		partition(arr,j+1,high,stats);
	}
}

void mergeSort(int arr[], int size, SortStats &stats) {
  /* YOUR CODE HERE */
	merge(arr,0,size,stats);
}

void merge(int arr[],int low,int high,SortStats &stats)
{
	int middle;
	if(low<high)
	{
		stats.assign(middle,((low+high)/2));
		merge(arr,low,middle,stats);
		merge(arr,middle+1,high,stats);
		actuallymerging(arr,low,high,stats);
	}
}

void actuallymerging(int arr[],int low,int high,SortStats &stats)
{
	int mid;
	stats.assign(mid,((low+high)/2));
	int i;
	stats.assign(i,low);
	int j;
	stats.assign(j,low);
	int k;
	stats.assign(k,mid+1);
	int temp[high];
	int count;

	while((stats.less(j,mid+1)) && (stats.less(k,high+1)))
	{
		if(stats.less(arr[j],arr[k]))
		{
			stats.assign(temp[i],arr[j]);
			stats.assign(i,i+1);
			stats.assign(j,j+1);
		}else{
			stats.assign(temp[i],arr[k]);
			stats.assign(i,i+1);
			stats.assign(k,k+1);
		}
	}
	while(stats.less(j,mid+1))
	{
		stats.assign(temp[i],arr[j]);
		stats.assign(j,j+1);
		stats.assign(i,i+1);
	}
	while(stats.less(k,high+1))
	{
		stats.assign(temp[i],arr[k]);
		stats.assign(i,i+1);
		stats.assign(k,k+1);
	}
	for(stats.assign(count,low); stats.less(count,i); stats.assign(count,count+1))
	{
		stats.assign(arr[count],temp[count]);
	}
}
