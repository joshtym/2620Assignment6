//********************************************************************
// Course: CPSC2620 Fall 2013
// Name: Josh Tymburski
// Assignment #6
// Question #1
// Professor: Howard Cheng
// Program: prob2.cc
// Purpose: Program takes all words from a file, and finds the key, IE,
//          the letters of the word organized alphabetically, of each
//          word. It stores each that correlates with a key into a
//          vector under that key. It then prints out each key, and all
//          the anagrams found in the file that correlates to that key.
// EDIT: This program has been edited to be compatible with the Binary
//       search tree included in assignment 6.
// Programming Partner: Anthony Tymburski
// Software Used: Geany
//********************************************************************
#include<iostream>
#include<map>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include"BST.h"

using namespace std;

//********************************************************************
// Function Definitions - I've been forced to move these to the top so
//                        the traverse function can detect my print
//                        function
//********************************************************************
// Function finds the alphabetically sorted k of the string w
string signature(const string& w)
{
	string sortedString = w;
	sort(sortedString.begin(), sortedString.end());
	
	return sortedString;
}

// Print function associated with the Binary Search Tree
void print(const string& key, vector<string>& value)
{
	cout << "Key: " << key << " Anagrams: ";
	
	// Loop that prints through all the strings in the vector
	for(vector<string>::iterator it = value.begin(); it != value.end(); 
		++it)
		cout << *it << " ";
		
	cout << endl;
}

int main()
{
	// Variable Declarations
	ifstream anagramFile;
	string word,key,fileName;
	BST anagramMap;
		
	cout << "Please enter the name of the file being entered into the "
		 << "system: ";
	cin >> fileName;
	
	anagramFile.open(fileName.c_str());
	
	// Loop through ensuring that the end of file hasn't been reached
	while (!anagramFile.eof())
	{
		anagramFile >> word;
		
		// Find the key of the word
		key = signature(word);
		
		// Implement the word into the correct key
		anagramMap[key].push_back(word);
	}
	
	cout << endl;
	cout << "The list is formatted as follows. It starts with the key"
		 << endl << "and prints out all associated anagrams found"
		 << " from the file with that key." << endl << endl;
	
	// Loop through until the end of the map	 
	/*while (it != anagramMap.end())
	{
		cout << "Key: " << it->first << " Anagrams: ";
		
		// Print out each element in each key
		for (vector<string>::iterator it2 = it->second.begin(); 
			 it2 != it->second.end()-1; ++it2)
			cout << *it2 << " ";
			
		cout << endl;
		++it;
	}*/
	
	// Traverse the Binary Search Tree with the print function from
	// above
	anagramMap.traverse(print);
		
	return 0;
}
