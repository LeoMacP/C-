#include<iostream>
#include <random>
#include <ctime>
#include <array>
#include<iomanip> //formating output

using namespace std;

// This app "rolls" a dice and generates a random number/ practicing the random number engine generator



int main(int argc, char** argv) {

	if (argc < 2) {

		std::cout << "Usage: DiceRolling.exe count (count is number of times rolling the dice)\n";
		return 1;
	};

	// this is a class (light green)
	// time because it never repeats and keep increasing
	// engine to generate
	std::default_random_engine eng(time(0));

	// equaly chance for each number to happen
	// this is a class (light green)
	// It will set the range
	std::uniform_int_distribution<unsigned int> randInt(0, 9);

	// normal Distributino method
	//@ std::normal_distribution<float> randInt{ 5.0, 1.0 }; @
	
	//atoi ==> transform argv into and integer
	int totalCount{ std:: atoi(argv[1]) };
	
	//classic way to declare an array
	//[] length
	//{} initializing
	//int frequencyArray[10]{};

	// new way
	std::array<int, 10> frequencyArray{ 0 };
	for (int i = 0; i < totalCount; ++i) {

		int face = randInt(eng); // equivalent to rolling a dice
		frequencyArray[face]++;
		
	}
	// formating the output to show 13 spaces
	std::cout << "Face " << std::setw(13) << "Frequency " << endl;
	cout << "\n 0" << setw(13) << frequencyArray[0];
	cout << "\n 1" << setw(13) << frequencyArray[1];
	cout << "\n 2" << setw(13) << frequencyArray[2];
	cout << "\n 3" << setw(13) << frequencyArray[3];
	cout << "\n 4" << setw(13) << frequencyArray[4];
	cout << "\n 5" << setw(13) << frequencyArray[5];
	cout << "\n 6" << setw(13) << frequencyArray[6];
	cout << "\n 7" << setw(13) << frequencyArray[7];
	cout << "\n 8" << setw(13) << frequencyArray[8]; 
	cout << "\n 8" << setw(13) << frequencyArray[8];
	cout << "\n 9" << setw(13) << frequencyArray[9];

	return 0;
}