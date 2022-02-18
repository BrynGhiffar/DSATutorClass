// Today's Tutorial
// * switch statement
// * do-while loop
// * ternary operator
// * const as well as #define
// * multi-line comments
// * Go through C++ exercise
//		* You have 5 minutes to solve one question
//		* After that we will walkthrough how to solve them
#include <iostream>
#include <string>
#include <vector>

// FORWARD SLASH COMMENT
/*
ahaklsdhf
asdklfjh
*/

void question_1() {
	std::cout << "Enter age: ";
	int age;
	std::cin >> age;
	std::cin.get();
	std::cout << "Enter your name: ";
	std::string name;
	std::getline(std::cin, name);
	// std::cout << "HELLO " + " BYE\n";

	if (age > 20) {
		std::cout << "Hello " + name + ". How are you doing today?\n";
		// Other way you can do this 
		// std::cout << "Hello " << name << ". How are you doing today?\n";
	}
}

void question_2() {
	std::cout << "Enter size: ";
	int size;
	std::cin >> size;
	std::vector<int> vec(size);
	std::cout << "Enter list: ";
	for (int i = 0; i < size; i++) {
		std::cin >> vec[i];
	}
	std::cout << "The list reversed is: ";
	for (int i = size - 1; i >= 0; i--) {
		std::cout << vec[i] << ' ';
	}
	std::cout << '\n';
}

void question_3() {
	std::string month;
	std::cout << "Enter month: ";
	std::getline(std::cin, month);

	// and so on...
	// if ((month == "January") || (month == "March") || (month == "May")) {
	// 	std::cout << "There are 31 days in January\n";
	// } else if (month == "February") {
	//	std::cout << "There are 28 days in February\n";
	// }

	std::vector<std::string> months = { "January", "February", "March" };
	std::vector<int> days = { 31, 28, 31 };
	int month_number = 0;
	for (int i = 0; i < months.size(); i++) {
		if (months[i] == month) {
			month_number = i;
			break;
		}
	}
	std::cout << "There are "
		<< days[month_number] << " in "
		<< months[month_number] << "\n";

	// and so on
	// std::cout << month << '\n';
}

void lesson() {
	int var;
	var = 2;
	switch (var)
	{
	case 1:
		std::cout << "var is one!\n";
		break;
	case 2:
		std::cout << "var is two!\n";
	case 3:
		std::cout << "var is three!\n";
	default:
		break;
	}

	int i = 10;
	do {
		std::cout << i << ' ';
		i++;
	} while (i < 10);
	std::cout << '\n';

	char cstr0[] = "HELLO";
	char cstr1[] = "HELLO";
	std::cout << std::boolalpha << (cstr0 == cstr1) << '\n';
	std::string str = "nothing";
	int val = (str == "nothing") ? 123 : -1;
	std::cout << val << '\n';

	const std::string CONST_VAL;
	std::cout << "a" << CONST_VAL << "a\n";

	const std::vector<int> vec = { 1, 2, 3 };
	std::cout << vec[1] << '\n';
	std::cout << vec.at(3) << '\n';

	int arr[] = { 6, 5, 4 };
	std::cout << arr[3] << '\n';
}


int main()
{	
	// question_1();
	// question_2();
	question_3();
}