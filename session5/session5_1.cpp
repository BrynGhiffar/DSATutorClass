#include <iostream>
#include <string>
using namespace std;

void updateString(string* strP) {
	(*strP)[0] = 'r';
}

int* createInt() {
	return new int;
}

void doSomething() {
	int* val = new int;
	*val = 10;
	delete val;
}

class A {
public:
	int a;
	int* b;
};

int main()
{
	string* strP = new string;
	*strP = "hello";
	updateString(strP);
	cout << *strP << endl;

	A a0;
	a0.a = 10;
	A a1;
	a1 = a0;
	cout << a1.a << endl; // will print 10
	a1.a = 100;
	cout << a1.a << endl; // 100
	cout << a0.a << endl; // 10

	a0.b = new int;
	*a0.b = 10;
	// a1.b and a0.b is pointing to the same value.
	a1 = a0;
	cout << *a0.b << endl;
	cout << *a1.b << endl;
	*a0.b = 123;
	cout << *a0.b << endl;
	cout << *a1.b << endl;
	delete a0.b;
}