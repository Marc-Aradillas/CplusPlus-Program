/*
 * Marc Aradillas
 * CS-210-H7634: Programming Languages
 * November 28, 2022
 * Project Two (Airgead Banking Application)
 * Develop Object-Oriented programming application using secure and efficient C++
 */

//included libraries
#include <iostream>
#include <iomanip>
#include <string>
//included header files
#include "InvestmentData.h"
#include "DisplayData.h"

using namespace std;

int main() {

    // Instantiate objects from the classes created to store and compute user input:  
    InvestmentData userData;
    DisplayData displayData;

    // Initialize placeholder variables for user input:
    double initalInvestmentAmount = 0;
    double monthlyDepositAmount = 0;
    double annualInterestRate = 0;
    int totalYears = 0;

    // Display example for user:
    displayData.displayMenu();

    // Request User Input and store it privately:
    userData.RequestUserInput(initalInvestmentAmount, monthlyDepositAmount, annualInterestRate, totalYears);

    // Reset placeholders for user privacy:
    initalInvestmentAmount = 0;
    monthlyDepositAmount = 0;
    annualInterestRate = 0;
    totalYears = 0;

    // Display results for user (without additional monthly deposits):
    userData.TableWithoutDeposits(userData.GetinitialInvestmentAmount(),
        userData.GetAnnualInterest(), userData.GetYears());

    // Display results for user (with additional monthly deposits):
    userData.TableWithDeposits(userData.GetinitialInvestmentAmount(),
        userData.GetMonthlyDeposit(), userData.GetAnnualInterest(), userData.GetYears());

    //Display prompt for new input
    displayData.displayContinue();

    return 0;
}