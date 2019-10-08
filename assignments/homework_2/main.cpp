/*-----------------------------------------------------------------------------

Name: Cykelle Semper.

Course: CMPS 1063 Data Structures, Fall 2019, Dr. Griffin

Purpose: This program will create an array based stack which resizes
to 1.5 times it's previous size if it gets 80% full, reduces and
to half it's size if the stack gets to 20% full.

-----------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>



using namespace std;

/*
Created a struct in order to read in files appropriately. Plus structs are just awesome!
*/
struct Input {
	char identifier;
	int numbers;
	/*
	Created a constructor in order to initialize variables in struct,
	and also run whenever I declare an instance of my struct.
	*/
	Input() {
		identifier = '-'; // initializes identifier to '-'.
		numbers = 0; // initializes numbers to 0.
	}
};

class Stack {
private:
	int *A;         // container of items (could make it a list)
	int Top;        // keep track of top
	int Size;       // Arrays need a size
	int max;
public:
	/*
	   Stack constructor
	   Description: Initializes an array of ints and sets our top
	*/
	Stack() // Default constructor
	{

		Size = 10;
		A = new int[Size];
		Top = -1;
		max = 0;
	};

	/**
	* Push
	* Description:
	*    Adds item to top of stack
	* Params:
	*    int val : integer size
	* Returns:
	*     bool : true = success
	*/
	int Push(int val) // Pushes a value onto the stack.
	{
		

		if (!Full())
		{       /*
				CheckResize function is called to check if conditions are met for enlargement.
				*/
				checkResize();
	
				Top++;
				A[Top] = val;
		}
		
		
		return 0;
	}

	/**
	 * Pop
	 * Description:
	 *    Removes top of stack and returns it
	 * Params:
	 *    void
	 * Returns:
	 *     int : item on stack
	 */
	bool Pop() // Removes an item from the top of the stack.
	{
		if (!Empty()) {

			    /*
				CheckResize function is called to check if conditions are met for enlargement.
				*/
				checkResize();
			

			
			int temp = 0;
			temp = A[Top];
			Top--;


			return temp;

		}
		else {

			return false;
			
		}
		

	}

	/**
	 * Print
	 * Description:
	 *    Prints output.
	 * Params:
	 *    void
	 * Returns:
	 *     void
	 */
	void Print(ofstream & outfile) // Prints Output.
	{
		outfile << "Cykelle Semper \n";
		outfile << "Homework 2\n";
		outfile << "Tuesday, 8th 2019\n\n";

		outfile << endl << "The current stack size is: " << Top << endl;

		outfile << "\n";
		
		outfile << "The max size of the stack was: " << max << endl;

		outfile << endl << "The remaining items in the stack: ";
		for (int i = 0; i < Top; i++) {
			outfile << A[i] << "  ";
		}
		outfile << endl;

	}


	/**
	* Empty
	* Description:
	*    Is stack empty
	* Params:
	*    void
	* Returns:
	*    bool : true = empty
	*/
	bool Empty()// Is stack empty
	{
		return Top < 0;

	}

	/**
	 * Full
	 * Description:
	 *    Is stack full
	 * Params:
	 *    void
	 * Returns:
	 *    bool : true = full
	 */
	bool Full() // is stack full
	{
		return (Top == Size - 1);
	}


	/**
	 * Full
	 * Description:
	 *    Enlarges the Stack size by 1.5 once conditions are met.
	 * Params:
	 *    void
	 * Returns:
	 *    void
	 */
	void Enlarge()
	{
		
		int newSize = (Size * 1.5);
		int *NewA = new int[newSize];
		
		
		for (int i = 0; i < Size; i++)
		{

			NewA[i] = A[i];
			
		}

		if (Top > max)
		{
			max = Top;
		}

		int *Temp = A;
		A = NewA;
		Size = newSize;

		
		
		delete[] Temp;
	}

	/**
	 * Full
	 * Description:
	 *    Reduces the Stack size by 0.5 once conditions are met.
	 * Params:
	 *    void
	 * Returns:
	 *    void
	 */
	void Reduce()
	{

		int newSize = (Size * 0.5);
		int *NewA = new int[newSize];


		for (int i = 0; i < Size; i++)
		{

			NewA[i] = A[i];

		}

		int *Temp = A;
		A = NewA;
		Size = newSize;

		delete[] Temp;

	}

	/**
	 * Full
	 * Description:
	 *    Checks if conditions are met to either Enlarge or to 
	      Reduce the size of the stack.
	 * Params:
	 *    void
	 * Returns:
	 *    void
	 */
	void checkResize()
	{
		if (Top == (Size - 2))
		{
			Enlarge();

			if (Top == (Size * 0.2))
			{
				Reduce();
			}

		}
		
	}

};

int main()
{

	Input Input; // Declares struct variable to call struct.
	Stack DoStuff; // Creates a variable of stack to Call all functions in class.


	ifstream infile("input_data.txt");
	ofstream outfile("stack_out.txt");
	if (!infile) // Error message if file could not be opened
	{
		cerr << "Error: file could not be opened" << '\n';
		system("pause");
		exit(1);
	}

	// Loops till the end of file pointer is reached. 
	while (!infile.eof())
	{
		//Reading in the input file to push onto stack.
		while (infile >> Input.identifier >> Input.numbers)
		{
			//Created an if statement to ensure push conditions are met.
			if (Input.identifier == '+' && Input.numbers > 0)
			{
				/*
				These outfile statements were just used to test the output.
				outfile << Input.identifier;
				outfile << Input.numbers;
				*/

				// Function call to push all numbers with '+' onto stack.
				DoStuff.Push(Input.numbers);
			}

			if (Input.identifier == '-' && Input.numbers == 0)
			{
				
				DoStuff.Pop(); // Pops values with a character '-' and number 0.
			}


		}

	}

	DoStuff.Print(outfile);


	//outfile << endl << "The current stack size is: ";
	//DoStuff.checkResize();
	outfile.close();
}