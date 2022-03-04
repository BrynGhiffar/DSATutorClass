#ifndef _EXTPERSONTYPE_H_
#define _EXTPERSONTYPE_H_

#include "personType.h"
#include "dateType.h"
#include "addressType.h"
#include <string>
#include <iostream>

class extPersonType {
private:
	personType name;
	dateType birthDate;
	addressType address;
	std::string relationship;
	std::string phoneNumber;
public:
	extPersonType(
		const std::string& fn,
		const std::string& ln,
		int month, int day, int year,
		const std::string& rlnship,
		const std::string& addressSt,
		const std::string& cty,
		const std::string& stt,
		const std::string& zp,
		const std::string& pn
	);

	// getters and setters
	void setFirstName(const std::string& firstName);
	void setLastName(const std::string& lastName);
	void setBirthDate(int month, int day, int year);
	void setRelationship(const std::string& relationship);
	void setPhoneNumber(const std::string& phoneNumber);
	void setAddress(const std::string& address);
	void setCity(const std::string& city);
	void setState(const std::string& state);
	void setZip(const std::string& zip);

	std::string getFirstName() const;
	std::string getLastName() const;
	dateType getBirthDate() const;
	std::string getRelationship() const;
	std::string getPhoneNumber() const;
	std::string getAddress() const;
	std::string getCity() const;
	std::string getState() const;
	std::string getZip() const;

	void print() const;
};
#endif