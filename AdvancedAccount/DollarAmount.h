#pragma once
#include <cstdint>
#include <string>
#include <sstream>
#include <iostream>

class DollarAmount
{
public:
	DollarAmount operator+(DollarAmount& rhs)
	{
		int64_t newcents = amount + rhs.GetAmount();
		DollarAmount ret(0, newcents);
		return ret;
	}
	DollarAmount operator-(DollarAmount& rhs)
	{
		int64_t newcents = amount - rhs.GetAmount();
		DollarAmount ret(0, newcents);
		return ret;
	}

	friend std::ostream& operator<<(std::ostream& os, DollarAmount& rhs)
	{
		os << rhs.toString() << std::endl;
		return os;
	}

private:
	int64_t amount;    //  keeping balance in cents

public:
	//default constructor:
	DollarAmount() : amount(0) {}

	// copy constructor
	DollarAmount(const DollarAmount& rhs)
	{
		amount = rhs.amount;
	}

	DollarAmount(int dollar, int cents) :
		amount(dollar * 100 + cents)
	{
	}

	// constructor for creating  DollarAmount using cents only
	DollarAmount(int64_t val): amount(val)
	{
	}

	// getter for amount
	int64_t GetAmount() const
	{
		return amount;
	}

	void add(DollarAmount depo)
	{
		amount += depo.GetAmount();
	}

	void add(int dollar, int cents)
	{
		DollarAmount deposit(dollar, cents);
		add(deposit);
	}

	void subtract(DollarAmount amnt)
	{
		amount -= amnt.GetAmount();
	}

	void subtract(int dollar, int cents)
	{
		DollarAmount da(dollar, cents);
		subtract(da);
	}

	std::string toString() const
	{
		int64_t dollar{ amount / 100 };
		int64_t cents{ amount % 100 };
		std::stringstream ss;
		ss << "Dollar:" << dollar << ", Cents:" << cents;
		return ss.str();
	}

	/*add interest using rate. It means for example for rate of 2.345 % we
	should call addInterest(2345, 1000)*/
	void addInterest(int rate, int divisor)
	{
		//first compute the interest.
		DollarAmount interest((amount * rate + divisor / 2) / divisor);
		add(interest);
	}


};
