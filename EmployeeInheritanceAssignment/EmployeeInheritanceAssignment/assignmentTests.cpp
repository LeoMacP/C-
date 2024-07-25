
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "BaseEmployee.h"
#include "CommissionEmployee.h"
#include "SalaryCommisionEmployee.h"
#include "Date.h"
#include "SalaryEmployee.h"


using namespace std;
int main()
{

	// This assignment is to test functionalities supported by the Employee Hierarchy along with operator overloading we introduced in class, in the form of overloading <<, >>, ++, and so on. The steps to perform the tests are as following:
	// 1- Complete operator overloading for stream input >> and output << for BaseEmployee, SalaryEmployee, CommisionEmployee, and SalaryCommisionEmployee, and Date and PhoneNumber classes. You are supposed to use the input operator overload to load the data from the data file EmployeeData.txt. Read the data in this file, line by line (after skipping the first few comment lines). For each line that you read, first detect what type of employee it is. Based on the type, construct an employee of that type and add that employee to the vector of employees bellow:
	
	
	
	
	vector<BaseEmployee*> employees;
	ifstream file("EmployeeData.txt");
	
	// suppose you have read a line from the file into a string str. Also suppose you have determined that str is for SalaryEmployee. Then constructing the employee and adding it to the vector goes as following:

	/*
	string aline; // suppose you have read this line from the input file
	SalaryEmployee* sEmp0{ new SalaryEmployee; };
	istringstream is{ aline };
	is >> sEmp0;
    employees.push_back(&sEmp0);
	 The above is a sample code. 
	*/
	
	// Your code goes here bellow:
	string line;
	while (getline(file, line)) {
		if (line.empty() || line[0] == '#') continue; // Skip empty lines and comments

		istringstream iss(line);
		string type;
		iss >> type;

		if (type == "SalaryEmployee") {
			SalaryEmployee* sEmp = new SalaryEmployee;
			iss >> *sEmp;
			employees.push_back(sEmp);
		}
		else if (type == "CommissionEmployee") {
			CommissionEmployee* cEmp = new CommissionEmployee;
			iss >> *cEmp;
			employees.push_back(cEmp);
		}
		else if (type == "SalaryCommissionEmployee") {
			SalaryCommissionEmployee* scEmp = new SalaryCommissionEmployee;
			iss >> *scEmp;
			employees.push_back(scEmp);
		}
	}

	file.close();

	
	// 2- print all the employees out using output operator >> for each employee.
	cout<<"Printing all the employees:\n";
	// YOur code goes here 
	
	for (auto emp : employees) {
		cout << *emp << endl;
	}




	// 3-Increase salary for SalaryEmployees by 10% and increase commission rate for the rest by 3%. Then print each employee 
	//  new earning using earning() method.
	cout << "Increase salary for all SalaryEmployees and SalaryCommissionEmployees by 10% " <<
		"  and increase commission rate by 3% " <<
		" and finally print the updated earnings below : \n\n";
	// Your code goes here: 

	for (auto emp : employees) {
		SalaryEmployee* sEmp = dynamic_cast<SalaryEmployee*>(emp);
		if (sEmp) {
			double newSalary = sEmp->getBaseSalary() * 1.10;
			sEmp->setBaseSalary(newSalary);
		}

		CommissionEmployee* cEmp = dynamic_cast<CommissionEmployee*>(emp);
		if (cEmp) {
			double newRate = cEmp->getcommisionRate() + 0.03;
			cEmp->setcommisionRate(newRate);
		}

		cout << *emp << " New earning: " << emp->earning() << endl;
	}

	
	// 4-Find all employees who have been with the company more than 2 years, and print those employees info using output operator >>
	cout<<"List of all employees who have been with the company for more than 2 years to date:\n";
	// Your code goes here: 
	
	for (auto emp : employees) {
		if (emp->getYearsWorked() > 2) {
			cout << *emp << endl;
		}
	}


	
	// 5- Compute average earning for each type of employee in the company, and print the result
	// Your code goes here: 


	double totalSalaryEarnings = 0.0;
	double totalCommEarnings = 0.0;
	double totalSalCommEarnings = 0.0;
	int salaryCount = 0;
	int commCount = 0;
	int salCommCount = 0;

	for (auto emp : employees) {
		if (auto sEmp = dynamic_cast<SalaryEmployee*>(emp)) {
			totalSalaryEarnings += sEmp->earning();
			salaryCount++;
		}
		if (auto cEmp = dynamic_cast<CommissionEmployee*>(emp)) {
			totalCommEarnings += cEmp->earning();
			commCount++;
		}
		if (auto scEmp = dynamic_cast<SalaryCommissionEmployee*>(emp)) {
			totalSalCommEarnings += scEmp->earning();
			salCommCount++;
		}
	}

	// Your code goes here: 
	cout << "\nAverage earning for SalaryEmployees: "
		<< (salaryCount > 0 ? totalSalaryEarnings / salaryCount : 0.0) << endl;
	
	// Your code goes here: 
	cout<<"\nAverage earning for CommissionEmployees: " << (commCount > 0 ? totalCommEarnings / commCount : 0.0) << endl;
	
	// Your code goes here: 
	cout<<"\nAverage earning for SalaryCommissionEmployees: " << (salCommCount > 0 ?totalSalCommEarnings / salCommCount : 0.0) << endl;
	 


	// 6- Print average earning for the whole company. Then Remove the toppest earning employee from the company and then compute  average company earning again and print it.
	
	double totalEarnings = totalSalaryEarnings + totalCommEarnings + totalSalCommEarnings;
	int totalCount = salaryCount + commCount + salCommCount;

		
	// Your code goes here: 
	cout<<"\nAverage employees earning for the whole company:" << (totalCount > 0 ? totalEarnings / totalCount : 0.0) << endl;;
 

	
	//cout << "\n Find the toppest earner and print his/her info.\n";
	// Your code goes here: 
	BaseEmployee* topEarner = nullptr;
	double highestEarning = 0.0;

	for (auto emp : employees) {
		if (emp->earning() > highestEarning) {
			highestEarning = emp->earning();
			topEarner = emp;
		}
	}

	cout << *topEarner << endl;
	
	
	cout<<"\nRemove the toppest earner and print the earning average for the company before and after the removal: ";
	// Your code goes here: 
	
	employees.erase(remove(employees.begin(), employees.end(), topEarner),employees.end());
	totalEarnings = totalSalaryEarnings + totalCommEarnings + totalSalCommEarnings;
	totalCount = salaryCount + commCount + salCommCount - 1;
	cout << (totalCount > 0 ? totalEarnings / totalCount : 0.0) << endl;
	

	totalEarnings = 0.0;
	totalCount = 0;
	for (auto emp : employees) {
		totalEarnings += emp->earning();
		totalCount++;
	}



	
	cout << "\nDelete all dynamic object:";
		// Your code goes here: 

	for (auto emp : employees) {
		delete emp;
	}

	cout<<"\nEnd of tests. Enter any key to finish.";
	cin.ignore();

	return 0;
}