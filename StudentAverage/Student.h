#pragma once
#include <string>
#include <vector>

// struct = tuples
struct Course
{
	std::string title;
	float mark;
};

class Student
{
public:
	// a constructor is a recipe for creating an instance of this class.
	Student(std::string aname="Not specified") // initialization can be done here by just : name(aname), average(0)
	{
		name = aname;
		average = 0;
	}
	// getter for name
	std::string getName() const
	{
		return name;
	}

	float getAverage()
	{
		computeAverage();
		return average;
	}
	
	// setter for name
	void setName(std::string aname);
	
	//destructor uselesse right now
	//~Student();

private:
	std::string name; // assuming here that the name = full name
	float average;
	void computeAverage();
	std::vector<Course> courses;

};


