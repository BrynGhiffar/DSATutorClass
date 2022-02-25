// Learning materials:
// * class templates
// * using namespace
// * initializer list
// * multi-file compilation
//      * writing a header file
//      * using #ifndef, #define and #endif pre-processor
// * Exercises

#include <iostream>
#include <vector>

const int CAPACITY = 10;

// suppose T = int
// suppose T = std::string
template <typename T>
class List {
	T arr[CAPACITY]; // int arr[CAPACITY];
public:
	List() {
		for (int i = 0; i < CAPACITY; i++)
			arr[i] = 0;
	}
	T operator[](int idx) const;
	// T get(int idx) const;
	// T& operator[](int idx);
	void set(int idx, T item);
	void print() const;
};

template <typename T>
T List<T>::operator[](int idx) const {
	if ((idx >= 0) && (idx < CAPACITY))
		return arr[idx];
	else
		std::cout << "List access error\n";
}

// template <typename T>
// T& List<T>::operator[](int idx) {
// 	if ((idx >= 0) && (idx < CAPACITY))
//		return arr[idx];
//	else
//		std::cout << "List access error\n";
//}

using namespace std;
// only makes cout available you still have to do std:: for the others
// using std::cout;

template <typename T>
void List<T>::set(int idx, T item) {
	if ((idx >= 0) && (idx < CAPACITY))
		arr[idx] = item;
	else
		cout << "List access error\n";
}

template <typename T>
void List<T>::print() const {
	cout << "List[";
	for (int i = 0; i < CAPACITY; i++)
		cout << List<T>::operator[](i) << ", ";
	cout << "]\n";
}


int main()
{
	List<int> arr;
	int a = 2;
	int& b = a;
	// arr[0] = 10;
	// arr[2] = 12;
	arr.set(2, 12);
	arr.print();
	cout << arr[2] << "\n";
}