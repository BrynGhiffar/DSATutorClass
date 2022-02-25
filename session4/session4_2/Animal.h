#ifndef _ANIMAL_H_
#define _ANIMAL_H_
#include <string>
#include <iostream>

// Multiple inclusions not allowed
// Example:
// Dog.h
// #include "Animal.h"

// session4_2.cpp
// #include "Animal.h"
// #include "Dog.h"

class Animal {
public:
    std::string name;
    int age;
    Animal(const std::string& nm,
        int ag) : name(nm), age(ag) {
        name = nm;
    };
    void print() const;
};
#endif
