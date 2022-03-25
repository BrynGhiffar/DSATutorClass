#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void printLineStars(int n) {
    for (int i = 0; i < n; i++) {
        cout << '*';
    }
    cout << endl;
}

void printStars(int i, int n) {
    // keep going when i <= n
    // stop/do nothing when i > n
    if (i > n) {
        return;
    } else {
		printLineStars(i);
		printStars(i + 1, n);
		printLineStars(i);
    }
}

int main()
{
    int num;
    do {
        cout << "Enter number of lines: ";
        cin >> num;
        printStars(1, num);
    } while (num > 0);
}
