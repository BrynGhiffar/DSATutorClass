#include "addressType.h"

addressType::addressType(
    const std::string& addr,
    const std::string& cty,
    const std::string& stt,
    const std::string& zp
) : address(addr), city(cty), state(stt), zip(zp) {}

void addressType::setAddress(const std::string& address) {
    this->address = address;
}

void addressType::setCity(const std::string& city) {
    this->city = city;
}

void addressType::setState(const std::string& state) {
    this->state = state;
}

void addressType::setZip(const std::string& zip) {
    this->zip = zip;
}

std::string addressType::getAddress() const {
    return this->address;
}

std::string addressType::getCity() const {
    return this->city;
}

std::string addressType::getState() const {
    return this->state;
}

std::string addressType::getZip() const {
    return this->zip;
}

void addressType::print() const {
    std::cout << addressType::getAddress() << " "
        << addressType::getCity() << " "
        << addressType::getState() << " "
        << addressType::getZip();
}
