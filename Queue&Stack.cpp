#include "stdafx.h"
#include<iostream>
#include <stack>
#include <vector>
#include<list>
#include <queue>
#include <deque>
using namespace std;


/*
* Node Declaration
*/
struct node    // node is a structure containing two fields
{
	int info;      // this is a data field containing integer
	struct node *link; // this is a link field containing a pointer to the next node
};

node *front, *rear;  // definition of two pointers, which will be used to point at the node in the frunt and rear of a queue


class queueList
{
private:
	int counter; // a counter for the number of elemetns in the queue

public:
	void Enqueue(int);  // insert a new element in the queue
	void Display();   // display all element frin the queue
	int Dequeue();       // Dequeueete an element from the queue
	int counter1();
	bool isEmpty();
	int queueFront(); // queueFront - copies and returns a data item from the front of the queue 
	queueList()      // default constructor - creates the empty queue
	{
		front = NULL;  // creates the empty queue
		rear = NULL;  // creates the empty queue
		counter = 0;  // sets a counter of the stack equal to 0
	}
}m;
int queueList::counter1() {
	return counter;
}
bool queueList::isEmpty() {
	return(counter == 0);
}
/*
* Enqueue Element into the Queue
*/
void queueList::Enqueue(int item)
{
	node *tmp;    // definition of the tmp pointer pointing at a node
	tmp = new  node;  // dynamic memory allocation for a new node --> address goes to tmp
	tmp->info = item;  // loading data (item) into the data filed (info) of the node pointing by tmp
	tmp->link = NULL;  // setting a link fileld of the node created to NULL
	if (front == NULL) { // if the front node does not exist, that is, if the queue us empty
		front = tmp;
	} // create a front node by assigning the address of the node pointed by tmp, just created
	else {            // if the front node exists, 
		rear->link = tmp; // an item should be enqueued from the rear, hence the link field of the rear is assigned the address contained in tmp
	}
		rear = tmp;   // a new rear node is created from the node pointed by tmp
		counter += 1;   // increment the queue counter, since an element was enqueued in the queue
}

/*
* Dequeue (Delete) Element from the Queue
*/
int queueList::Dequeue()
{
	int item;      // a variable to carry a dequeued value
	node *tmp;              // definition of the tmp pointer pointing at a node
	if (front == NULL) {
		// check whether the queue is empty
		cout << "The Queue is empty (Underflow)" << endl;  // if so, there is nothing to dequeue
		return -1;
	}
	else
	{
		tmp = front;   // if the queue is not empty, tmp is assigned the address of the front node 
		item = tmp->info; // a value stored in the data field of the node pointed by tmp is assigned to item, that is read from the front of the queue
		front = front->link;	 // print out item		// decrement the queue counter, since an element was dequeued from the queue
		delete tmp;
		counter -= 1;
		return item;
	}

	// front is assigned the address contained in the link filed (link) of front pointing to the second item of the queue,  // which will become now its front
}

/*
* Copy front element from the Queue withput deliting it
*/
int queueList::queueFront()   // queueFront - copies and returns a data item from the front of the queue 
{
	int item; // a variable to carry a copied value
	if (front == NULL)  // checks whether the queue is empty, if top==NULL, this means that the stack is empty 
		cout << "The Queue is empty (Underflow)" << endl;  // and there is nothing to pop
	else
	{
		item = front->info; // a value stored in the data field of the node pointed by top is assigned to item, that is copied

	}
	return item;  // return a new top of the stack
}

/*
* Traversing the Queue
*/
void queueList::Display()
{
	node *ptr;     // definition of the ptr pointer pointing at a node
	ptr = front;   // ptr is assigned the address of the front node of the queue
	if (front == NULL) { // checks whether the queue is empty, if top == NULL, this means that the queue is empty
		cout << "Queue is empty" << endl;  // and there is nothing to traverse there
	}
	else
	{
		cout << "The queue contains " << counter << " elements" << endl;
		cout << "The queue elements :" << endl;
		while (ptr != NULL)  // a loop over all elements of the queue util ptr==NULL, that is there is the end of the queue
		{
			cout << ptr->info << endl; // a value stored in the data field of the node pointed by ptr is printed out
			ptr = ptr->link; // ptr is updated and assigned the address stored in the link field (link) of the current node				 // thus after this operation ptr contains the address of the next queue node
		}
	}
}

struct nodes      // node is a structure containing two member fields
{
	int info;   // this is a data field containing integer
	struct nodes *link;  // this is a link field containing a pointer to the next node
};

nodes *top; // definition of the pointer, which will be used to point at the node on the top of a stack

			// Stack Class Declaration
class stackList    // stackList is a class utilizing a stack using a linear list
{
private:
	int counterfull; // a counter for the number of elemetns in the stack
public:
	// prototypes of public functions utilizing stack operations
	nodes* createNode(int);
	void push(int); // push - pushs an integer data item into the stack whose current top is in the node pointed by node*
	int pop();      // pop - pops a node from the stack whose current top is in the node pointed by node*
	int counter23();
	bool isStackEmpty();
	void clearStack();
	int topCopy(nodes *top);  // topCopy - copies and returns a data item from the top of the stack whose current top is in the node pointed by node*
	void traverse(nodes*);  // traversing the stack whose current top is in the node pointed by node*
	void destroyStack(nodes*); // destroying the stack whose current top is in the node pointed by node*

	stackList()   // default stack constructor
	{
		top = NULL;  // creates an empty stack
		counterfull = 0; // sets a counter of the elements in the stack to 0
	};
};
// Definitions of public functions utilizing stack operations
void stackList::clearStack() {
	nodes *tmp;
	while (top != NULL)
	{
		tmp = top;
		top = top->link;
		delete tmp;
	}
}
bool stackList::isStackEmpty() {

	return(counterfull == 0);
}
/*
* Push Element into the Stack
*/
int stackList::counter23() {
	return counterfull;
}
nodes* stackList::createNode(int value) {
	nodes *temp = new  nodes;
	if (temp == NULL) {
		cout << "Error: The node was not created correctly." << endl;
		return 0;
	}
	else {
		temp->info = value;
		temp->link= NULL;
		return temp;
	}
}

void stackList::push(int c) {				//function for pushing a node to the stack
	nodes *tmp;
	tmp = new nodes;
	tmp->info = c;
	tmp->link = top;
	top = tmp;
	counterfull++;
}

/*
* Pop Element from the Stack
*/
int stackList::pop() {		
	int c = 0;
	int popped;
	//function for popping a node from the stack
	if (top == NULL) {	//pop operation cannot be performed if the stack is empty
		cout << "The stack is empty. cannot  pop" << endl;
		return c;				//however,this cannot happen in this project, since 
	}
	else {
		popped = top->info;//holds the character
		nodes* temp = top;
		top = top->link;//the second to top node, becomes the new top
		delete temp;
		//the old top is deallocated
		counterfull--; 	//the character is returned
	}
	return popped;
}
/*
* Copy top element from the Stack withput popping it
*/
int stackList::topCopy(nodes *top)   // topCopy - copies and returns a data item from the top of the stack whose current top is in the node pointed by node*
{
	int item; // a variable to carry a copied value
	if (top == NULL)  // checks whether the stack is empty, if top==NULL, this means that the stack is empty 
		cout << "The Stack is empty" << endl;  // and there is nothing to pop
	else
	{
		item = top->info; // a value stored in the data field of the node pointed by top is assigned to item, that is copied

	}
	return item;  // return a new top of the stack
}

/*
* Traversing the Stack
*/
void stackList::traverse(nodes *top)  // traversing the stack whose current top is in the node pointed by top
{
	nodes *ptr;  // defines pointer ptr pointing at node
	ptr = top;  // ptr is assigned the address of the top node of the stack
	if (top == NULL)  // checks whether the stack is empty, if top==NULL, this means that the stack is empty 
		cout << "The Stack is empty" << endl; // and there is nothing to traverse there
	else
	{
		cout << "The stack contains " << counterfull << " elements" << endl;
		cout << "The stack elements :" << endl;
		while (ptr != NULL)  // a loop over all elements of the stack util ptr==NULL, that is there is the end of the stack
		{
			cout << ptr->info << endl; // a value stored in the data field of the node pointed by ptr is printed out
			ptr = ptr->link; // ptr is updated and assigned the address stored in the link field (link) of the current node
							 // thus after this operation ptr contains the address of the next node in the stack
		}
	}
}

void stackList::destroyStack(nodes*) // destroying the stack 
{
	nodes *ptr;  // defines pointer ptr pointing at node
	ptr = top;  // ptr is assigned the address of the top node of the stack
	if (top == NULL)  // checks whether the stack is empty, if top==NULL, this means that the stack is empty 
	{
		delete ptr; // the top node is deleted by releasing memory where it is located
		cout << "The stack is destroyed" << endl; // and there is nothing to traverse there
	}
	else
	{
		while (ptr != NULL)  // a loop over all elements of the stack util ptr==NULL, that is there is the end of the stack
		{
			top = ptr->link;   // which will become now its top
			delete ptr;  // release the memory as ptr containing the previous top node is no longer needed
			ptr = top;  // ptr point now at the new top
			counterfull--; // decrement the stack counter, since an element was popped from the stack
		}
		cout << "The stack is destroyed" << endl; // and there is nothing to traverse there
	}
}

void reverseQueue(queueList *);

int main()
{
	int choice, item;
	queueList *list;
    list = new queueList;
	
	while (1)
	{
		cout << "\n-------------" << endl;
		cout << "Operations on Queue" << endl;
		cout << "\n-------------" << endl;
		cout << "1.Enqueue Element into the Queue" << endl;
		cout << "2.Dequeue Element from the Queue" << endl;
		cout << "3.Copy Element from the front of the Queue" << endl;
		cout << "4.Traverse the Queue" << endl;
		cout << "5. Reverse Queue." << endl;
		cout << "6. Quit." << endl;
		cout << "Enter your Choice: ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:  // Enqueue Element into the Queue
		{
			cout << "Enter value to be Enqueueed into the queue: ";
			cin >> item;
			list->Enqueue(item);
			break;
		}
		case 2:  // Dequeue(Delete) Element from the Queue
		{
			list->Dequeue();
			break;
		}
		case 3:   // Copy front element from the Queue withput deliting it
		{
			item = list->queueFront();
			cout << "Front Element: " << item << endl;  // a copied value from the top is printed out
			break;
		}
		case 4:  // Traversing the Queue
		{
			list->Display();
			break;
		}
		case 5:
		{
			reverseQueue(list);
			list->Display();
			    break;
		}
		case 6: // exit from the menu and main, accordingly
		{
			exit(1);
			break;
		}
		default:
			cout << "Wrong Choice." << endl;
		}
	}
	system("pause");
	return EXIT_SUCCESS;
}

void reverseQueue(queueList *Q) {
	    stackList temporaryHolding;

		while (! Q->isEmpty()) {
			temporaryHolding.push(Q->Dequeue());
		}
		cout << endl << "This is the stack after pushing all dequeued values:" << endl;
		
		while (! temporaryHolding.isStackEmpty()) {
			Q->Enqueue(temporaryHolding.pop());
		}
	}
