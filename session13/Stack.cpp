// #include "Stack.h"
// 
// template <typename T>
// Stack<T>::Stack(int size) : MAX_SIZE(size) {
// 	length = 0;
// 	arr = new T[size];
// }
// 
// template <typename T>
// Stack<T>::Stack(const Stack<T>& stack) : MAX_SIZE(stack.MAX_SIZE) {
// 	length = stack.length;
//  	arr = new T[MAX_SIZE];
//  	for (int i = 0; i < stack.length; i++)
//  		arr[i] = stack.arr[i];
// }
// 
// template <typename T>
// const Stack<T>& Stack<T>::operator=(const Stack<T>& stack) {
// 	if (this != &stack) {
// 		MAX_SIZE = stack.MAX_SIZE;
// 		length = stack.length;
// 		delete[] arr;
// 		arr = new T[MAX_SIZE];
// 		for (int i = 0; i < stack.length; i++)
// 			arr[i] = stack.arr[i];
// 	}
// 	return *this;
// }
// 
// template <typename T>
// Stack<T>::~Stack() {
// 	// delete is for deallocating single variables
// 	delete[] arr;
// }
// 
// template <typename T>
// T Stack<T>::peek() const {
// 
// 	if (length > 0)
// 		return arr[length - 1];
// 	else
// 		return -1;
// }
// 
// template <typename T>
// void Stack<T>::push(const T& item) {
// 	if (length < MAX_SIZE) {
// 		arr[length] = item;
// 		length++;
// 	}
// }
// 
// template <typename T>
// T Stack<T>::pop() {
// 
// 	if (length > 0) {
// 		length--;
// 		return arr[length];
// 	}
// 	else {
// 		return -1;
// 	}
// }
// 
// template <typename T>
// int Stack<T>::size() const {
// 	return length;
// }
// 
// template <typename T>
// bool Stack<T>::empty() const {
// 	return length == 0;
// }
// 
// template <typename T>
// std::ostream& operator<<(std::ostream& os, const Stack<T>& stack) {
// 	os << "Stack([";
// 	for (int i = 0; i < stack.length; i++) {
// 		os << stack.arr[i] << ", ";
// 	}
// 	os << "], " << "length=" << stack.length << ")";
// 	return os;
// }
