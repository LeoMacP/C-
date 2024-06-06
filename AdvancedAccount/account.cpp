
#include <iostream>
#include "account.h"

Account::Account(std::string n, AccountType t) :owner(n), actype(t)
{
	std::cout << "Account created\n";
}

DollarAmount Account::deposit(DollarAmount val)
{
	auto cents = val.GetAmount();
	balance.add(0, cents);
	return balance;
}

DollarAmount Account::deposit(int dollar, int cents)
{
	DollarAmount val(dollar, cents);
	return deposit(val);
}

DollarAmount Account::withdraw(DollarAmount val)
{
	return DollarAmount();
}

DollarAmount Account::withdraw(int dollar, int cents)
{
	return DollarAmount();
}


