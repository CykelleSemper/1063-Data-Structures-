/**
 * This program is a review of some 1043 (CS 1) topics.
 *
 * Functions
 * Structs
 * Arrays of Structs
 *
 */
#include <iostream> // write to and read from stdin and stdout
#include <ctime>    // access system clock (we used for rand function)
#include <string>   //
#include <sstream>
#include <fstream> // read a write files
#include<iomanip>

#define SIZE 10 // gives us a CONSTANT to use anywhere in our program \
                // we capitalize constants so we know they are not variables!

using namespace std; // so we don't have to put std:: in front of cin, cout.


/**
 * Structs are like creating your own data type.
 * We can use this struct to represent a student and thier grades.
 *
 * Remember, to declare a variable we use the following:
 *
 *      int x;
 *
 * To use our new struct we do the same:
 *
 *      Student S;
 *
 * Then we can load it with data like:
 *
 *      S.fname = 'Susan';
 *      S.lname = 'Sarandon';
 *      S.numGrades = 1;
 *      S.grades[0] = 88;
 *
 */
struct Student
{
	string fname;//First Name and Last name seem to be attached to each other
	string lname;//Printing fname from function also prints lname.
	int numGrades;//Printing lname also prints all the grades in file!!!
	int grades[10]; // There seemes to be an issue reading in the grades
	//from the file given. It wont store grades, also prints random 
	//negative values. Original code doesnt run, gives error. 
	
}; // REMEMBER TO TRY AND FIGURE THIS OUT LATER!


/**
 * Function: loadClassList
 * Description:
 *      Reads a file with student data, and loads it into an array of Students.
 *
 * Params:
 *      Student *classlist  : array of Students
 *      string  filename    : name of file to process
 *
 * Returns:
 *      int - number of students read in.
 */

ofstream outfile;
int loadClassList(Student *classList, string fileName)
{
	ifstream infile;       // get a stream variable
	infile.open("input_data.txt"); // open the stream using our fileName param
	int i = 0;          // index (counter)

	if (!infile) // Error message if file could not be opened
	{
		cerr << "Error: file could not be opened" << '\n';
		system("pause");
		exit(1);
	}
	while (!infile.eof())// Loops until the end of file pointer is reached.
	{
		
		getline(infile, classList[i].fname);
		getline(infile, classList[i].lname);
		//getline(infile, classList[i].numGrades); Unable to read in numGrades.

		// Read one line in the file into one struct at array location `i`
		// increment `i`
		i++;
	}

	

	// return sudent count
	return i;

}

/**
 * Function: printClassList
 *
 * Description:
 *      Prints an array of students to stdout
 *
 * Params:
 *
 *      Student *classList : array of structs (and the structs are `Students`)
 *      int     classSize  : size of class (returned from `loadClassList` )
 *
 * Returns:
 *
 *      void
 */
void printClassList(Student *classList, int classSize)
{
	ofstream outfile;
	outfile.open("student_output.txt");
	outfile << " Name: Cykelle Semper. \n";
	outfile << " Course: CMPS 1063 Data Structures, Fall 2019, Dr. Griffin.\n";
	outfile << " Purpose: This program is a review of CMPS 1044 Topics, \n";
	outfile << " Functions, Structs, and Arrays of Structs. \n\n";
	outfile << "Students \n";
	outfile << "=========================== \n";

	for (int i = 0; i < classSize; i++)
	{
		outfile << classList[i].fname << ": \n"
			//<< classList[i].numGrades 
		     << classList[i].lname << "   \n\n";

	}
	/* If I cout first name, it also prints the last name along with the first name. If I cout
	last name, it prints out the grades instead. I have been trying to figure this out since Friday 30th
	August, 2019, and have been unable to come to a solution. I have rewritten the program, 
	reused the struct given, altered the functions to process and output the required data,
	and ended up with the same result.  */

	outfile << "The list above displays how many grades the student has, \n";
	outfile << "followed by the grades of the student. \n\n";
}


/**
 * Function: main
 *
 * Description:
 *      Drives this example of structs and arrays
 */
int main()
{

	int A[SIZE];        // Array to hold students read from file
	Student classList[100];
	int classSize = 0;

	// Call the loadClassList function to open a file and load an array
	// of `Student` structs.
	classSize = loadClassList(classList, "input_data.txt");

	// Function returned how many lines (students) read in, lets print it.

	//outfile << "Class Size: " << classSize << endl;

	// Function to print out an array of students in a formatted way.
	printClassList(classList, classSize);


	return 0;
}