
#include <iostream>

#include "DollarAmount.h"
#include "account.h"

using namespace std;

int main()
{
	DollarAmount amount1(124, 30);
	DollarAmount amount2(25, 10);

	cout << amount1.toString() << endl;
	cout << amount2.toString() << endl;

	// testing add method in DollarAmount
	amount1.add(amount2);
	cout << "amount1: "<<amount1.toString() << endl;

	auto amount3 = amount1; // create a reference to amount1.
	amount3.add(amount2);
	cout << "amount1: " << amount1;
	cout << "amount3: " << amount3;

	DollarAmount amount4 = amount1 + amount3;
	cout << "amount4: " << amount4;

	DollarAmount amount5 = amount4 - amount2;
	cout << "amount5: " << amount5;

	//DollarAmount amount6 = amount2 - amount4;
	//cout << "amount6: " << amount6.toString() << endl;

	cout << amount5 <<" that is it";


	// test Account class
	Account janeAccount("Jane Doe", Account::AccountType::chequing);
	janeAccount.deposit(100, 25);

	auto theBalance = janeAccount.getBalance();
	cout << theBalance << endl;

	// how to compound interest:
	int initialDeposit = 2345;  // in dollar
	float rate = 2.45;  // interest rate for yearly

	// 1- let's accummulate interest for 10 years:
	// (1.0 + 2.45/100.) * initialDeposit  --> this is your total amount after 1 year
	// for year 2: (1.0 + 2.45/100.) * (1.0 + 2.45/100.) * initialDeposit
	// for year n: (1.0 + 2.45/100.)^n * initialDeposit
	Account savingAccount("Reza Nezami", Account::AccountType::saving); // creating an account
	savingAccount.deposit(2345, 0);   // depositing $2345.00 in it.

	auto interest = savingAccount.ComputeInterest(245, 100);
	cout << "Interest for saving account is: " << interest.toString() << endl;

	return 0;

}