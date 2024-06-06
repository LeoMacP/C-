#pragma once
#include <iostream>
#include <string>
#include "dollarAmount.h"


class Account
{
public:
	enum AccountType
	{
		chequing,
		saving
	};

	// constructor:
	Account(std::string accountholdername, DollarAmount& initialBalance, AccountType thetype) :
		name(accountholdername), balance(initialBalance), type(thetype)
	{
		std::cout << "Account(" << accountholdername << "," << initialBalance.toString() << ", " << thetype << std::endl;
	}

	// setters:
	void  setName(std::string thename)
	{
		name = thename;
	}
	// here for you to write setters for balance and type:

	void setBalance(DollarAmount newbalance)
	{
		balance = newbalance;
	}

	void setType(AccountType thetype)
	{
		type = thetype;
	}

	// getters:
	std::string getName() const
	{
		return name;
	}
	//  here provide the other 2 getters:
	DollarAmount getBalance() const
	{
		return balance;
	}

	AccountType getType() const
	{
		return type;
	}


	//deposit:
	DollarAmount deposit(DollarAmount depo)
	{
		balance.add(depo);
		return balance;
	}

	DollarAmount deposit(unsigned int dollar, unsigned int cents)
	{
		balance.add(dollar, cents);
		return balance;
	}

	//withdraw
	DollarAmount withdraw(DollarAmount with)
	{
		balance.subtract(with);
		return balance;
	}

	DollarAmount withdraw(unsigned int dollar, unsigned int cents)
	{
		balance.subtract(dollar, cents);
		return balance;
	}

	//TODO by students
	// computing interests
	DollarAmount ComputeInterest(int rate, int base)
	{
		// compute interest based on this formula:
		// interest = (balance.amount * rate + base/2) / base
		return DollarAmount{};
	}
	//TODO by students
	DollarAmount CompoundInterestYearly(int yearlyrate, int base, int years)
	{
		std::cout << "CompoundInterestYearly: to be done by students\n";
		// compounds interest yearly over the original balance.
		// You must use DollarAmount::AddInterest() method for implementing this and the 2 following methods.
		// Each year interest is added to the balance, so it can
		// be used for computing subsequent year interest.
		return DollarAmount{};
	}
	DollarAmount CompoundInterestMonthly(int yearlyrate, int base, int months)
	{
		std::cout << "CompoundInterestMonthly: to be done by students\n";
		// compounds interest monthly over the original balance.
		// pay attention that the rate is yearly. So for monthly
		// rate you have to do rate / 12 and use that.
		// Each month interest is added to the balance, so it can
		// be used for computing subsequent month interest.
		return DollarAmount{};
	}
	DollarAmount CompoundInterestDaily(int yearlyrate, int base, int days)
	{
		std::cout << "CompoundInterestDaily: to be done by students\n";
		// compounds interest daily over the original balance.
		// pay attention that the rate is yearly. So for daily
		// rate you have to do rate / 365 and use that.
		// Each day interest is added to the balance, so it can
		// be used for computing subsequent day interest.
		return DollarAmount{};
	}

	std::string toString() const
	{
		return name + ": " + balance.toString() + "\n";
	}

private:
	std::string name;    // this is account holders's full name
	DollarAmount balance;   // balance in this account
	AccountType type;
};