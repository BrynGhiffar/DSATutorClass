// Learning materials
// * how to declare a class
// * constructors, multiple constructors and default parameters
// * destructors
// * member variables
// * member functions
// * this pointer
// * scope resolution operator
// * assignment operator copies the member variables
// * passing by reference vs passing by members
// * inheritance => public, private, protected, overriding base class functions
// * friend functions
// * operator overloading => member, non-member, overloading the stream insertion operator
// * function overloading
// * templates => function templates, class templates
#include <iostream>
#include <vector>

class Rectangle {
private:
	int width;
	int height;
public:
	Rectangle(int w, int h);
	// constructor asks for width and height
	Rectangle();
	// default constructor
	~Rectangle();
	// destructor
	void setWidth(int w);
	// width setter
	void setHeight(int h);
	// height setter
	int getWidth();
	// width getter
	int getHeight();
	// height getter
	void print();
	// prints the values of Rectangle
	// in simple words friend functions are normal methods
	// that can access private members of the class
	friend void doubleWidth(Rectangle& rect);
	friend std::ostream& operator<<(std::ostream& os, const Rectangle& rect);
};

class Box : private Rectangle {
private:
	int length;
public:
	Box(int w, int h, int l);
	void setLength(int l);
	int getLength();
	void print();
};

class BoxChild : public Box {
public:
	void foo() {
		// doesn't work when Box inherits Rectangle using private
		// print();
	}
};

Rectangle::Rectangle(int w, int h = 10) { // constructor 1
	std::cout << "A Rectangle is born! at " << this << "\n";
	(*this).width = w;
	(*this).height = h;
}
Rectangle::Rectangle() { // default constructor
	std::cout << "A Rectangle is born! and the default constructer was used.\n";
	(*this).width = 0;
	(*this).height = 0;
}
Rectangle::~Rectangle() {
	std::cout << "A Rectangle dies\n";
}
void Rectangle::setWidth(int w) {
	(*this).width = w;
}
void Rectangle::setHeight(int h) {
	(*this).height = h;
}
int Rectangle::getWidth() {
	return (*this).width;
}
int Rectangle::getHeight() {
	return (*this).height;
}
void Rectangle::print() {
	std::cout << "Rectangle{";
	std::cout << "width=" << (*this).width << ',';
	std::cout << "height=" << (*this).height << "}\n";
}

Box::Box(int w = 1, int h = 1, int l = 1) {
	Rectangle::Rectangle(w, h);
	length = l;
}

void Box::setLength(int l) {
	length = l;
}

int Box::getLength() {
	return length;
};

void Box::print() {
	// if you are overidding a function of the parent class
	// and you want to specify the parent class' method
	Rectangle::print();
	std::cout << "Box{";
	std::cout << "height=" << Rectangle::getHeight() << ',';
	std::cout << "width=" << Rectangle::getWidth() << ',';
	std::cout << "length=" << Box::getLength() << "}\n";
}

// passing by value
int getArea(Rectangle rect) {
	int area = rect.getHeight() * rect.getWidth();
	return area;
}

// passing by reference
void doubleWidth(Rectangle& rect) {
	rect.width = rect.width * 2;
}

void foo() {
	Rectangle rect(3, 5);
	std::cout << "Area: " << getArea(rect) << '\n';
}

void print(std::vector<int>& arr) {
	std::cout << "vector{";
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << ',';
	}
	std::cout << "}\n";
}

void print(int num) {
	std::cout << "Integer: " << num << '\n';
}

void print(int arr[], int size) {
	std::cout << "c-arr{";
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << ',';
	}
	std::cout << "}\n";
}

std::ostream& operator<<(std::ostream& os, const Rectangle& rect) {
	os << "Rectangle{";
	os << "width=" << rect.width << ',';
	os << "height=" << rect.height << "}";
	return os;
}

int main()
{
	Rectangle rect0(3);
	std::cout << rect0 << '\n';
	// Rectangle rect1;
	// rect0.print();
	// rect1.print();
	// rect0.width = 10;
	// rect0.height = 5;
	// rect0.setWidth(10);
	// rect0.setHeight(5);
	// rect1.width = 3;
	// rect1.height = 7;
	// rect1.setWidth(3);
	// rect1.setHeight(7);
	
	// rect0.print();
	// rect1.print();
	// foo();
	// doubleWidth(rect0);
	// rect0.print();

	// Box box0(3, 4, 5);
	// box0.print();
	std::vector<int> vec = { 1, 2, 3 };
	int arr[] = { 4, 5, 6 };
	int size = (sizeof arr) / sizeof(int);
	print(vec);
	print(arr, size);
	print(3);
}