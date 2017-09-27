#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Binary tree class
class intBT {
private:
	struct node {
		int value;
		node *left;
		node *right;
	}*root;
	void insert(node *&, node*&); 
	void deleteNode(int, node*&); 
	void makeDelete(node *&);  
	void display_inorder(node *) const;
	void display_postorder(node *) const; 
	void display_preorder(node *) const; 
public:
	intBT() {
		root = nullptr;
	}
	bool searchNode(int);  
	void insertNode(int);    
	void remove(int); 
	void displayInOrder() const
	{
		display_inorder(root);
	};
	void displayPreOrder()
	{
		display_preorder(root);
	};
	void displayPostOrder()
	{
		display_postorder(root);
	};
};
void intBT::insert(node*& nodePtr, node *& newNode) {

	if (nodePtr == nullptr)
		nodePtr = newNode;   //insert new node
	else if (newNode->value < nodePtr->value)
		insert(nodePtr->left, newNode);   //search left
	else
		insert(nodePtr->right, newNode);  //search right
}
void intBT::insertNode(int num) {
	node *newNode = nullptr; // pointer to new node.

	newNode = new node;
	newNode->value = num;
	newNode->left = newNode->right = nullptr;

	insert(root, newNode);
}
void intBT::display_inorder(node *nodePtr) const
{
	if (nodePtr)
	{
		display_inorder(nodePtr->left);
		cout << nodePtr->value << endl;
		display_inorder(nodePtr->right);
	}
}
void intBT::display_preorder(node *nodePtr) const {
	if (nodePtr)
	{
		cout << nodePtr->value << endl;
		display_preorder(nodePtr->left);
		display_preorder(nodePtr->right);
	}
}
void intBT::display_postorder(node *nodePtr) const {

	if (nodePtr)
	{
		display_postorder(nodePtr->left);
		display_postorder(nodePtr->right);
		cout << nodePtr->value << endl;
	}
}
bool intBT::searchNode(int num) //search for a number
{
	node *nodePtr = root;

	while (nodePtr)
	{
		if (nodePtr->value == num) // if found return true
			return true;
		else if (num < nodePtr->value)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}
void intBT::remove(int num) //delete function
{
	deleteNode(num, root);
}
void intBT::deleteNode(int num, node *&nodePtr)   //recursive function for deletion
{
	if (num < nodePtr->value)
		deleteNode(num, nodePtr->left);
	else if (num > nodePtr->value)
		deleteNode(num, nodePtr->right);
	else
		makeDelete(nodePtr);
}
void intBT::makeDelete(node *&nodePtr)
{
	//use temp pointer for re-attaching left subtree.
	node *tempNodePtr = nullptr;

	if (nodePtr == nullptr)
		cout << "Can't delete empty node." << endl;
	else if (nodePtr->right == nullptr)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left;    //Reattach left child
		delete tempNodePtr;
	}
	else if (nodePtr->left == nullptr)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
	//If node has 2 children....
	else
	{
		// move one node to right
		tempNodePtr = nodePtr->right;
		//Go to the end left node.
		while (tempNodePtr->left)
			tempNodePtr = tempNodePtr->left;
		//Reattach left subtree
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		//Reattach right subtree
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}

int main(int argc, const char * argv[]) {
	//Binary tree object called tree
	intBT tree;
	// Insert values in tree
	tree.insertNode(5);
	tree.insertNode(8);
	tree.insertNode(3);
	tree.insertNode(12);
	tree.insertNode(9);
	//display values
	cout << "Values in the tree:\n";
	tree.displayInOrder();

	// delete 8....
	cout << "deleting 8...\n";
	tree.remove(8);
	// delete 12...
	cout << "deleting 12...\n";
	tree.remove(12);
	// insert 10..
	cout << "inserting 10...\n";
	tree.insertNode(10);
	//Display values...
	cout << "New Values in tree...\n";
	tree.displayInOrder();

	//Display pre Order..
	cout << "displaying in preorder...\n";
	tree.displayPreOrder();
	//Display Post Order...
	cout << "Displaying PostOrder...\n";
	tree.displayPostOrder();
	cout << endl;

	//Search
	cout << "Let's see if there is a 5 and 10 inside of our tree...\n";
	cout << "Is there a 5...  " << tree.searchNode(5) << "\n";
	cout << "Is there a 10... " << tree.searchNode(10) << "\n";
	cout << "If you see a 1, that means it is in our tree. " << endl;
	cout << endl;


	system("pause");
	return EXIT_SUCCESS;
}
