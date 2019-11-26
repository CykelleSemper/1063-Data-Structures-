/*

 Author:           CYKELLE SEMPER
 Assignment:       Homework_05
 Date:             26 November 2019
 Title:            Program 4: Caeser Cipher Class 
 Semester:         Fall 2019
 Course:           CMPS 1063

 Files:            main.cpp
                   encrypted.txt(Input File)
                   decrypted.txt(Output File)
 Description:
	   Write a main driver function that shows the complete functionality
	   of your CaeserCipher class by opening a plaintext file and encrypting it,
	   then open an encrypted file and decrypting it.

*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Encryption {
	int Number_of_Messages;
	int ShiftValue;
	string Message;


	/*
	Created a constructor in order to initialize variables in struct,
	and also run whenever I declare an instance of my struct.
	*/
	Encryption() {
		Number_of_Messages = 0; // Initializes Number_of_Messages to zero.
		ShiftValue = 0;        // Initializes Shift Value to zero.
		Message = "";
	}
	
	
};

class CaeserCipher
{
 private:


 public: 

/**
*
*
* Description:
*           Encrypt's a string and returns the encrypted string.
*
* Params:
*           Shift Value
	        Message
*
*
* Returns:
*           string EncryptedResult
*/
	 string Encrypt(int ShiftValue, string Message)
	 {
		 string EncryptedResult = ""; // Variable to store Encrypted string.

		 // Traverse Message to be encrpted.
		 for (int i = 0; i < Message.length(); i++)
		 {
			 UpperCase(Message); // Uppercases the message.
			 // To Encrypt Uppercase letters in string.
			 if (isupper(Message[i])) // Checks to make sure it is uppercased. 
				 EncryptedResult += char(int(Message[i] + ShiftValue - 65) % 26 + 65);

			 // To Encrypt Lowercase letters in string.
			 else
				 EncryptedResult += char(int(Message[i] + ShiftValue - 97) % 26 + 97);
		 }

		 // Return the resulting string 
		 return EncryptedResult;
		
	 }


/**
*
*
* Description:
*           Decrypt's a string and returns the decrypted string.
*
* Params:
*           Shift Value
	        Message
*
*
* Returns:
*           string DecryptedResult
*/
	 string Decrypt(int ShiftValue, string Message)
	 {
		 string DecryptedResult = ""; // Variable to store Encrypted string.

		 // Traverse Message to be encrpted.
		 for (int i = 0; i < Message.length(); i++)
		 {
			 UpperCase(Message); // Uppercases ASCII values 'a' to 'z'.
			 // To Encrypt Uppercase letters in string.
			 
			 if (isupper(Message[i]))// Checks to make sure it is uppercased. 
				 DecryptedResult += char(int(Message[i] + (26 - ShiftValue) - 65) % 26 + 65);

			 // To Decrypt Lowercase letters in string.
			 else
				 DecryptedResult += char(int(Message[i] + (26 - ShiftValue) - 97) % 26 + 97);
		 }
		  
		 
		 // Return the resulting string 
		 return DecryptedResult;
	 }


/**
*
*
* Description:
*           Uppercases a string.
*
* Params:
*           Shift Value
	        Message
*
*
* Returns:
*           Uppercased string.
*/
	 string UpperCase(string Message)
	 {
		 int i = 0;

		 while (Message[i] != '\0')
		 {
			 if (Message[i] >= 'a' && Message[i] <= 'z') {
				 Message[i] = Message[i] - 32;
			 }
			 i++;
		 }
		 return Message;
	 }
/**
*
*
* Description:
*                Displays Menu 
                 Calls Encryption or Decryption functions 
*
* Params:
*                Shift Value
                 Message
*
*
* Returns:
*                void
*/
void Menu(int ShiftValue, string Message)
 { 
	/*

	int Choice = 0;
	int sentinel = -1;

	if (Choice != sentinel)
	{

		cout << "Choose one of the following options below: \n";
		cout << "----------------------------------------------";
		cout << "\n1. Encrypt";
		cout << "\n2. Decrypt \n";
		cout << "To quit the program, enter the value -1. \n";
		cin >> Choice;

		while (Choice <= -2)
		{
			// Displays an error message if any value lower than
			//the sentinel value is entered by the user.
			cout << "Error: Number entered is not an option. \n";
			cout << "Only enter numbers corresponding to option numbers. \n\n";
			cout << "Please select an option from the following menu. \n";

			cout << "Choose one of the following options below: \n";
			cout << "----------------------------------------------";
			cout << "\n1. Encrypt";
			cout << "\n2. Decrypt \n";
			cout << "To quit the program, enter the value -1. \n";
			cin >> Choice;
		}
		while (Choice >= 3)
		{
			// Displays an error message if any value hight than
			//the highest menu value is entered by the user.
			//The menu is then redisplayed and user promted for selection.
			cout << "Error: Number entered is not an option. \n";
			cout << "Only enter numbers corresponding to option numbers. \n\n";
			cout << "Please select an option from the following menu. \n";

			cout << "Choose one of the following options below: \n";
			cout << "----------------------------------------------";
			cout << "\n1. Encrypt";
			cout << "\n2. Decrypt \n";
			cout << "To quit the program, enter the value -1. \n";
			cin >> Choice;
		}

		// When sentinel value is entered, displays the following message.
		if (Choice == sentinel)
		{
			cout << "You decided to quit the program. \n";
			cout << "Have a good day! \n\n";
			//system("pause");
			//return 0;
		}
		else switch (Choice)
		{

		case 1:
			Encrypt(ShiftValue, Message);
			break;

		case 2:
		    Decrypt(ShiftValue, Message);
			break;
		}
	}*/

	
}



	 void SetShift()
	 {

	 }

	 void ReadCipherText()
	 {

	 }

	 void WriteCipherText()
	 {

	 }
	
	 void ReadPlainText()
	 {

	 }
/**
*
*
* Description:
*      Prints output and Results
*
* Params:
*      Result from Decryption Function
*
*
* Returns:
* void
*/
	 void WritePlainText(string Result)
	 {
		 ofstream outfile("decrypted.txt");

		 outfile << "Cykelle Semper \n";
		 outfile << "Program_04: Caesar Cipher\n";
		 outfile << "Tuesday, 26th 2019\n\n";

		 outfile << Result << endl << endl;
	 }
};

int main()
{
	CaeserCipher C;
	Encryption Input;

	ifstream infile("encrypted.txt");
	ofstream outfile("decrypted.txt");

	outfile << "Cykelle Semper \n";
	outfile << "Program_04: Caesar Cipher\n";
	outfile << "Tuesday, 26th 2019\n\n";


	if (!infile) // Error message if file could not be opened
	{
		cerr << "Error: file could not be opened" << '\n';
		system("pause");
		exit(1);
	}

	infile >> Input.Number_of_Messages; // Gets the number of messages to be read in from file.
	
	while (!infile.eof())
	{
			infile >> Input.ShiftValue;
			

			infile.ignore(100, '\n'); // Ignores new line.
			getline(infile, Input.Message);

			string Result = C.Decrypt(Input.ShiftValue, Input.Message);
				
			outfile << Result << endl;
			
			/*
			The Menu works, however, If I pass in the shiftvalue and message from inside this loop
			it will only Decrypt the first Message. Same as with the Print function. to make things easier, 
			I'll just send the result to outputfile from main. 
			*/
			//C.Menu(Input.ShiftValue, Input.Message);
			
		
	}
	
	
	
	infile.close();

	system("pause");
	return 0;
}
