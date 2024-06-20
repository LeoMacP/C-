#include <iostream> // system streams
#include <fstream> // file streams
#include <sstream> //stream of streams
#include <vector>

#include "person.h"


using namespace std;

// what is gonna happen:
// Opening people files
// Building vectos with the data
// retriveing their age and calculating the average
// taking notes of who is abouve average
// Saving the 2 vectors to an output file


//Passing in input file as command line argument be like : >testingIO.exe listOfNames.txt
// argv[0] = "testingIO.exe"
// argv[1] = "listOfNames"
// argc = argument count
// argv = argument vector(aka array in c++)
// Passing files here in this scenario is like reading elements insie an array
int main(int argc, char** argv) {

	// check if there is anough arguments:

	if (argc < 2) {
		cout << "Usage: testingIO.exe filename\n";
		return 1;

	}
	else
		cout << "Processing input file " << argv[1] << endl;

	//Opeging file for processing (read)
	//ifstream is a class
	// fs is a variable that is going to hold the file to be used
	std::ifstream fs(argv[1]);

	// Check if file si properly opened for reading

	
		//vector = container ("array")
		vector<Person> personVec{};
	if (fs.is_open()) {
		// temporary container -- waiting room -- it is gonna get empty and full over and over
		string aline{};

		//getline --> reads line by line in the file
		while (std::getline(fs, aline)) {

			cout << "Line read: " << aline << endl;
			//constructor that expects a string
			std::stringstream ss(aline);
			string first, last;
			int age;
			int id;

			//variable that is going to reciebe and split the information into where it needs to
			ss >> first >> last >> age;

			Person per1(first, last, age);
			personVec.push_back(per1);
		}
		fs.close();

		// Finding average age of person:
		// Parse through personVec one by one, get each person age, add it to some variable at the end divide by the number of persons
		size_t averageAge{};

		//classic way
		// for (int i = 0; i < personVec.size(); ++i) {
			//Person aPer = personVec[i];
			//averageAge += aPer.getAge();
		//};
		
		//New way 
		for (auto& per : personVec) {
			averageAge += per.getAge();

		};

		averageAge /= personVec.size();
		cout << "Average age is " << averageAge << endl;

		// create 2 vectors, one for persons with age < average, and another for person with age >= average
		vector<Person> theYoung;
		vector<Person> theWise;
		

		// save the youngs to an output file theYoungs.txt
		// save theWise to an output file 
		
		for (auto& per : personVec) {
			if (per.getAge() < averageAge) {
				theYoung.push_back(per);

			
			}else
				theWise.push_back(per);

		}

		// save the youngs to an output file theYoungs.txt
		// save theWise to an output file 
		std::ofstream yf("theYoung.txt");
		if (yf.is_open()) {
			for (auto& aper : theYoung) {
				string aline = aper.getFisrt() + " " + aper.getLast() + " " + std::to_string(aper.getAge());
				cout << aline << endl;
				yf << aline << endl;
			};
			yf.close();
		}

		std::ofstream wf("theWise.txt");
		if (yf.is_open()) {
			for (auto& aper : theYoung) {
				string aline = aper.getFisrt() + " " + aper.getLast() + " " + std::to_string(aper.getAge());
				cout << aline << endl;
				yf << aline << endl;
			};
			yf.close();
		}
	}
	cout << "Number of Person" << personVec.size() << endl;


	return 0;
}
