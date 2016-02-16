//********************************************************************
// Course: CPSC2620 Fall 2013
// Name: Josh Tymburski
// Assignment #6
// Question #1
// Class Interface
// Professor: Howard Cheng
// Program: BST.h
// Purpose: Header file defines the prototypes of everything used in
//          the BST class
// Programming Partner: Anthony Tymburski
// Software Used: Geany
//********************************************************************

#ifndef BST_H
#define BST_H

#include<string>

using namespace std;

class BST
{
	private:
		// Private nested class Node
		class Node
		{
			public:
				// Key of each Node
				string signature;
				
				// All strings associated with Key
				vector<string> stringList;
				
				// Pointers to point the children
				Node *left, *right;
				
				// Constructor for Node
				Node (Node *m, Node *n, string k) : left{m}, right{n}, 
					  signature{k} {}
		};
		
		// Private find function that returns a pointer to the location
		// of the Node consisting of the key
		BST::Node* find(Node *root, const string& key);
		
		// Private delete function for when the destructor is called
		void deleteTree(Node *root);
		
		// Private insert function that finds the first available
		// position to insert node with string key
		void insert(Node *&root, string key);
		
		// Altered private helper traverse function
		void traverse(void (*f)(const string& key,vector<string>&value),
							    Node *root);
							    
	public:
		// Default Constructor
		BST();
		
		// Destructor
		~BST();
		
		// Initialization of the root node
		Node *root;
		
		// Operation overload to allow for some vector functionality
		vector<string>& operator[](const string& key);
		
		// Public traverse function
		void traverse(void (*f)(const string &key, 
		              vector<string>& value));
};
#endif
