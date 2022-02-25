// Learning materials:
// * class templates
// * using namespace
// * initializer list
// * multi-file compilation
//      * writing a header file
//      * using #ifndef, #define and #endif pre-processor
// * Exercises

// For multi-file compilation those who can't use vs 
// you can use g++ with the following command to create the object files
// 
// g++ -c -o main.o main.cpp -std=c++11
// g++ -c -o Animal.o Animal.cpp -std=c++11
// 
// then link the two object files using
// g++ -o main main.o Animal.o -std=c++11
#include <iostream>
#include "Animal.h"

class Dog : public Animal{
public:
    const int NUMBER_OF_LEGS;
    Dog(const std::string& nm, int ag) 
        : Animal::Animal(nm, ag), NUMBER_OF_LEGS(4) {}
};

int main()
{
    Animal wild("Doggo", 10);
    wild.print();
    Dog myPet("Doge", 3);
}