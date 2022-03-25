// templates

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template <class T1, class T2>
class Dual {
    T1 first;
    T2 second;
public:
    Dual(T1 f, T2 s) : first(f), second(s) {}

    void print() const {
		cout << "Dual(" << first << ", " << second << ")";
    }
};

// template <class T1, class T2>
// void Dual<T1, T2>::print() const {
// }

template <typename T>
void print(T item) {
    cout << item << endl;
}

// void print(int item) {
//      cout << item << endl;
// }

// void print(const char* item) {
//      cout << item << endl;
// }

int main()
{
    print<int>(123);
    print<string>("123");
    Dual<int, string> myDual(123, "what");
    myDual.print();
}
