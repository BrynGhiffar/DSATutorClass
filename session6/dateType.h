// dateType.h
#ifndef _DATETYPE_H_
#define _DATETYPE_H_
#include <iostream>

class dateType
{
public:
	void setDate(int month, int day, int year);
	// Function to set teh date.
	// The member variables dMonth, dDay, dYear are set
	// according to the parameters
	// Postcondition: dMonth = month; dDay = day; dYear = year

	int getDay() const;
	// Function to return teh day.
	// Postcondition: the value of dDay is returned.

	int getMonth() const;
	// Function to return the month.
	// postCondition: The value of dMonth is returned.

	int getYear() const;
	// Function to return the year.
	// Postcondition: The value of dYear is returned

	void printDate() const;
	// Function output the date in the form mm-dd-yyyy

	bool isLeapYear(int year) const;
	// Function to determine if a year is a leap year

	dateType(int month = 1, int day = 1, int year = 1990);
	// Constructor to set the date
	// The member variables dMonth, dDay, and dYear are set
	// according to the parameters
	// Postcondition: dMonth = month; dDay = day; dYear = year. If
	//   no values are specified, the default values are used to
	//   initialize the member variables.
private:
	int dMonth;  // variable to store the month
	int dDay;    // variable to store the day
	int dYear;   // variable to store the year
};
#endif