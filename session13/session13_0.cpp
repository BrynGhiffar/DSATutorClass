// main topic: stack
// stack operations:
#include <iostream>
#include "Stack.h"

using std::cout;
using std::endl;

int main()
{
    Stack<int> myStack(10);
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    // Stack copiedStack(myStack);
    Stack<int> copiedStack;
    copiedStack.push(100);
    copiedStack.push(200);
    copiedStack.push(300);
    cout << myStack << endl;
    cout << copiedStack << endl;
    copiedStack = myStack;
    cout << myStack << endl;
    cout << copiedStack << endl;

    Stack<std::string> stringStack;
    stringStack.push("hello");
    stringStack.push("bye - bye");
    cout << stringStack << endl;
    while (!myStack.empty()) {
        cout << myStack.pop() << endl;
    }

    while (!copiedStack.empty()) {
        cout << copiedStack.pop() << endl;
    }
}
