#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
using namespace std;

//  Node Declaration

struct node    // node is a structure containing two fields
{
	int salary;
	short id;
	string name;
	struct node *link; // this is a link field containing a pointer to the next node
};

node *front, *rear;  // definition of two pointers, which will be used to point at the node in the front and rear of a queue


					 //Class Declaration

class DynEmpQueue
{
private:
	int counter; // a counter for the number of elemetns in the queue

public:
	void Addqueue(int, short, string);  // insert a new element in the queue
	int getSalary();
	short getID();
	string getName();
	int getCounter();
	void Display();   // display all element frin the queue
	void Dequeue();       // Dequeueete an element from the queue
	node* queueFront();   // queueFront - copies and returns a data item from the front of the queue
	DynEmpQueue()      // default constructor - creates the empty queue
	{
		front = NULL;  // creates the empty queue
		rear = NULL;  // creates the empty queue
		counter = 0;  // sets a counter of the queue equal to 0
	}
};

int DynEmpQueue::getCounter() {

	return counter;
}

int DynEmpQueue::getSalary() {
	node *ptr;     // definition of the ptr pointer pointing at a node
	ptr = front;   // ptr is assigned the address of the front node of the queue
	if (front == NULL) // checks whether the queue is empty, if top == NULL, this means that the queue is empty
		cout << "Queue is empty." << endl;  // and there is nothing to traverse there
	else
	{
		while (ptr != NULL)  // a loop over all elements of the queue util ptr==NULL, that is there is the end of the queue
		{
			return ptr->salary;
		}
	}
}
short DynEmpQueue::getID() {
	node *ptr;     // definition of the ptr pointer pointing at a node
	ptr = front;   // ptr is assigned the address of the front node of the queue
	if (front == NULL) // checks whether the queue is empty, if top == NULL, this means that the queue is empty
		cout << "Queue is empty." << endl;  // and there is nothing to traverse there
	else
	{
		while (ptr != NULL)  // a loop over all elements of the queue util ptr==NULL, that is there is the end of the queue
		{
			return ptr->id;
		}
	}
}
string DynEmpQueue::getName() {
	node *ptr;     // definition of the ptr pointer pointing at a node
	ptr = front;   // ptr is assigned the address of the front node of the queue
	if (front == NULL) // checks whether the queue is empty, if top == NULL, this means that the queue is empty
		cout << "Queue is empty." << endl;  // and there is nothing to traverse there
	else
	{
		while (ptr != NULL)  // a loop over all elements of the queue util ptr==NULL, that is there is the end of the queue
		{
			return ptr->name;
		}
	}
}

void DynEmpQueue::Addqueue(int money, short iD, string Name)
{
	node *tmp;    // definition of the tmp pointer pointing at a node
	tmp = new node;  // dynamic memory allocation for a new node --> address goes to tmp
	tmp->salary = money;
	tmp->id = iD;
	tmp->name = Name;
	tmp->link = NULL;  // setting a link fileld of the node created to NULL
	if (front == NULL)    // if the front node does not exist, that is, if the queue us empty
	{
		front = tmp;     // create a front node by assigning the address of the node pointed by tmp, just
	}
	else {          // if the front node exists,
		rear->link = tmp; // an item should be enqueued from the rear, hence the link field of the rear is assigned the address contained in tmp
	}
	rear = tmp;   // a new rear node is created from the node pointed by tmp
	counter += 1;   // increment the queue counter, since an element was enqueued in the queue
}

void DynEmpQueue::Dequeue()
{
	int sal;      // a variable to carry a dequeued value
	short buf;
	string name1;
	if (front == NULL)      // check whether the queue is empty
		cout << "The Queue is empty." << endl;  // if so, there is nothing to dequeue
	else
	{
		node *tmp = front;   // if the queue is not empty, tmp is assigned the address of the front node
		sal = tmp->salary; // a value stored in the data field of the node pointed by tmp is assigned to item, that is read from the front of the queue
		buf = tmp->id;
		name1 = tmp->name;
		// cout << "Element Dequeued: " << name1 << ", " << endl;  // print out item
																// front is assigned the address contained in the link filed (link) of front pointing to the second item of the queue,
		front = front->link;  // which will become now its front
		delete tmp;  // release the memory as tmp is no longer needed
		counter -= 1;  // decrement the queue counter, since an element was dequeued from the queue
	}
}

node* DynEmpQueue::queueFront()   // queueFront - copies and returns a data item from the front of the queue
{
	int sal;      // a variable to carry a dequeued value
	short buf;
	string name1; // a variable to carry a copied value
	if (front == NULL)  // checks whether the queue is empty, if top==NULL, this means that the stack is
	{
		cout << "The queue is empty. " << endl;
	}
	else
	{   
		return front;
	}
}

void DynEmpQueue::Display()
{
	node *ptr;     // definition of the ptr pointer pointing at a node
	ptr = front;   // ptr is assigned the address of the front node of the queue
	if (front == NULL) // checks whether the queue is empty, if top == NULL, this means that the queue is empty
		cout << "Queue is empty." << endl;  // and there is nothing to traverse there
	else
	{
		// cout << "The queue contains " << counter << " elements" << endl;
		cout << "The queue elements are: " << endl;
		while (ptr != NULL)  // a loop over all elements of the queue util ptr==NULL, that is there is the end of the queue
		{
			cout << "(" << ptr->name << ", " << ptr->id << ", " << ptr->salary << ")-> " << endl;// a value stored in the data field of the node pointed by ptr is printed out
			ptr = ptr->link; // ptr is updated and assigned the address stored in the link field (link) of the current node
							 // thus after this operation ptr contains the address of the next queue node
		}
	}
}
int main()
{
	int choice, item;
	string buff, name;
	int sal;
	short id;
	DynEmpQueue originalqueue, demandsalaryincrease;
	while (1)
	{
		cout << "\n-------------" << endl;
		cout << "   Operations on Queue!" << endl;
		cout << "\n-------------" << endl;
		cout << "1. Enqueue Element into the Queue." << endl;
		cout << "2. Dequeue Element from the Queue." << endl;
		cout << "3. Copy Element from the front of the Queue." << endl;
		cout << "4. Traverse the Queue." << endl;
		cout << "5. Display employees for salary increase." << endl;
		cout << "6. Quit." << endl;
		cout << "Enter your Choice: ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:  // Enqueue Element into the Queue
		{
			cout << "Enter name to be Enqueueed into the queue: ";
			cin >> name;
			cout << "Enter Salary: ";
			cin >> sal;
			cout << "Enter ID: ";
			cin >> id;
			originalqueue.Addqueue(sal, id, name);
			break;
		}
		case 2:  // Dequeue(Delete) Element from the Queue
		{
			originalqueue.Dequeue();
			break;
		}
		case 3:   // Copy front element from the Queue withput deliting it
		{
			node *buf;
			buf = new node;
			buf = originalqueue.queueFront();
			cout << "The Front Element in queue: (Name: " << buf->name <<", ID: " << buf->id <<", Salary: " << buf->salary <<"). " << endl;  // a copied value from the top is printed out
			break;
		}
		case 4:  // Traversing the Queue
		{
			originalqueue.Display();
			break;
		}
		case 5:               
		{
			cout << "Employees for salary increase:" << endl;
			cout << "______________________________\n" << endl;
			while (originalqueue.getCounter() > 0) {
				  if (originalqueue.getSalary() < 50000) {
						demandsalaryincrease.Addqueue(originalqueue.getSalary(), originalqueue.getID(), originalqueue.getName());
						cout << ". Name: " << demandsalaryincrease.getName() << ", ID: "
							<< demandsalaryincrease.getID() << ", Salary: "
							<< demandsalaryincrease.getSalary();
						cout << "\n" << endl;
				}
				originalqueue.Dequeue();
			}
			break;
		}
		case 6:         // exit from the menu and main, accordingly
		
		{
			exit(1);
			break;
		}
		default:
			cout << "Wrong Choice." << endl;
		}
	}
	return 0;
}
