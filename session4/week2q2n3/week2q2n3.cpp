#include <iostream>
#include <string>

class Device {
private:
    std::string name;
    unsigned int batteryCapacity;
    std::string chargerType;
    double cost;
public:
    Device(const std::string& nm, unsigned bc, const std::string ct, double cs)
        : name(nm), batteryCapacity(bc), chargerType(ct), cost(cs) {}
};

class Phone : public Device {
private:
    std::string screenRes;
    std::string frontCamRes;
    std::string backCamRes;
public:
    Phone(
        const std::string& nm, 
        unsigned bc, 
        const std::string ct, 
        double cs,
        const std::string& screenRe,
        const std::string& frontCamRe,
        const std::string& backCamRe
        ) : Device::Device(nm, bc, ct, cs),
        screenRes(screenRe),
        frontCamRes(frontCamRe),
        backCamRes(backCamRe) {}
};

int main()
{
    Phone ph("GalaxyS10", 4500, "USB-C", 2000.00, "1920x1080", "1920x1080", "1920x1080");
}