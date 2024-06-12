#pragma once
#include <string>

class Person {
// Remember that if you dont write default will be private
private:
	std::string first;
	std::string last;
	int age;
	int id;

public:
// constructor name has to be same as the class
// Way number 1 -->  Remember that initialization can be done in the same line 
	Person(std::string first, std::string last, int a, int id) : first(first), last(last), age(a), id(0) {

	}
		//Way number 2 = Person(): first(""), last(""), age(0), id(0) {} --> then you dont neet do write in the same line
		Person() = delete; // This way compiler will not create a default, so your code will only consider the one you create

		//Person(Person const& src) = delete; // DONT WANT MY CLASS TO BE COPIED --> SAFETY MEASURE
	
		//You asked about putting space between operator and " = ", he said that it should create a problem but if do start here changing
			// Only constructor it should not return anything
		Person& operator = (Person const& src) = delete; // disabling or deleting assignment

		// Implementing comparison operator
		bool operator==(Person const& rhs) {
			if (first == rhs.first && last == rhs.last) {
				return true;
				// dont need else here, but can be use if you want
				return false;
			}
		};

		// Operations:
		// Method = Function = Void --> remember that void doesnt return anything
		void setAge(int a) {

			age = a;

		}

		//Getters
		// Getting the First Name
		std::string getFisrt() const {
			return first;
		}

		// Getting Last Name

		std::string getLast() const {

			return last;

		}

		int getAge() const {

			return age;
		}

		int getID() {

			return id;
		}

		std::string toString() const {

			return first + " " + last + ", age = " + std::to_string(age);

		};

		//Setters

		void setID(int i) {

			// Check to see if ID is positive

			if (i <= 0) {
				std::cout << "setID: please provide a valid ID " << endl;
				return;
			}
		}
	};