/**
   Name: Cykelle Semper.

   Course: CMPS 1063 Data Structures, Fall 2019, Dr. Griffin

   Purpose: This program creates a list based stack to hold animals.

   Submission date: 10/15/2019.

 ***********************************************************************************
  Contains code from Lecture 07.
 * Author: Terry Griffin
 * Date: Oct 4th ish 2019
 
 * ListStack.h
 *
 * List stack definition file. This stack hold animal types. Why? Cause integers
 * get a little boring after a while.
 *
 * Author: Terry Griffin
 * Date: Oct 4th ish 2019
 */

#include <iostream>

using namespace std;

/**
 * Animal Type
 */
struct Animal {
	string name;
	double weight;
	double scary;

	// Default constructor
	/*Animal() {
		name = "";
		weight = 0.0;
		scary = 99.0;
	}*/

	// Overloaded constructor
	Animal(string Name, double Weight, double Scary) {
		name = Name;
		weight = Weight;
		scary = Scary;
	}
};

// Overload "<<" operator for animals
 ostream &operator<<(ostream &, const Animal *);

/**
 * Node type.
 *
 * We seperate Animal from Node so we can return an "Animal"
 * when we pop the stack, and don't have to return a "node"
 */
struct Node {
	Animal *A;
	Node *Next;

	// Needs a default constructor

	Node(Animal *a) {
		A = a;
		Next = NULL;
	}
};

/**
 * ListStack
 *
 * List based stack implementation
 *
 */
class ListStack {
private:
	Node *Top;

public:
	ListStack();          // constructor
	void Push(Animal *);  // stack gets Animals
	Animal *Pop();        // Pop returns top animal
	void Print();         // print stack for debugging
};
