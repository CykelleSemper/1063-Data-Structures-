/*

 Author:           CYKELLE SEMPER
 Assignment:       Program_03
 Date:             14 November 2019
 Title:            Program_03: Arbitrary Precision Math
 Semester:         Fall 2019
 Course:           CMPS 1063

 Files:            apm.cpp
				   input_data.txt(Input File)
				   output.txt(Output File)
 Description:
	   Write a program that uses a doubly linked list that
	   will have the ability to add, subtract, and multiply
	   two arbitrarily long integers positive integers.

*/

#include <iostream>
#include <string>
#include <fstream>
//#include <sstream> 
#include <vector>

using namespace std;

struct Input {
	char Operator;
	string _1stNumber;
	string _2ndNumber;
	int NumProblems;
	/*
	Created a constructor in order to initialize variables in struct,
	and also run whenever I declare an instance of my struct.
	*/
	Input() {
		Operator = '-'; // initializes identifier to '-'.
		_1stNumber = " "; // initializes numbers to " ".
		_2ndNumber = " "; // initializes numbers to " ".
		NumProblems = 0;   // initializes NumProblems to zero.
	}
};

struct Node {
	string Data; 
	Node* Next;
	Node* Prev;
	string Answer;


	Node(string d) {
		Data = d;
		Next = NULL;
		Prev = NULL;
		Answer = "";

	}
};



class List {

private:
	Node *Head;
	Node *Tail;


public:

	List() {
		Head = NULL;
		Tail = NULL;
	}

	void HeadSert(string Data) {
		Node*Temp = new Node(Data);
		Temp->Next = Head;
		Head = Temp;
	}
	/**
	 *
	 *
	 * Description:
	 *      Inserts strings into a Linked List
	 *
	 * Params:
	 *      string val1 : A string representation of an integer number.
	 *      string val2 : A string representation of an integer number.
	 *
	 * Returns:
	 *      string : list of string type
	 */
	string InsertNumbersL1(string Data) {
		Node* List_1 = new Node(Data);

		List_1->Next = Head;
		List_1->Prev = NULL;
		if (Head != NULL)
		{
			Head = List_1;
		}


		return List_1->Data;

	}

	string InsertNumbersL2(string Data) {
		Node* List_2 = new Node(Data);

		List_2->Next = Head;
		List_2->Prev = NULL;
		if (Head != NULL)
		{
			Head = List_2;
		}




		return List_2->Data;
	}


	/**
	 *
	 *
	 * Description:
	 *      Adds two doubly linked lists together.
	 *
	 * Params:
	 *      string val1 : A string representation of an integer number.
	 *      string val2 : A string representation of an integer number.
	 *
	 * Returns:
	 *      string : a list with addition results
	 */
	string Add(string List_1, string List_2)
	{
		/*Checks list sizes to figure which is smaller before computation.*/
		if (List_1.length() > List_2.length())
			swap(List_1, List_2);

		// Created an empty string for storing result .
		string Result = "";

		// Calculate lengths of both strings. 
		int n1 = List_1.length(), n2 = List_2.length();

		// Reverse both of strings. 
		reverse(List_1.begin(), List_1.end());
		reverse(List_2.begin(), List_2.end());

		int Carry = 0; // Calculate lengths of both strings. 

		for (int i = 0; i < n1; i++)
		{
			int Sum = ((List_1[i] - '0') + (List_2[i] - '0') + Carry);
			Result.push_back(Sum % 10 + '0');

			// Calculate carry for next step 
			Carry = Sum / 10;
		}

		// Add remaining digits of larger number 
		for (int i = n1; i < n2; i++)
		{
			int Sum = ((List_2[i] - '0') + Carry);
			Result.push_back(Sum % 10 + '0');
			Carry = Sum / 10;
		}

		// Add remaining carry 
		if (Carry)
			Result.push_back(Carry + '0');

		// reverse resultant string 
		reverse(Result.begin(), Result.end());

		Node* NewList = new Node(Result);// Creates new list and stores Answer.

		NewList->Next = Head;
		NewList->Prev = NULL;
		if (Head != NULL)
		{
			Head = NewList;
		}
		return NewList->Data; // Returns New list of computed value.
	}

	bool isSmaller(string List_1, string List_2)
	{
		// Calculate lengths of both string 
		int n1 = List_1.length(), n2 = List_2.length();

		if (n1 < n2)
			return true;
		if (n2 < n1)
			return false;

		for (int i = 0; i < n1; i++)
			if (List_1[i] < List_2[i])
				return true;
			else if (List_1[i] > List_2[i])
				return false;

		return false;
	}

	/**
	 *
	 *
	 * Description:
	 *      Subtracts two doubly linked lists.
	 *
	 * Params:
	 *      string val1 : A string representation of an integer number.
	 *      string val2 : A string representation of an integer number.
	 *
	 * Returns:
	 *      string : a list with subtraction results
	 */
	string Sub(string List_1, string List_2)
	{

		/*Checks list sizes to figure which is smaller before computation.*/
		if (isSmaller(List_1, List_2))
			swap(List_1, List_2);

		// Created an empty string for storing result .
		string Result = "";

		// Calculate lengths of both strings. 
		int n1 = List_1.length(), n2 = List_2.length();

		// Reverse both of strings 
		reverse(List_1.begin(), List_1.end());
		reverse(List_2.begin(), List_2.end());

		int Carry = 0;

		// Run loop till small string length 
		// and subtract digit of List_1 to List_2 
		for (int i = 0; i < n2; i++)
		{
			//Difference Computation.

			int Sub = ((List_1[i] - '0') - (List_2[i] - '0') - Carry);

			/*If subtraction is less then zero 
			we add, and then add 10 into sub and 
			take carry as 1. */
			if (Sub < 0)
			{
				Sub += 10;
				Carry = 1;
			}
			else
				Carry = 0;

			Result.push_back(Sub + '0');
		}

		// Remaining digits are subtracted.
		for (int i = n2; i < n1; i++)
		{
			int Sub = ((List_1[i] - '0') - Carry);

			// if the sub value is less than zero, 10 is added to it's value. 
			if (Sub < 0)
			{
				Sub += 10;
				Carry = 1;
			}
			else
				Carry = 0;

			Result.push_back(Sub + '0');
		}

		// Resultant string is reversed. 
		reverse(Result.begin(), Result.end());

		Node* NewList = new Node(Result);// Creates new list and stores Answer.

		NewList->Next = Head;
		NewList->Prev = NULL;
		if (Head != NULL)
		{
			Head = NewList;
		}

		return NewList->Data; //Returns New list of computed value.

	}


	 /**
	  *
	  *
	  * Description:
	  *      Multiplies two doubly linked lists.
	  *
	  * Params:
	  *      string val1 : A string representation of an integer number.
	  *      string val2 : A string representation of an integer number.
	  *
	  * Returns:
	  *      string : a list with multiplication results
	  */
	string Mul(string List_1, string List_2)
	{
		/*Calculate lengths of both strings. 
		and stores them in a variable of type int. */
		int List1 = List_1.size();
		int List2 = List_2.size();

		if (List1 == 0 || List2 == 0)
			return 0;

		// Creates a Result variable of vector <int>.
		vector<int> Result(List1 + List2);

		//Indexes created to find results in vector. 
		int index_1 = 0;
		int index_2 = 0;
		for (int i = List1 - 1; i >= 0; i--)
		{
			int Carry = 0;
			int L1 = List_1[i] - '0';

			index_2 = 0;
			for (int j = List2 - 1; j >= 0; j--)
			{

				int L2 = List_2[j] - '0';

				// Stores product of Multiplication in Sum.
				int Sum = L1 * L2 + Result[index_1 + index_2] + Carry;

				Carry = Sum / 10;

				Result[index_1 + index_2] = Sum % 10;

				index_2++;
			}

			if (Carry > 0)
				Result[index_1 + index_2] += Carry;
			index_1++;
		}

		int i = Result.size() - 1;
		while (i >= 0 && Result[i] == 0)
			i--;

		//If all zeros are results, then either all or one of the numbers were 0.
		if (i == -1)
			return 0;

		string Answer = ""; // Created an empty string for storing result .

		while (i >= 0)
			Answer += std::to_string(Result[i--]);

		Node* NewList = new Node(Answer); // Creates new list and stores Answer.

		NewList->Next = Head;
		NewList->Prev = NULL;
		if (Head != NULL)
		{
			Head = NewList;
		}
		return NewList->Data;//Returns New list of computed value.

	}

	/**
 *
 *
 * Description:
 *      Prints Output
 *
 * Params:
 *      ofstream variable for printing to file
		Answer
 *
 *
 * Returns:
 *      void : 
 */
	void PrintResult(ostream &outfile, string Answer)
	{
		//outfile.open("output.text");

		Node* Temp = Head;

		while (Temp != NULL) {
			outfile << Temp->Data;
			//cout << Temp->Data;
			Temp = Temp->Next;
		}

		outfile << endl;

	}

};





int main()
{
	/*Declares struct variable to call struct This struct was created
	and used to read in list from file. */
	Input Input; 

	/*Not Necessary, but I created different List Variables for each
	computation. L = General Function calls, LS = Calls Sub, LM = Calls Mul, LA = calls Add. */
	List L; 
	List LS;
	List LM;
	List LA;
	
	/*Declaration of ifstream and ofstream variables.*/
	ifstream infile("input_data.txt");
	ofstream outfile("output.txt");

	/*Also not necessary, but I like elaborate code.
	Variables created to strore each result. */
	string Result_Add, Result_Sub, Result_Mul;
	
	outfile << "Cykelle Semper \n";
	outfile << "Program_03: Arbitrary Precision Math\n";
	outfile << "Thursday, 14th 2019\n\n";

	if (!infile) // Error message if file could not be opened
	{
		cerr << "Error: file could not be opened" << '\n';
		system("pause");
		exit(1);
	}

	// Not used, but this was to read in number of problems in file. 
	infile >> Input.NumProblems;
	
	// Loops till the end of file pointer is reached. 
	while (!infile.eof())
	{
		//Reading in the input file.

		infile >> Input.Operator >> Input._1stNumber >> Input._2ndNumber;
		/*Using a switch statement, the various functions are 
		called according to the operator found in file.*/
		switch (Input.Operator)
		{

		case '-':
			outfile << "\nOperation: Subtraction \n";
			Result_Sub = L.Sub(L.InsertNumbersL1(Input._1stNumber), L.InsertNumbersL2(Input._2ndNumber));
			LS.HeadSert(Result_Sub);
			LS.PrintResult(outfile, Result_Sub);
			break;

		case '+':
			outfile << "\nOperation: Addition \n";
			Result_Add = L.Add(L.InsertNumbersL1(Input._1stNumber), L.InsertNumbersL2(Input._2ndNumber));
		    LA.HeadSert(Result_Add);
			LA.PrintResult(outfile, Result_Add);
			break;

		case '*':
			outfile << "\nOperation: Multiplication\n";
			Result_Mul = L.Mul(L.InsertNumbersL1(Input._1stNumber), L.InsertNumbersL2(Input._2ndNumber));
			LM.HeadSert(Result_Mul);
			LM.PrintResult(outfile, Result_Mul);
			break;
		}
	}
	
	infile.close(); // closes input file.
	outfile.close(); // closes output file.
}
