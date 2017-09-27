#include "stdafx.h"
#include<iostream>
#include <string>
#include "assert.h"

using namespace std;


//Struct declaration

struct node              // A node consists of two member fields
{
	string name;
	int gpa;
	struct node *next;   // link field containing the address to the next node
};

node *start;
node *last;

//Class Declaration

class LinkedListStudents {
protected:
	int count;
public:
	node* create(int, string);  //create new node
	string findTopper();      //searchs and prints name of a student with highest gpa
	void insertFront(int, string);    // inserting a new node in beginning
	void insertEnd(int, string);      // inserting a new node at end
	void insert(int, int, string);    // insert a new node at any position
	void delete_1(int);       // delete an element at any position
	void printList();   //done      // prints list
	int searchstudent(string name);  //searches the list and returns student gpa.
	void destroyList();       // delete all nodes
	LinkedListStudents() {
		start = NULL; // creates an empty list
		last = NULL;
		count = 0;
	}
}m;




int main()
{
	int choice, position, value;
	int x; // buffer to hold value of double returned from search function

	LinkedListStudents List1; // defintion of the linear list 

	start = NULL;  // a single node of the list = NULL
 
	// Assigning values through object List1.    (gpa, name)
	List1.insertFront(80, "Justin");
	List1.insertFront(85, "Big");
	List1.insertFront(86, "Bigger");
	List1.insertFront(87, "Biggest");
	List1.insertFront(95, "Aragon");
	List1.insertFront(78, "Small");
	List1.insertFront(72, "Smallest");

	cout << "------------------------------" << endl;

	string hold1 = List1.findTopper();           //buffer for search function  that returns a string
    cout << "Student with highest gpa: " << hold1 << endl;   //student with highest gpa.. Aragon
	
	cout << endl;

	x = List1.searchstudent("Aragon");   //Search Aragons GPA...
	cout << "Gpa of Aragon is: " << x << endl;

	cout << endl;

	
	List1.insert(100, 3, "INTRUDER");    //Add a node inside... gpa, position, name
	// ----
	List1.printList();    //Print list to show all nodes. 

	cout << endl;
	system("pause");
	return EXIT_SUCCESS;
}




string LinkedListStudents::findTopper() {
	struct node *p, *s;   //pointer for use in sorting
	int value;     //holder value for gpa when swapping occurs
	string not;  //holder value for name  when swapping occurs

	string notHere = "NA";   //to let user know there is nothing to sort.

	if (start == NULL)   // if list is empty, no sorting.
		return notHere;
	p = start;    //if not empty, p is assigned the first node
	while (p != NULL)   //loop over entire list until p=NULL
	{
		for (s = p->next; s != NULL; s = s->next)   // loop starts from current node p and continues til end
		{
			if (p->gpa < s->gpa)     //... if data item pointed to by p > the data pointed to by s
			{
				value = p->gpa;     // the data item from p is copied into value
				p->gpa = s->gpa;    // the data item from the s is copied from the p pointer
				s->gpa = value;     // the data item in value is copied into s.
				not = p->name;
				p->name = s->name;
				s->name = not;
			}
		}
		p = p->next;        //update p for while loop to move to next node.

	}
	return start->name;
}

node* LinkedListStudents::create(int num, string name1) {

	struct node *temp;      // *temp is a pointer to the node to be created
	temp = new(struct node);  // dynamical memory allocation
	if (temp == NULL)    // if memory was not allocated, then this means that no memory is available
	{
		cout << "Memory was not allocated " << endl;   // let the user know
		return 0;
	}
	else
	{
		temp->gpa = num;    // value goes to the data field
		temp->name = name1; // value goes to the data field
		temp->next = NULL;      // NULL goes to the link field (since this is the last node in the list, it does not point at the next node)
		count++;
		return temp;            // return temp containing a pointer to the newly created node
	}
}



void LinkedListStudents::insertFront(int num, string name1) {
	node *newNode;      // pointer to create new node
	newNode = new node; //create new node

	assert(newNode != NULL);  //if unable to allocate memory, terminate program.

	newNode->name = name1;      // assign name
	newNode->gpa = num;         // assign gpa
	newNode->next = start;      //insert newnode before first one
	start = newNode;    //make first point to new first node, newNode.
	count++;
	cout << "Element inserted at beginning" << endl;

	if (last == NULL)  //if list was empty, newNode is also last node.
		last = newNode;
}; //end



void LinkedListStudents::insertEnd(int num, string name1) {
	node *newNode;             // pointer to create new node
	newNode = new node;        //create new node
	assert(newNode != NULL);  //if unable to allocate memory, terminate program.

	newNode->gpa = num;  //assign values
	newNode->name = name1;
	newNode->next = NULL;

	if (start == NULL)    //if empty, newnode is both first and last
	{
		start = newNode;
		last = newNode;
		count++;   //increment count
	}
	else   //list is not empty, insert new node after last
	{
		last->next = newNode;  //insert after last
		last = newNode; //make last point to actual last node
		count++;       //increment
	}
};



void LinkedListStudents::insert(int num, int pos, string name1) {

	struct node *temp, *s, *ptr = nullptr;  // pointers to nodes to manipulate with the linear list

	temp = create(num, name1);  // creates a new node and assigns its address to the temp pointer

	if (pos == 1)   // if the node to be inserted will be the 1st
	{
		if (start == NULL)  // if the list is empty
		{
			start = temp;   // then make temp the 1st node of the list
			start->next = NULL;  // an put NULL in its link field
		}
		else              // otherwise, if the list is not empty
		{
			{
				temp->next = start;  // if the linear list is not empty, then temp->next (a link field of the new node) is assigned the address of the current 1st node (start)
				start = temp;   // start is reassigned, since temp, a newly created node, will be now the first node

			}

			cout << "The element inserted successfully" << endl;  // let the user know
		}
	}
	else if ((pos > 1) && (pos <= count))  // otherwise, if the node to be inserted should be inside the list, between two existing nodes
	{
		s = start; // s is assigned the address of the 1st node
		for (int i = 1; i < pos; i++)  // a loop over all the nodes from the first to pos-1st
		{
			ptr = s;    // when i=1, s points at the 1st node, then it points to the i-th node for any i
			s = s->next; // s is associated now with the next to the current "s" node
		} // after this loop is complete, ptr points to the node "pos-1" and s points to the current "pos"-th node
		ptr->next = temp;  // the link field of ptr (node "pos-1") is assigned the address of the new node, which will become "pos"-th
		temp->next = s;  // now temp points to the new "pos"-th node and its link field is assigned the address of the previous "pos"-th node,
						 // which becomes "pos+1"-st
		count++;        // incrementing the counter of nodes
		cout << "The element inserted successfully" << endl;  // to let the usr know that the operation is complete
	}
	else   // this happens if pos < 1 or pos > counter, that is when the incorrect position index was used
	{
		cout << "Positon is out of range" << endl;  // let the user know
	}
};



void LinkedListStudents::delete_1(int num) {
	node *current; // pointer to traverse list
	node *beforeCurrent; //pointer to trail current pointer
	bool found;

	if (start == NULL) //Case 1. the list empty.
		cout << "Cannot delete an empty list." << endl;
	else {
		if (start->gpa == num) //Case 2.
		{
			current = start;
			start = start->next;
			count--;
			if (start == NULL) //the list has only 1 node
				last = NULL;
			delete current;
		}
		else   // search list for given info
		{
			found = false;
			beforeCurrent = start; // set it to the first node
			current = start->next; // set current to point to second node
			while (current != NULL && !found)
			{
				if (current->gpa != num)
				{
					beforeCurrent = current;
					current = current->next;
				}
				else
					found = true;
			} // end while
			if (found)  // Case 3. if found, delete node
			{
				beforeCurrent->next = current->next;
				count--;

				if (last == current) //node to be deleted was last node
					last = beforeCurrent;  //update last value
				delete current; //delete node from list
			}
			else
				cout << "The item to be deleted is not in the list." << endl;
		} // end else

	} // end else
}; // end delete node



int LinkedListStudents::searchstudent(string name1) {
	bool found = false;
	node *current;   //pointer to traverse the list
	current = start; // set current to point to the first node in the list
	while (current != NULL && !found)   //search list
	{
		if (current->name == name1)  //Search name is found
		{
			found = true;
			return current->gpa;
		}
		else
			current = current->next;    //make current point to next node
	}

}; //end search



void LinkedListStudents::destroyList() {
	node *temp;
	while (start != NULL)    //while there are nodes in the list
	{
		temp = start;  //set temp to current node
		start = start->next;   //advance first to the next node
		delete temp;          //deallocate memory occupied by temp
	}
	last = NULL;    //last to null.
	count = 0;
};



void LinkedListStudents::printList()    // traverse the list displaying content
{
	struct node *temp;    // pointer to node to manipulate with the linear list

	if (start == NULL)   // if the list is empty
	{
		cout << "The list is Empty" << endl;  // let the user know
		return;    // and return to the calling program
	}
	temp = start;    // temp is assigned the address of the 1st node

	cout << "The list elements:" << endl;

	while (temp != NULL)  // a loop over all the nodes
	{
	    cout << "(" << temp->name << ", " << temp->gpa << ")"<< "->";   // printing out a data item containing in the data filed of the current node
		temp = temp->next;     // move to the next node
	}
}
