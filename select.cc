//********************************************************************
// Course: CPSC2620 Fall 2013
// Name: Josh Tymbursk
// Assignment #6
// Question #3
// Professor: Howard Cheng
// Program: select.cc
// Purpose: Modification of the quicksort algorithm which returns the
//          kth (user inputed number) smallest element in the array
// Programming Partner: Anthony Tymburski
// Software Used: Geany
//********************************************************************
#include<iostream>

using namespace std;

//********************************************************************
// Function Prototypes
//********************************************************************

// Recursive function that compares a sorted point to check if that
// is the element that the user wants
int quickSelect(int A[], int start, int end, int k);

// Function that determines each pivot point.
int partition(int A[], int start, int end);

int main()
{
	// Variable Declarations
	int arraySize, k;
	int *A;
	
	// Get the array size from the user
	cout << "Please enter the size of the array (< 1 will terminate the"
		 << " the program): ";
	cin >> arraySize;
	
	// Fail safe in case the user enters more than one integer
	cin.ignore(10000, '\n');
	
	// Only continue on to the rest of the program if the array is
	// greater than 0
	while (arraySize > 0)
	{
		// Creation of new array of the user inputed size
		A = new int[arraySize];
		
		// Get which element the user wants to find, IE the 'kth'
		// smallest element.
		cout << "Please enter the 'kth' smallest element you would like"
			 << " to find: ";
		cin >> k;
		
		// Fail safe incase user enters more than one integer
		cin.ignore(10000, '\n');
		
		// Fail safe incase user inputs a k value that is invalid.
		while (k > arraySize || k < 1)
		{
			// Re input the element k
			cout << endl;
			cout << "That is not a valid 'smallest element'! Please"
				 << " re-enter the value: ";
			cin >> k;
			
			// Another fail safe
			cin.ignore(10000, '\n');
			
			cout << endl;
		}
		
		
		cout << "Please enter your arraySize number of elements into"
			 << " the terminal: ";
			 
		// Loop to enter in the arraySize number of elements into the
		// array	 
		for (int i = 0; i < arraySize; ++i)
		{
			cin >> A[i];
		}
		
		// Fail safe if user inputs too many integers.
		cin.ignore(10000, '\n');
		cout << endl;
		
		// Call to the function to get the 'kth' smallest element
		cout << "The " << k << "(rst/nd/rd/th) smallest element in the"
			 << " array is " << A[quickSelect(A, 0, arraySize, k-1)]
			 << "." << endl << endl;
		
		// Deallocate allocated memory 
		delete[] A;
		
		// Re run the program
		cout << "Please enter the size of the array (< 1 will terminate"
			 << " the program): ";
		cin >> arraySize;
		// Fail safe
		cin.ignore(10000, '\n');
	}
	
	cout << endl << "Program Terminated." << endl;
}

//********************************************************************
// Function Definitions
//********************************************************************

// Recursive function that is a modified version of the quicksort
// function. Determines each successive pivot and compares it to the
// k index to see if this is indeed the element that is being looked
// for. 
int quickSelect(int A[], int start, int end, int k)
{
	// Check if the array is greater than 1
	if (end - start > 1)
	{
		// Determine the pivot point
		int pivot = partition(A, start, end);
		// If the pivot is our kth index, then return
		if (pivot == k)
			return pivot;
		// If the pivot is greater than the kth index, then we only
		// need to repeat the function for the left side of the pivot
		// point
		else if (pivot > k)
			quickSelect(A, start, pivot, k);
		// If the pivot is smaller than the kth index, then we only
		// need to repeat the function for the right side of the pivot
		// point
		else
			quickSelect(A, pivot + 1, end, k);
	}
	else // If array is of size 1, then k is the element
		return k;
}

// Function that determines the pivot for the above function. Does this
// by comparing the first element to each one and determines which place
// to put it as the 'pivot' point
int partition(int A[], int start, int end)
{
	int i, j;
	i = start+1;
	// Loop that compares each element to the start element. If this
	// is the case, then they swap
	for(j = start+1;j < end; ++j)
	{
		if (A[j] <= A[start])
			swap(A[i++], A[j]);
	}
	
	swap(A[start], A[i-1]);
	return i-1;
}
