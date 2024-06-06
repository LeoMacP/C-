#pragma once

#include <iostream>
#include <string>
#include "DollarAmount.h"

// Definition of Account class
class Account
{
public:
	enum AccountType
	{
		NotSet = -1,
		chequing,
		saving,
		savingPlus,
	};

	// declaring default constructor to initialize balance
	Account(std::string, AccountType);
	~Account() {
		std::cout << "Account is being deleted.\n";
	}

	// method for depositing money in the account
	DollarAmount deposit(DollarAmount val);
	DollarAmount deposit(int dollar, int cents);

	// method for withdraw from the account
	DollarAmount withdraw(DollarAmount val);
	DollarAmount withdraw(int dollar, int cents);

	// getter method to get the balance
	DollarAmount getBalance() { return balance; }

	// getter for account type:
	AccountType getType() const
	{
		return actype;
	}

	std::string getTypeStr() const
	{
		std::string output{};
		if (actype == AccountType::chequing)
			output = "chequing";
		else if (actype == AccountType::saving)
			output = "saving";
		else if (actype == AccountType::savingPlus)
			output = "savingPlus";
		else
			output = "Warning: account type is not set properly";

		return output;
	}

	// getter for owner:
	std::string getOwner() const
	{
		return owner;
	}

	std::string toString() const
	{
		return "Owner: " + owner + ", type: " + getTypeStr() + ",balance:" + balance.toString();
	}

	DollarAmount ComputeInterest(int rate, int divisor)
	{
		// compute interest based on this formula:
		DollarAmount interest((balance.GetAmount() * rate + divisor / 2) / divisor);
		return interest;
	}

	DollarAmount CompoundInterestYearly(int rate, int divisor, int years)
	{
		std::cout << "CompoundInterestYearly: to be done by students\n";
		// compounds interest yearly over the original balance.
		// You must use DollarAmount::AddInterest() method for 
		// implementing this and the 2 following methods.
		// Each year interest is added to the balance, so it can
		// be used for computing subsequent year interest.
		DollarAmount{};
	}


	DollarAmount CompoundInterestMonthly(int rate, int divisor, int months)
	{
		std::cout << "CompoundInterestMonthly: to be done by students\n";
		// compounds interest monthly over the original balance.
		// pay attention that the rate is yearly. So for monthly
		// rate you have to do rate / 12 and use that.
		// Each month interest is added to the balance, so it can
		// be used for computing subsequent month interest.
		DollarAmount{};
	}

	DollarAmount CompoundInterestDaily(int rate, int divisor, int days)
	{
		std::cout << "CompoundInterestDaily: to be done by students\n";
		// compounds interest daily over the original balance.
		// pay attention that the rate is yearly. So for daily
		// rate you have to do rate / 365 and use that.
		// Each day interest is added to the balance, so it can
		// be used for computing subsequent day interest.
		return DollarAmount{};
	}


private:
	DollarAmount balance{};
	std::string owner{};
	AccountType actype{};

};
