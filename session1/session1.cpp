#include <iostream>
#include <string>
#include <vector>

// What we will be learning today:
// * How to print, using cout
// * basic data types such as int, bool, double, float, char, string
//     * you can have as big an integer as you want in python
// * compound data structures such as arrays and vectors
// * taking input using cin, getline(cin, str), cin.getline(str, maxlength)
// * expressions + - % / *
// * if statements
// * iterations for, while, do-while
// * type conversion
// --- MAYBE ---
// * functions
// * structs
// * pointers, references
// * classes
//      * methods
//      * objects, instanct variables

struct A {
    int parameter2;
    int parameter1;
};

struct Person {
    std::string name;
    int age;
};

int foo() {

    std::cout << "This is foo\n";
    return 1;
}

int add(int num1, int num2) {
    int three = 3;

    return num1 + num2;
}

int main()
{
    // How to print in C++
    std::cout << 100 << "\n";
    std::cout << 123 << "\n";

    // C++ data types
    short shrt_nums;
    int number;
    long long_nums;
    unsigned long long llong_nums;
    std::cout << "SHRT_MIN: " << SHRT_MIN << '\n';
    std::cout << "SHRT_MAX: " << SHRT_MAX << '\n';
    std::cout << "INT_MIN: " << INT_MIN << '\n';
    std::cout << "INT_MAX: " << INT_MAX << '\n';
    std::cout << "LONG_MIN: " << LONG_MIN << '\n';
    std::cout << "LONG_MAX: " << LONG_MAX << '\n';
    std::cout << "LLONG_MIN: " << LLONG_MIN << '\n';
    std::cout << "LLONG_MAX: " << LLONG_MAX << '\n';

    bool condition = true;
    std::cout << std::boolalpha << condition << '\n';

    float my_float = 1.23;
    double my_double = 1.45;
    std::cout << my_float << '\n';
    std::cout << my_double << '\n';

    char my_char = '2';
    std::cout << my_char << '\n';

    std::string my_string = "It's a STRING!!";
    std::cout << my_string << '\n';

    int arr[] = { 1, 2, 3 };
    int length = (sizeof arr) / sizeof(int);
    std::cout << "length: " << length << '\n';
    std::vector<int> vec = { 1, 2, 3 };
    std::vector<std::string> vec_strings = { "one", "two" };
    vec.push_back(12);
    std::cout << "vector size: " << vec.size() << '\n';
    std::cout << "vec_strings.size(): " << vec_strings.size() << '\n';

    // Getting input in c++
    int nums;
    std::cout << "Give me a number: ";
    std::cin >> nums;
    std::cout << "Your number is " << nums << ".\n";
    char newline = std::cin.get();

    std::cout << "Enter your name: ";
    std::string inpt_str;
    std::getline(std::cin, inpt_str);
    std::cout << "Your name is " << inpt_str << ".\n";
    std::cout << newline;

    // Expressions
    int a = 2 * 3;
    std::cout << "a: " << a << '\n';
    int b = 3 + 3;
    std::cout << "b: " << b << '\n';
    int c = 10 % 3;
    std::cout << "c: " << c << '\n';

    // if statements, while loops, for loops.
    if (4 == 5) {
        std::cout << "IT'S TRUE\n";
        std::cout << "HOLA!!\n";
    }
    else if (1 == 1) {
        std::cout << "IT'S NOT TRUE\n";
    }
    std::cout << "-----------\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << 2 * i << '\n';
        std::cout << i << '\n';
    }
    std::cout << "-----------\n";
    int n = 0;
    std::cout << n++ << '\n';
    // n = 1
    std::cout << ++n << '\n';

    while (n < 10) {
        std::cout << n << '\n';
        n++;
    }

    // type conversion
    short num = SHRT_MAX;
    std::cout << "num: " << num << '\n';
    int nums_int = num; // implicit casting
    std::cout << "nums_int: " << nums_int + 1 << '\n';

    int exp_nums = (int)num;
    std::cout << "exp_nums: " << exp_nums + 1 << '\n';

    // functions
    int ret = foo();
    std::cout << ret << '\n';
    std::cout << add(2, 3) << '\n';

    // structs
    A my_A = { 1, 2 };
    std::cout << my_A.parameter1 << '\n';
    std::cout << my_A.parameter2 << '\n';

    Person me;
    me.name = "Bryn Ghiffar";
    me.age = 20;
    std::cout << me.name << '\n';
    std::cout << me.age << '\n';

    // references and a little bit of explicit casting
    double val = 3.14;
    double* double_pointer = &val;
    float float_val = 1.68;
    // 1.12
    float float_val2 = int(float_val) + 0.12;
    std::cout << float_val2 << '\n';
}
