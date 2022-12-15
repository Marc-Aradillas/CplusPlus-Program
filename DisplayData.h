/*
 * Marc Aradillas
 * CS-210-H7634: Programming Languages
 * November 28, 2022
 * Project Two (Airgead Banking Application)
 * Develop Object-Oriented programming application using secure and efficient C++
 */

 /* references:
 * https://learn.microsoft.com/en-us/cpp/preprocessor/hash-define-directive-c-cpp?view=msvc-170
 */

#ifndef DISPLAY_DATA_H
#define DISPLAY_DATA_H
//included header file and string library
#include <string>
#include "InvestmentData.h"

using namespace std;

class DisplayData {
public:
	// constructor
	DisplayData();

	// accessors
	void displayMenu();
	void displayContinue();
};
#endif 