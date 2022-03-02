// Learning Materials
// * what is a pointer?
// * how do you declare a pointer?
// * dereferencing operator
// * NULL constant
// * using 'new' to allocate memory in the heap
// * using 'new' to create an array of values
// * using 'delete' to deallocate
// * using 'delete []' to deallocate an array
// * pointer arithmetic and arrays
// * creating a matrix (array of arrays) using pointers
// * deallocating a matrix
// * passing pointers to functions
// * classes and pointers things to be aware of

#include <iostream>
#include <string>

void wasteMemory() {
	// if yo don't deallocate memory
	// you are going to have a memory leak
	int* p = new int[1000];
	delete[] p;
}

using namespace std;
int main()
{
	// How to declare a pointer
	int* intPointer;
	char* chPointer;
	string* myString;

	// various notations of declaring pointers
	int *intPointerFront;
	int * intPointerMid;

	int val = 10;
	// this means declaring a pointer and int
	int* c, d;
	// this means declaring two pointers
	int *a, *b;
	a = &val;
	b = &val;
	cout << &val << endl;
	cout << val << endl;
	*a = 12;
	cout << &val << endl;
	cout << val << endl;
	int* p2 = NULL;
	p2 = 0;

	int* p3 = new int;
	*p3 = 10;
	cout << *p3 << endl;
	cout << p3 << endl;
	int size = 3;
	// int arr[size] = { 1, 2, 3 };
	int* p4 = new int[size];
	bool arr[2] = { true, false };

	for (int i = 0; i < size; i++) {
		p4[i] = i * 2;
	}
	for (int i = 0; i < size; i++) {
		cout << p4[i] << ' ';
	}
	cout << '\n';

	delete p3;
	delete[] p4;

	// you can copy the address a pointer
	// is pointing to by assigning it.
	int x2 = 10;
	int* p5 = &x2;
	int* p6;
	p6 = p5;

	cout << "p6 == p5 : " << boolalpha << (p6 == p5) << endl;
	cout << "p6 != p5 : " << boolalpha << (p6 != p5) << endl;

	int size0 = 10;
	int* arr0 = new int[size0];
	arr0[0] = 123;
	cout << *arr0 << endl;

	// arrays are basically like pointers
	arr0[3] = 101;
	arr0[1] = 345;
	int arr34[5];
	int* p7 = arr0;
	cout << p7 << endl;
	cout << p7 + 3 << endl;
	cout << &(arr0[3]) << endl;
	cout << *(p7 + 1) << endl;
	cout << arr0[1] << endl;

	for (int* pt = arr0; pt != arr0 + size0; pt++) {
		*pt = 123;
	}

	for (int* pt = arr0; pt != arr0 + size0; pt++) {
		cout << *pt << ' ';
	}
	cout << '\n';
	delete[] arr0;
	cout << "----\n";
	// cout << *arr0 << endl;
	arr0 = NULL;
	p7 = NULL;

	int mat_size = 3;
	int** matrix = new int* [mat_size];
	for (int i = 0; i < mat_size; i++) {
		matrix[i] = new int[mat_size];
	}

	// you can populate your matrix
	for (int i = 0; i < mat_size; i++) {
		for (int j = 0; j < mat_size; j++) {
			matrix[i][j] = j + 5 * i;
		}
	}

	// print these values
	cout << "hello\n";
	for (int i = 0; i < mat_size; i++) {
		for (int j = 0; j < mat_size; j++) {
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}

	for (int i = 0; i < mat_size; i++)
		delete[] matrix[i];
	delete[] matrix;


}