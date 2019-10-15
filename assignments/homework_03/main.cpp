/*
   Name: Cykelle Semper.

   Course: CMPS 1063 Data Structures, Fall 2019, Dr. Griffin

   Purpose: This program creates a list based stack to hold animals.

   Submission date: 10/15/2019.



   Contains code from Lecture 07. 
 * Author: Terry Griffin
 * Date: Oct 4th ish 2019
 */

#include "ListStack.h"    // include our stack definition
#include <fstream>      
#include <iostream>

using namespace std;

int main() {
	ifstream fin("animals.txt");  // input file of animal info                   
	Animal *a;                    // animal pointer used to hold popped animals
	ListStack LS;                 // List based stack object

	string N;
	double W;
	double S;

	// While still animals in the file
	/*while (!fin.eof()) {
		a = new Animal();                         // allocate memory for an animal
		fin >> a->name >> a->weight >> a->scary;  // load animal with file data
		LS.Push(a);                               // push animal onto the stack
	}*/

	while (!fin.eof()) {
		/*Allocates new memory for an animal, and also loads animal with file data.*/
		a = new Animal(N, W, S); 
		fin >> a->name >> a->weight >> a->scary;
		/*Calls the push function to push an animal onto the stack.*/
		LS.Push(a);                              
	}


	LS.Print();             // Print the stack

	/*cout << endl;           // ummm

	a = LS.Pop();           // get animal off top of stack

	cout << a << endl;      // print animal (cout operator overloaded)

	a = LS.Pop();           // get animal off top of stack again

	cout << a << endl;      // print animal (cout operator overloaded)

	LS.Print();             // print the stack*/
}