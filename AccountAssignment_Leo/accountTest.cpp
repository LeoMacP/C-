
#include <iostream>
#include <string>
#include "account.h"


using namespace std;

int main()
{
	std::cout << "Create 3 accounts and print them using account's toString() method:\n";
	// 1- create 3 accounts for 3 people as following:
		// 1- Name=Jane Doe, amount = $2500, type = Checking
		// 2- Name=Jane Doe, amount =  $2500,  type = Saving
		// 3- Name = Ali Barooti, amount =  $2500, type = Checking

	std::cout << "\nCompare interest accumulation yearly, monthly and daily styles:\n";
	// In the following we want to compare interest accumulation yearly vs monthly vs daily for the same amount:
	// 2- Add interest as following: 
		// 1- For Jane's checking account: call CompoundInterestYearly. yearly Interest rate 2.45%, for 10 years, 
				// Then print Jane checking account using toString() method in Account class
		// 2- For Jane's saving account: call CompoundInterestMonthly. yearly Interest rate 2.45%, for 10 years, 
				// Then print Jane saving account using toString() method in Account class
		// 1- For Ali's checking account: call CompoundInterestDaily. yearly Interest rate 2.45%, for 10 years, 
				// Then print Ali account using toString() method in Account class

	std::cout << "\nTransfer $550.65 from Jane's saving account to her checking account:\n";
	// In the following we practice transferring money from one account to another:
	// 3- Withdraw $550.65 from Jane's saving account and deposit in her checking account. 
	//		You must use account's methods withdraw(dollar, cents) and deposit(dollar, cents)
			//Finally  print the 2 accounts after the transfer

	
	
	return 0;
}

