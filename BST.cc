//********************************************************************
// Course: CPSC2620 Fall 2013
// Name: Josh Tymbursk
// Assignment #6
// Question #1
// Class Implementation
// Professor: Howard Cheng
// Program: BST.cc
// Purpose: Takes the header file and defines all the elements of it
// Programming Partner: Anthony Tymburski
// Software Used: Geany
//********************************************************************
#include<iostream>
#include<string>
#include<vector>
#include"BST.h"

using namespace std;

//********************************************************************
// Default Constructor
// Post-Condition -- Default tree is empty with the root declared as
//                   a null pointer
//********************************************************************
BST::BST()
{
	root = nullptr;
}

//********************************************************************
// Deconstructor
// Post-Condition -- By using the private helper delete tree function,
//                   this deallocates all allocated memory
//********************************************************************
BST::~BST()
{
	deleteTree(root);
}

//********************************************************************
// Helper function to assist with deletion of the binary search tree
// once the destructor is called. Note that this was required in order
// for the recursive deletion as you cannot explicitly call Destructor
//********************************************************************
void BST::deleteTree(Node *root)
{
	if(root)
	{
		deleteTree(root->left);
		deleteTree(root->right);
		delete root;
		root = nullptr;
	}
}

//********************************************************************
// Find function that, starting at the root, attempts to locate the
// node that has the equivalent string of key. If none is found, it
// uses the insert function and inserts a new node with string key
//********************************************************************
BST::Node* BST::find(Node *root, const string& key)
{
	if (!root)
		return nullptr;
	if (root->signature == key)
		return root;
	else if (root->signature > key)
		return find(root->left, key);
	else
		return find(root->right, key);
}

//********************************************************************
// Function inserts a new Node with string key. Note that this does
// this whilst maintaining the order of a Binary Search Tree
//********************************************************************
void BST::insert(Node *&root, string key)
{
	if (!root)
	{
		root = new Node(nullptr, nullptr, key);
	}
	else if (root->signature >= key)
	{
		insert(root->left, key);
	}
	else
	{
		insert(root->right, key);
	}
}

//********************************************************************
// [] Operation Overload
// Post-Condition -- Function overloads the [] operator to allow for
//                   use of some of the vector operations
//********************************************************************
vector<string>& BST::operator[](const string& key)
{
	Node *locatedNode;
	locatedNode = find(root, key);
	
	if (locatedNode)
		return locatedNode->stringList;
	else
	{
		insert(root, key);
		locatedNode = find(root, key);
		return locatedNode->stringList;
	}
}

//********************************************************************
// Function that is used to traverse the tree and apply the function
// f to every single element.
//********************************************************************
void BST::traverse(void (*f)(const string &key, vector<string>& value))
{
	traverse(f, root);
}

//********************************************************************
// Private helper function of the above that takes an additional
// parameter, the start point, so it may traverse the tree and apply
// f to every function
//********************************************************************
void BST::traverse(void (*f)(const string& key, vector<string>& value),
			  Node *root)
{
	if(root)
	{
		traverse(f, root->left);
		f(root->signature, root->stringList);
		traverse(f, root->right);
	}
}
