#pragma once

#include <string>
#include <sstream>
#include <iomanip>
#include "BaseEmployee.h"

// add support to keep track of number of SalaryEmployees !!!DONE!!!
class SalaryEmployee : virtual public BaseEmployee
{
public:
	SalaryEmployee(std::string first = {}, std::string last = {}, std::string sin = {}, double pay={ 35000. }) :
		BaseEmployee(first, last, sin), salary(pay)
	{
	}
	
	~SalaryEmployee()
	{
		std::cout << "~SalaryEmployee.\n";
	}

	virtual double earning() const override
	{
		return salary;
	}



	virtual std::string to_string() const override
	{
		std::ostringstream os;
		os << (BaseEmployee::to_string() + ", pay=") << earning();
		return os.str();

	}

	void setSalary(double pay) 
	{
		salary = pay;
	}
	int setSalary(double pay, int count) // overloading setSalary
	{
		salary = pay;
		return 1;
	}
	double getSalary() const
	{
		return salary;
	}
protected:

	// implement friend operator<<() here
	// must use BaseEmployee input support.
	friend std::ostream& operator<<(std::ostream& os, const SalaryEmployee* sal)
	{
		os << static_cast<const BaseEmployee*>(sal);
		os << "Salary: " << sal->salary << "\n";
		return os;
	};
	
	// implement friend opereator>> here
	friend std::istream& operator>>(std::istream& is, SalaryEmployee& se)
	{
		is >> static_cast<BaseEmployee&>(se);
		std::cout << "Enter Salary: ";
		is >> se.salary;
		return is;
	};

private:
	double salary;
};
