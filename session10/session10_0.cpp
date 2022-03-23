#include <iostream>
#include <string>
#include "linkedListType.h"

using namespace std;

class Cat {
public:
    ~Cat();
    Cat(const Cat& c);
    Cat();
    string* name;
};

Cat::~Cat() {
    cout << "Meowww...\n";
    delete name;
}

Cat::Cat() {
    this->name = new string("no name");
}

Cat::Cat(const Cat& c) {
    this->name = new string;
    *(this->name) = *(c.name);
}

int main()
{
    linkedListType<int> li;
    li.insertFirst(1);
    li.insertFirst(2);
    li.insertFirst(3);
    li.print();
    cout << "length: " << li.length() << endl;
    li.deleteNode(2);
    li.deleteNode(3);
    li.print();
    li.deleteNode(1);
    li.print();
    cout << "length: " << li.length() << endl;

}