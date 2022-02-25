// week2q1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Worker {
private:
    std::string name;
    unsigned short age;
    std::string gender;
public:
    Worker(
        const std::string& nm = "No name",
        unsigned short ag = 0,
        const std::string& gndr = "Prefer not to say")
        : name(nm), age(ag), gender(gndr) {}
    std::string getName() const;
    unsigned short getAge() const;
    std::string getGender() const;
    void setName(const std::string& name);
    void setAge(unsigned short age);
    void setGender(const std::string& gender);
    void print() const;
};

std::string Worker::getName() const {
    return name;
}
unsigned short Worker::getAge() const {
    return age;
}
std::string Worker::getGender() const {
    return gender;
}
void Worker::setName(const std::string& name) {
    this->name = name;
}
void Worker::setAge(unsigned short age) {
    this->age = age;
}
void Worker::setGender(const std::string& gender) {
    this->gender = gender;
}

void Worker::print() const {
    std::cout << "Worker{";
    std::cout << "name=\"" << this->name << "\", ";
    std::cout << "age=" << this->age << ", ";
    std::cout << "gender=\"" << this->gender << "\"}\n";
}

int main()
{
    Worker me;
    me.setName("Bryn Ghiffar");
    me.setAge(20);
    std::cout << me.getName() << "\n";
    me.print();
}