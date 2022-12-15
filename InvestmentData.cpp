/*
 * Marc Aradillas
 * CS-210-H7634: Programming Languages
 * November 28, 2022
 * Project Two (Airgead Banking Application)
 * Develop Object-Oriented programming application using secure and efficient C++
 */

 /* references:
  * https://cplusplus.com/reference/istream/istream/ignore/
  * https://en.cppreference.com/w/cpp/types/numeric_limits
  * https://www.geeksforgeeks.org/stdsetbase-stdsetw-stdsetfill-in-cpp/
  * https://www.geeksforgeeks.org/stdto_string-in-cpp/
  * https://cplusplus.com/reference/ios/ios/clear/
  * https://en.cppreference.com/w/cpp/io/ios_base
  * zybooks online material
 */

//included header to access class 
#include "InvestmentData.h"

using namespace std;


// consructor
InvestmentData::InvestmentData() {}


// InvestmentData class setters (mutators)

    // Intital investment amount from user input
void InvestmentData::SetinitialInvestmentAmount(double t_initialInvestment) {
    m_initialInvestmentAmount = t_initialInvestment;
}

    // Recurring monthly deposit calculation
void InvestmentData::SetMonthlyDeposit(double t_monthlyDeposit) {
    m_monthlyDeposit = t_monthlyDeposit;
}
void InvestmentData::SetAnnualInterest(double t_interestRate) {
    m_annualInterest = t_interestRate;
}

    // The total number of years the amount is caluclated to compound
void InvestmentData::SetnumberOfYears(int t_numYears) {
    m_totYears = t_numYears;
}


// InvestmentData class getters (accesors)

    // Returns intial investment amount
double InvestmentData::GetinitialInvestmentAmount() const {
    return m_initialInvestmentAmount;
}

    // Returns the monthly deposit calculation
double InvestmentData::GetMonthlyDeposit() const {
    return m_monthlyDeposit;
}

    // Returns annual interest rate return
double InvestmentData::GetAnnualInterest() const {
    return m_annualInterest;
}

    // Returns number of years set for account maturity
int InvestmentData::GetYears() const {
    return m_totYears;
}


    // User input 
void InvestmentData::RequestUserInput(double t_initialInvestment, double t_monthlyDeposit,
    double t_AnnualInterest, int t_numberOfYears) {


    // Print header:
    cout << "**********************************************************************" << endl;
    cout << "*************************** Data Input *******************************" << endl;
    // Prompt user:
    cout << "Initial Investment Amount: $";


    // Get input using while loop to validate data:
    while (!(cin >> t_initialInvestment) || t_initialInvestment < 0.00) {
        cout << "Invalid entry, Please enter a valid deposit amount: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Set private data member: 
    InvestmentData::SetinitialInvestmentAmount(t_initialInvestment);

    // Prompt user
    cout << "Monthly Deposit: $";

    // Get input using while loop to validate data:
    while (!(cin >> t_monthlyDeposit) || t_monthlyDeposit < 0.00) {
        cout << "Invalid entry, Please enter a valid deposit amount: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    // Set private data member:
    InvestmentData::SetMonthlyDeposit(t_monthlyDeposit);

    // Prompt user
    cout << "Annual Interest: %";

    // Get input using while loop to validate data:
    while (!(cin >> t_AnnualInterest)) {
        cout << "Invalid entry, Please enter numbers only: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    // Set private data member:
    InvestmentData::SetAnnualInterest(t_AnnualInterest);

    // Prompt user
    cout << "Number of years: ";

    // Get input using while loop to validate data:
    while (!(cin >> t_numberOfYears) || t_numberOfYears < 1) {
        cout << "Invalid entry, Please enter positive numbers only: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    // Set private data member:
    InvestmentData::SetnumberOfYears(t_numberOfYears);

    // Clear the buffer stream:
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl << endl;
}


// displays the total balances on table without additional monthly deposits
void InvestmentData
::TableWithoutDeposits(double t_initialInvestment,
    double t_AnnualInterest, int t_numberOfYears) {

    // total balance amount 
    double totalBal = t_initialInvestment;

    // prints the total balances on table without additional monthly deposits
    cout << "        Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "===========================================================================" << endl;
    cout << "   Year " << setw(25) << "Year End Balance " << setw(35) << "Year End Earned Interest" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    // Main loop to calculate the total earnings of the investment every year
    for (int i = 0; i < t_numberOfYears; ++i) {

        // stores the total interest earned for the individual year
        double yearlyEarnings = 0;

        // stores the total monthly interest earnings for each month
        double monthlyEarnings;

        // Nested loop to compound the total balance value each month 
        for (int j = 0; j < 12; ++j) {

            // monthly interest earned
            monthlyEarnings = (totalBal) * ((t_AnnualInterest / 100) / 12);

            // Add the current month's earnings to the current year's earnings:
            yearlyEarnings = yearlyEarnings + monthlyEarnings;

            // Compound the running total balance value:
            totalBal = totalBal + monthlyEarnings;
        }
        // Populate current table row with investment data:
        cout << setprecision(2) << fixed << setw(6) << (i + 1);
        cout << setw(30 - to_string(totalBal).size()) << " " << right;
        cout << setw(1) << "$" << right;
        cout << setw(10 - to_string(totalBal).size()) << totalBal << right;
        cout << setw(39 - to_string(yearlyEarnings).size()) << " " << right;
        cout << setw(1) << "$" << right;
        cout << setw(2 - to_string(yearlyEarnings).size()) << yearlyEarnings << right;
        cout << endl << endl;
    }
    cout << endl << endl;
}

// takes data to calculate future investment and returns with monthly deposits then prints the information.
void InvestmentData::TableWithDeposits(double t_initialInvestment, double t_monthlyDeposit,
    double t_AnnualInterest, int t_numberOfYears) {

    // total balance amount compounded
    double totalBal = t_initialInvestment;

    // prints the total balances on table with additional monthly deposits
    cout << "        Balance and Interest With Additional Monthly Deposits" << endl;
    cout << "===========================================================================" << endl;
    cout << "   Year " << setw(25) << "Year End Balance " << setw(35) << "Year End Earned Interest" << endl;
    cout << "---------------------------------------------------------------------------" << endl;

    // Main loop to calculate the total earnings of the investment every year
    for (int i = 0; i < t_numberOfYears; ++i) {

        // stores the total interest earned for the individual year
        double yearlyEarnings = 0;

        // stores the total monthly interest earnings for each month
        double monthlyEarnings;

        // Nested loop to compound the total balance value each month
        for (int j = 0; j < 12; ++j) {

            // monthly interest earned
            monthlyEarnings = (totalBal + t_monthlyDeposit) * ((t_AnnualInterest / 100) / 12);

            // Add the current month's earnings to the current year's earnings
            yearlyEarnings = yearlyEarnings + monthlyEarnings;

            // Compound the running total balance value (including the monthly deposit)
            totalBal = totalBal + t_monthlyDeposit + monthlyEarnings;
        }
        // Populate current table row with investment data:        
        cout << setprecision(2) << fixed << setw(6) << (i + 1);
        cout << setw(30 - to_string(totalBal).size()) << " " << right;
        cout << setw(1) << "$" << right;
        cout << setw(10 - to_string(totalBal).size()) << totalBal << right;
        cout << setw(39 - to_string(yearlyEarnings).size()) << " " << right;
        cout << setw(1) << "$" << right;
        cout << setw(2 - to_string(yearlyEarnings).size()) << yearlyEarnings << right;
        cout << endl << endl;
    }
    cout << endl;
}