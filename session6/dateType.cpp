// dateType.cpp
#include "dateType.h"

bool dateType::isLeapYear(int year) const
{
	if (year % 100 == 0) {
		if (year % 400 == 0)
			return true;
		else
			return false;
	}
	else {
		if (year % 4 == 0)
			return true;
		else
			return false;
	}
}

void dateType::setDate(int month, int day, int year)
{
	int monthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month <= 0 || month > 12) {
		std::cerr << "Please enter a valid month\n";
		return;
	}

	if (year < 0) {
		std::cerr << "Please enter a valid year\n";
		return;
	}

	int md = monthDays[month - 1];
	if (month == 2 && dateType::isLeapYear(year))
		md++;

	if (day <= 0 || day > md) {
		std::cerr << "Please enter a valid day\n";
		return;
	}
	dMonth = month;
	dDay = day;
	dYear = year;
}

int dateType::getDay() const
{
	return dDay;
}

int dateType::getMonth() const
{
	return dMonth;
}

int dateType::getYear() const
{
	return dYear;
}

void dateType::printDate() const
{
	std::cout << dMonth << '-' << dDay << '-' << dYear;
}

// constructor with parameters
dateType::dateType(int month, int day, int year)
{
	setDate(month, day, year);
}