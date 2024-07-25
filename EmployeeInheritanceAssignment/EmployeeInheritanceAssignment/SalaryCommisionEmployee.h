#pragma once

#include <string>
#include <sstream>
#include "SalaryEmployee.h"
#include "CommissionEmployee.h"
#include <cmath>

class SalaryCommissionEmployee : public SalaryEmployee, public CommissionEmployee
{
public:
	SalaryCommissionEmployee(std::string first = {},
		std::string last = {},
		std::string sin = {}, double pay = { 35000. }, double rate = { 0.10 }) :
		BaseEmployee(first, last, sin),
		SalaryEmployee(first, last, sin, static_cast<int>(std::round(pay))),
		CommissionEmployee(first, last, sin, rate)
	{
		setSalary(pay);
		setcommisionRate(rate);
		++sNumSalCommEmp;
	}

	~SalaryCommissionEmployee() 
	{
		--sNumSalCommEmp;
		std::cout << "salarycommission employee deleted";
	}

	virtual double earning() const override
	{
		return SalaryEmployee::earning() + CommissionEmployee::earning();
	}

	virtual std::string to_string() const override
	{	
		return "SalaryCommisionEmployee: " + BaseEmployee::to_string() + ", earning=" + std::to_string(earning());
	}

	static int getNumSalCommEmp()
	{
		return sNumSalCommEmp;
	}

private:

// add static variable to keep track of number of SalComm Employees.

	static int sNumSalCommEmp;

	friend std::ostream& operator<<(std::ostream& os, const SalaryCommissionEmployee& salComm)
	{

		// std::cout << "To be done by students. Use BaseEmployee string coversion operator to print the base info. THen add salary print out.\n";

		os << static_cast<const BaseEmployee&>(salComm)  
			<< ", Salary: " << salComm.getBaseSalary()
			<< ", Gross Sale: " << salComm.getGrossSale()
			<< ", Commission Rate: " << salComm.getcommisionRate()
			<< ", Earning: " << salComm.earning() << "\n";
		return os;
	}
	

	friend std::istream& operator>>(std::istream& is, SalaryCommissionEmployee& salComm)
	{
		is >> static_cast<BaseEmployee&>(salComm); 
		double salary;
		std::cout << "Enter Salary: ";
		is >> salary;
		salComm.setBaseSalary(static_cast<int>(std::round(salary)));;

		double grossSale;
		std::cout << "Enter Gross Sale: ";
		is >> grossSale;
		salComm.setGrossSale(static_cast<int>(std::round(grossSale)));

		double commissionRate;
		std::cout << "Enter Commission Rate: ";
		is >> commissionRate;
		salComm.setcommisionRate(static_cast<int>(std::round(commissionRate)));

		return is;
	}
	
};
