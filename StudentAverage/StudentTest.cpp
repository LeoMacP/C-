#include <iostream>
#include "Student.h"

using namespace std;
int main()
{
	//ask user for student name:
	string stuName;

	while (stuName.length() <= 0)
	{
		cout << "What is student's name?\n";
		cin >> stuName;
	}

	Student stud(stuName);
	
	// ask user for courses' names and marks:
	string coursename{ "" };
	int coursemark;
	int courseCount{ 0 };
	do
	{
		cout << "\nEnter next course name and mark: ";
		cin >> coursename >> coursemark;
		if (coursename.length() <= 0 || coursemark < 0)
		{
			cout << "Try again! course name is empty or the mark is not valid!\n";
		}
		else
		{
			stud.SetCourse(coursename, coursemark);
			cout << "Course " << coursename << "with mark " << coursemark << " added.\n";
			++courseCount;
		}
	}
	while (coursename.size() > 1);

	stud.ComputeAverage();
	cout << "Student average is " << stud.GetAverage() << endl;
	string letterGrade{ stud.GetLetterGrade() };
	cout << "Letter grade for average is " << letterGrade << endl;

	return 0;
}