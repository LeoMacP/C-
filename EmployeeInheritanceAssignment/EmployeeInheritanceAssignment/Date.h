#pragma once
// a class to represent date
#include <array>

class Date
{
public:
	Date::Date(unsigned int m = 1, unsigned d = 1, unsigned y = 1900); // default constructor

	void setDate(unsigned int, unsigned int, unsigned int); // set month, day, year
	

	Date& operator++();  // prefix increment operator ++i
	Date operator++(int);  // postfix increment operator  i++
	Date& operator+=(unsigned int);

	static bool leapYear(unsigned int y); // is year y a leap year or not
	bool endOfMonth(unsigned int d) const; // is day d end of the month
	int yearsEmployed() const;

	std::string to_string() const;

private:
	unsigned int month, day, year;
	static const std::array<unsigned int, 13> days;
	void helpIncrement(); // utility method used internally for incrementing date
	
	// add operator<< and operator>> as friend here, similar to how was done for PhoneNumber class
	friend std::ostream& operator<<(std::ostream& os, const Date& date)
	{
		os << date.to_string();
		return os;
	}

	friend std::istream& operator>>(std::istream& is, Date& date)
	{
		unsigned m, d, y;
		char delimiter;
		is >> m >> delimiter >> d >> delimiter >> y;
		date.setDate(m, d, y);
		return is;
	}
};
