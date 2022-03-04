#ifndef _ADDRESSTYPE_H_
#define _ADDRESSTYPE_H_

#include <iostream>
#include <string>

class addressType {
private:
    std::string address;
    std::string city;
    std::string state;
    std::string zip;
public:
    addressType(
        const std::string& addr,
        const std::string& cty,
        const std::string& stt,
        const std::string& zp
    );
    // getters and setters
    void setAddress(const std::string& address);
    void setCity(const std::string& city);
    void setState(const std::string& state);
    void setZip(const std::string& zip);

    std::string getAddress() const;
    std::string getCity() const;
    std::string getState() const;
    std::string getZip() const;

    void print() const;
};
#endif