/*
 * Marc Aradillas
 * CS-210-H7634: Programming Languages
 * November 28, 2022
 * Project Two (Airgead Banking Application)
 * Develop Object-Oriented programming application using secure and efficient C++
 */

/* references
*https://cplusplus.com/forum/beginner/188464/
*/

#include <iostream>
#include <string>
#include "DisplayData.h"

using namespace std;

// DisplayData class constructor
DisplayData::DisplayData() {}

// DisplayTemplate: Prints the programs required inputs.
void DisplayData::displayMenu() {
	// Print Display for user
	cout << "**********************************************************************" << endl;
	cout << "******                 Airgead Banking App                      ******" << endl;
	cout << "*************************** Data Input *******************************" << endl;
	cout << endl;
	cout << "Initital Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;
	cout << endl;	
	cout << "Welcome!" << endl << endl; //welcome message to user
	// system pause used to stand by for user response
	system("PAUSE");
}

void DisplayData::displayContinue() {
	// print statement to prompt user for new input
	cout << "Would you like to continue with new inputs,  Y/N?" << endl;
	cout << endl;
	// FIXME: Implement loop to request user for new inputs or else exit program

	// system pause used to stand by for user response
	system("PAUSE");
}