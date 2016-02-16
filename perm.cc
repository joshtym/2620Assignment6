//********************************************************************
// Course: CPSC2620 Fall 2013
// Name: Josh Tymburski
// Assignment #6
// Question #2
// Professor: Howard Cheng
// Program: perm.cc
// Purpose: Program takes two number and finds all the permutations of
//          using the two numbers
// Programming Partner: Anthony Tymburski
// Software Used: Geany
//********************************************************************
#include<iostream>

using namespace std;

//********************************************************************
// Function Prototypes
//********************************************************************
// Recursive function that prints out all the permutations of the given
// number with 1
void print_perm(int A[], int n, int current);

int main()
{
	// Variable Declarations
	int *A;
	int inputedNumber;
	
	// Get the user input for the number they want to permute with 1
	cout << "Please enter the digit you wish to permutate with 1."
			 << endl << "Any digit below 1 will quit the program: ";
	cin >> inputedNumber;
	
	// Loop that allows for repition of the program
	while(inputedNumber > 0)
	{
		// Allocate the inputedNumber array
		A = new int[inputedNumber];
		
		// Array that inputs all the numbers from 1 to the inputedNumber
		for (int i = 1; i <= inputedNumber; ++i)
		{
			A[i-1] = i;
		}
		
		// Call to the recursive function that prints out all the
		print_perm(A, inputedNumber, 0);
		
		// Deallocate allocated memory
		delete[] A;
		
		// Get a new user input
		cout << "Please enter the digit you wish to permutate with 1."
			 << endl << "Any digit below 1 will quit the program: ";
		cin >> inputedNumber;
	}
		
	return 0;
}

//********************************************************************
// Function Definitions
//********************************************************************
// Recursive function to print all the permutations between 1 and the
// user inputed number
void print_perm(int A[], int n, int current)
{
	// Prints out elements once current is equal to the end of the array
	if (current == (n-1))
	{
		for (int i = 0; i < n; ++i)
		{
			cout << A[i];
			
			if (i != (n-1))
			{
				cout << ", ";
			}
		}
		cout << endl;
	}
	else
	{
		// Recursion sequence that ensures all elements of permuations
		// are printed out
		for (int k = current; k < n; ++k)
		{
			swap(A[current], A[k]);
			print_perm(A, n, current + 1);
			swap(A[current], A[k]);
		}
	}
}
