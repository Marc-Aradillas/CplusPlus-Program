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

//included hash directives
#ifndef INVESTMENT_DATA_H
#define INVESTMENT_DATA_H
//included libraries
#include <iostream>
#include <iomanip>
#include <string>
//included header file
#include "DisplayData.h"

using namespace std;

class InvestmentData 
{
public:
	// constructor
	InvestmentData();
	// mutators
	void SetinitialInvestmentAmount(double t_initialInvestment);
	void SetMonthlyDeposit(double t_monthlydeposit);
	void SetAnnualInterest(double t_interestRate);
	void SetnumberOfYears(int t_numYears);
	// accessors
	double GetinitialInvestmentAmount() const;
	double GetMonthlyDeposit() const;
	double GetAnnualInterest() const;
	int GetYears() const;
	// these accessors return calculated values without making changes to the private data members
	void RequestUserInput(double t_initialInvestment, double t_monthlyDeposit, double t_AnnualInterest, int t_numberOfYears);
	void TableWithoutDeposits(double t_initialInvestment, double t_AnnualInterest, int t_numberOfYears);
	void TableWithDeposits(double t_initialInvestment, double t_monthlyDeposit, double t_AnnualInterest, int t_numberOfYears);


	// monetary values are kept private for security:
private:
	double m_initialInvestmentAmount = 0;
	double m_monthlyDeposit = 0;
	double m_annualInterest = 0;
	int m_totYears = 0;
};
#endif
