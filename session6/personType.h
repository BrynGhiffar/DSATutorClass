// personType.h
#ifndef _PERSONTYPE_H_
#define _PERSONTYPE_H_
#include <string>
#include <iostream>

class personType {
public:
	void print() const;
	// Function to output the first naem and last name
	// in the form firstName lastName

	void setName(std::string first, std::string last);
	// Function to set firstName and lastName according to the
	// parameters.
	// Postcondition: firstName = first; lastName = last;

	std::string getFirstName() const;
	// Function to return the first name.
	// Postcondition: The value of firstName is returned

	std::string getLastName() const;
	// Function to return the last name.
	// PostCondition: the value of lastName is returned

	personType();
	// default construcotr
	// Sets firstName and lastName to null string.
	// Postcondition: firstName = ""; lastName = "";

	personType(std::string first, std::string last);
	// Construcotr with parameters.
	// Sets firstName and lastName according to the parameters.
	// Postcondition: firstName = first; lastName = last;

private:
	std::string firstName; // variable to store the first name
	std::string lastName;  // variable to store the last name
};
#endif