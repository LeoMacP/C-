#include <iostream>
#include "student.h"

using namespace std;
void Student::setName(std::string aname)
{
	//prevent setting name to empty string
	if (aname.empty())
	{
		std::cout << "Empty name is not accepted\n";
		return;
	}
	// check to see if there is at least a firstname and a lastname.
	// find_first is a method - READ ABOUT IT
	// npos =  
	if (aname.find_first_of(" ") == std::string::npos)
	{
		std::cout << "Need a first name separated by a space from a lastname\n";
		return;
	}
	name = aname;
}

void Student::computeAverage()
{
	float total{ 0.0f };
	for (size_t i = 0; i < courses.size(); ++i)
		total += courses[i].mark;
	average = total / 20;

}
