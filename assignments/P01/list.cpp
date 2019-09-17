/**
 This program serves to write a list class that stores employee information, one per node.
 You will write list methods to perform some basic tasks.
 */


#include <iostream> // write to and read from stdin and stdout
#include <fstream> // read and write files
#include <string> // access string library

using namespace std; // Which namespace is being used.

string lower_string(string orig)
{
	string result = "";
	for (int i = 0; i < orig.size(); i++)
	{
		result += tolower(orig[i]);
	}
	return result;
}

bool string_match(string big, string small)
{
	int index = big.find(small);
	return index >= 0;
}

struct Employee {
	string emp_id;
	string first_name;
	string last_name;
	string gender;
	string email;
	double hourly_pay;
	Employee *Next;

	Employee() {
		emp_id = "";
		first_name = "";
		last_name = "";
		gender = "";
		email = "";
		hourly_pay = 0.0;
	}

	Employee(string id, string first, string last, string sex, string mail, double pay) {
		emp_id = id;
		first_name = first;
		last_name = last;
		gender = sex;
		email = mail;
		hourly_pay = pay;
	}
};

class LinkedList {
private:
	Employee* Head;

public:
	LinkedList() {
		Head = NULL;
	}


	/**
	 * Function: push
	 * Description:
	 *      Adds an employee to the front of the list
	 *
	 * Params:
	 *      Employee *Next
	 *
	 * Returns:
	 *      void
	 */
	void push(Employee *Next)
	{
		Employee *Temp = new Employee(*Head);
		Head = Temp;
	}

	/**
	 * Function: Delete Function
	 * Description:
	 *      Removes an item from anywhere in the list (you can base the delete off of any field.
	 If your find is based on email, this may be the easiest to use).
	 * Params:
	 *      string Key
	 *
	 * Returns:
	 *      Employee
	 */
	Employee del(string key)
	{
		Employee *Temp = Head;
		while (Temp->Next->email != key)
		{
			Temp = Temp->Next;
		}
		Employee *Temp_del = Temp->Next;
		Temp = Temp->Next->Next;
		delete Temp_del;
	}
	/**
	 * Function: Delete Function
	 * Description:
	 *      Removes an employee from the front of the list (does not have to return employee)
	 *
	 * Params:
	 *
	 * Returns:
	 *     returns a boolean true/false if an item is in the list
	 */
	Employee pop()
	{
		//Employee Result = Head->email;
		Employee *Temp_del = Head;
		Head = Head->Next;
		delete Temp_del;
		//return Result;
	}

	void frontSert(string id, string first, string last, string sex, string mail, double pay) {
		Employee* Temp = new Employee(id, first, last, sex, mail, pay);

		if (Head == NULL) {
			Head = Temp;
			Head->Next = NULL;
		}
		else {
			Temp->Next = Head;
			Head = Temp;
		}

	}

	/**
	 * Function: Print Fnction
	 * Description:
	 *      Prints first thirty employee Id's in list.
	 *
	 * Returns: Void.
	 *
	 */
	void printThirty(ofstream & outfile)
	{
		outfile << " Name: Cykelle Semper. \n";
		outfile << " Course: CMPS 1063 Data Structures, Fall 2019, Dr. Griffin.\n";
		outfile << " Purpose: This program serves to write a list class that \n";
		outfile << " stores employee information, one per node.  \n";
		outfile << " Functions, Structs, and Arrays of Structs. \n\n";
		outfile << "Employees \n";
		outfile << "=========================== \n";
		Employee* Temp = Head;

		outfile << "The first thirty employee id's are: \n\n";

		int i = 30;
		while (i != NULL)
		{
			if (Temp->Next) {
				//outfile << "->";
			}
			outfile << Temp->emp_id << '\n';
			Temp = Temp->Next;

			i--;
		}
	}
	/**
	 * Function: Find Function
	 * Description:
	 *      Returns a boolean true/false if an item is in the list
	 * Params: String email
	 *
	 * Returns: Bool (True or False)
	 *
	 */
	bool find(string email)
	{
		Employee *Temp = Head;
		while (Temp != NULL)
		{

			if (string_match(lower_string(Temp->email), lower_string(email)))
			{
				return true;
			}

			else
			{
				Temp = Temp->Next;
			}


		}
		return false;

	}

	void findall(string email, ofstream & out)
	{
		Employee *Temp = Head;

		while (Temp != NULL)
		{

			if (string_match(lower_string(Temp->email), lower_string(email)))
			{
				out << lower_string(Temp->email) << " \n";
			}

			Temp = Temp->Next;


		}


	}






};



int main() {

	LinkedList EmpList;

	string empid;
	string first;
	string last;
	string email;
	string gender;
	double pay;

	string line;
	string *tokens;
	ifstream fin("employees.txt");
	ofstream out("output.txt");



	if (!fin) // Error message if file could not be opened
	{
		cerr << "Error: file could not be opened" << '\n';
		system("pause");
		exit(1);
	}

	while (!fin.eof()) {

		fin >> empid >> first >> last >> email >> gender >> pay;

		//outfile<<empid<<", "<<first<<", "<<last<<", "<<email<<", "<<gender<<", "<<pay<<endl;

		EmpList.frontSert(empid, first, last, email, gender, pay);

	}


	EmpList.printThirty(out); // Prints first thirty from the bottom of the list go up. Due to FrontSert.
	out << "\nIf salon exists, print out a 1 for true or a 0 for false. \n";
	out << EmpList.find("salon");
	out << endl;
	out << EmpList.find("SIFUGBOUDGHUOSHDGUIOHSROIGHIOGBSIOG"); // Testing if program returns zero for no match.
	out << endl;
	out << "\n\nAll emails containing salon found in list: \n"; // Prints all emails with salon.
	EmpList.findall("salon", out);

	out.close();

	return 0;
}