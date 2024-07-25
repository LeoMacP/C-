#pragma once
#include <iostream>
#include "BaseEmployee.h"
#include <sstream>

// add support to keep track of number of CommissionEmployee
class CommissionEmployee : virtual public BaseEmployee
{
public:
	CommissionEmployee(std::string first = {},
		std::string last = {},
		std::string sin = {},
		double rate={ 0.10 }) :
		BaseEmployee(first, last, sin),
		commisionRate(rate),
		grossSale(0.)
	{
	//	std::cout << "CommissionEmployee created:" <<
	//	"Commission=" << commisionRate << std::endl;
	}

	~CommissionEmployee()
	{
		std::cout << "~CommissionEmployee.\n";
	}

	void setGrossSale(double sale)
	{
		grossSale = sale;
	}
	double getGrossSale() const
	{
		return grossSale;
	}
	void setcommisionRate(double sale)
	{
		commisionRate = sale;
	}
	double getcommisionRate() const
	{
		return commisionRate;
	}	
	
	virtual double earning() const override
	{
		return grossSale * commisionRate;
	}

private:
	double grossSale;
	double commisionRate;
// add friend operator<< and friend operator>> overrides bellow:

	friend std::ostream& operator<<(std::ostream& os, const CommissionEmployee& emp){

		os << static_cast<const BaseEmployee&>(emp)
			<< "Gross Sale: " << emp.grossSale << "\n"
			<< "Commission Rate: " << emp.commisionRate << "\n";
		return os;
	}		

	friend std::istream& operator>>(std::istream& is, CommissionEmployee& emp)
	{
		is >> static_cast<BaseEmployee&>(emp);
		is >> emp.grossSale;
		std::cout << "Enter Commission Rate: ";
		is >> emp.commisionRate;
		return is;
	}

};
