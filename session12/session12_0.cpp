// overloading

#include <iostream>
#include <vector>
#include <string>

using std::ostream;
using std::cout;
using std::endl;
using std::string;

void print(int n) {
	cout << n << endl;
}

void print(string str) {
	cout << str << endl;
}

void print(int* arr, int length) {
	// 1 2 3 
	//     ^
	for (int i = 0; i < length; i++)
		cout << arr[i] << " ";
	cout << endl;
}

class Point {
	int x, y;
	public:
	Point(int x_val, int y_val) : x(x_val), y(y_val) {}


	friend ostream& operator<<(ostream& os, const Point& point);
	friend Point operator+(const Point& p1, const Point& p2);
	// friend bool operator<(const Point& p1, const Point& p2);
	friend void print(const Point& point);
};

void print(const Point& point) {
	cout << point.x << point.y << endl;
}

ostream& operator<<(ostream& os, const Point& point) {
	os << "Point(" << point.x << ", " << point.y << ")";
	return os;
}

Point operator+(const Point& p1, const Point& p2) {
	return Point(p1.x + p2.x, p1.y + p2.y);
}

int main()
{
	print(123);
	// + - / * << =
	print("hello");
	int arr[] = { 1, 2, 3, 4 };
	int length = (sizeof arr) / sizeof(int);
	print(arr, length);
	cout << "Hello\n";
	cout << "a" << "b";
	operator<<(cout, "Helloss\n");
	string str1 = "Bryn";
	string str2 = " Ghiffar";
	string str3 = str1 + str2;
	cout << str3 << endl;

	Point p1(3, 2);
	Point p2(1, 5);
	Point p3 = p1 + p2;
	cout << p3 << endl;
	operator<<(cout, p1);
}
