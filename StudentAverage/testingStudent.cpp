
#include <iostream>
#include "student.h"


int main()
{
	Student aStudent{ "Reza" };
	std::cout << "aStudent name is " << aStudent.getName() << std::endl;

	// we want to add 10 courses to aStudent courses and then compute the average and print it.
	// we want to do it by asking user for each course name and mark. Then add it to the courses.

	int courseCount{ 0 };
	while (courseCount < 3)
	{
		std::string coursename{ "" };
		float mark{ 0.f };
		std::cout << "Enter a course name: ";
		std::getline(std::cin, coursename);
		std::cout << "coursename=" << coursename << std::endl;

		std::cout << "Enter the course mark: ";
		std::cin >> mark;
		Course aCourse{ coursename, mark };
		aStudent.courses.push_back(aCourse);
		++courseCount;
		std::cin.ignore();
	}
	
	std::cout << "Your average is " << aStudent.getAverage() << std::endl;
	

	Student bStudent;

	bStudent.setName("Tony Soprano");

	return 0;
}