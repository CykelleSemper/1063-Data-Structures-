/**
  Name: Cykelle Semper.

  Course: CMPS 1063 Data Structures, Fall 2019, Dr. Griffin

  Purpose: This program creates a list based queue to hold animals.

  Submission date: 10/15/2019.
 *********************************************************************
 * Contains code from Lecture 08.
 * Date: Oct 4th ish 2019
 *
 * List based queue
 *
 * Author: Terry Griffin
 * Date: Oct 4th ish 2019
 */
#include <iostream>
#include <fstream>
#include <string>
#include "ListQueue.h"

using namespace std;


int main() {
	


	ifstream fin("animals.txt");  // input file of animal info                   
	Animal *a;                    // animal pointer 
	               
    ListQueue LQ;         // Queue instance 

	string N = "";
	double W = 0.0;
	double S = 0.0;

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
		//cout << a->name << a->weight << a->scary;
		/*Calls the push function to push an animal onto the stack.*/
		LQ.Push(a);
	}


	LQ.Print();
}