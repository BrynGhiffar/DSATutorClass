#include <iostream>
using std::cout;
using std::endl;
using std::cin;

void printLineStars(int n) {
	// n = -1 will stop the loop
	for (int i = 0; i < n; i++) {
		cout << "*";
	}
	cout << endl;
}

void printStars(int n) {
	if (n <= 1) {
		printLineStars(n);
		printLineStars(n);

	}else {
		printLineStars(n);
		printStars(n - 1);
		printLineStars(n);
	}

	// if (n > 0) {
	// 	printLineStars(n);
	// 	printStars(n - 1);
	// 	printLineStars(n);
	// }
}

int main()
{
	int num;
	do {
		cout << "Enter number of lines: ";
		cin >> num;
		printStars(num);
	} while (num > 0);
}
