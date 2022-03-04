#include "extPersonType.h"
extPersonType::extPersonType(
	const std::string& fn,
	const std::string& ln,
	int month, int day, int year,
	const std::string& rlnship,
	const std::string& addressSt,
	const std::string& cty,
	const std::string& stt,
	const std::string& zp,
	const std::string& pn
) : name(fn, ln), birthDate(month, day, year), relationship(rlnship),
phoneNumber(pn), address(addressSt, cty, stt, zp) {}

// getters and setters
void extPersonType::setFirstName(const std::string& firstName) {
	name.setName(firstName, extPersonType::getLastName());
}

void extPersonType::setLastName(const std::string& lastName) {
	name.setName(extPersonType::getFirstName(), lastName);
}

void extPersonType::setBirthDate(int month, int day, int year) {
	birthDate.setDate(month, day, year);
}

void extPersonType::setRelationship(const std::string& relationship) {
	this->relationship = relationship;
}
void extPersonType::setPhoneNumber(const std::string& phoneNumber) {
	this->phoneNumber = phoneNumber;
}

void extPersonType::setAddress(const std::string& address) {
	this->address.setAddress(address);
}

void extPersonType::setCity(const std::string& city) {
	this->address.setCity(city);
}

void extPersonType::setState(const std::string& state) {
	this->address.setState(state);
}
void extPersonType::setZip(const std::string& zip) {
	this->address.setZip(zip);
}

std::string extPersonType::getFirstName() const {
	return name.getFirstName();
}
std::string extPersonType::getLastName() const {
	return name.getLastName();
}
dateType extPersonType::getBirthDate() const {
	return birthDate;
}

std::string extPersonType::getRelationship() const {
	return relationship;
}

std::string extPersonType::getPhoneNumber() const {
	return phoneNumber;
}

std::string extPersonType::getAddress() const {
	return this->address.getAddress();
}

std::string extPersonType::getCity() const {
	return this->address.getCity();
}

std::string extPersonType::getState() const {
	return this->address.getState();
}

std::string extPersonType::getZip() const {
	return this->address.getZip();
}

void extPersonType::print() const {
	std::cout << extPersonType::getFirstName() << " "
		<< extPersonType::getLastName() << " ";
	birthDate.printDate();
	std::cout << " ";
	address.print();
	std::cout << " ";
	std::cout << extPersonType::getRelationship() << " ";
	std::cout << extPersonType::getPhoneNumber() << " ";
}