#include "Animal.h"

void Animal::print() const {
    std::cout << "Animal{";
    std::cout << "name=\"" << name << ", ";
    std::cout << "age=" << age << "}\n";
}