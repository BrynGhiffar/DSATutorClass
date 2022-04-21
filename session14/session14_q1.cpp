#include <iostream>
#include "LinkedStackType.h"

int main()
{
    LinkedStackType<int> myStack;
    myStack.push(5);
    myStack.push(6);
    myStack.push(7);
    LinkedStackType<int> copiedStack;
    copiedStack = myStack;
    std::cout << copiedStack << std::endl;
    std::cout << myStack << std::endl;
    myStack.pop();
    myStack.pop();
    myStack.pop();
    std::cout << myStack << std::endl;
    std::cout << "Hello World!\n";
}
