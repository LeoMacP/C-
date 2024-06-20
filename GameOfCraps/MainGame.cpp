#include<iostream>
#include <random>
#include <ctime>

using namespace std;

enum status {CONTINUE, WON, LOST};
unsigned int rollDice(); //function the rolls two dice and return the sum of the faces

int main() {

	
	
	return 0;
}

unsigned int rollDice() {

	//generates 2 random number
	std::default_random_engine eng(time(0));
	std::uniform_int_distribution<unsigned int> randInt1(1, 6), randInt2(1, 6);


	//first turn ==> sum them, if sum == 7 or 11, player wins! ------ if sum == 2, 3, 12, player loses!
	int rollDice1 = randInt1(eng);
	int rollDice2 = randInt2(eng);
	int diceSum = rollDice1 + rollDice2;
	
	
	switch (diceSum) {
	//Win case
	case 1:
		if (diceSum == 7 || diceSum == 11) {
			std::cout << diceSum << "Chicken for Dinner!!!";
		}
	//lose case
	case 2:

	// continue case
	case 3:
	}

	

	//Variable to keep track the points and compare
	// 
	//
}