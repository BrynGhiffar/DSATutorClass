#ifndef _QUEUETYPE_H_
#define _QUEUETYPE_H_

#include "queueADT.h"
#include <iostream>

template <class Type>
class queueType : public queueADT<Type> {
public:
	queueType(int size = 100);
	queueType(const queueType<Type>& q);
	const queueType<Type>& operator=(const queueType<Type>& q);
	bool isEmptyQueue() const;
	bool isFullQueue() const;
	void initializeQueue();
	Type front() const;
	Type back() const;
	void addQueue(const Type& queueElement);
	void deleteQueue();
	void moveNthFront(int n);
	template <typename T>
	friend std::ostream& operator<<(std::ostream& os, const queueType<T>& q);
	~queueType();

private:
	int maxQueueSize;
	int count;
	int queueFront;
	int queueRear;
	Type* arr;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const queueType<T>& q) {
	os << "queueType([";
	for (int i = 0; i < q.count; i++) {
		os << q.arr[(q.queueFront + i) % q.count] << ", ";
	}
	os << "], maxQueueSize = " << q.maxQueueSize << ", "
		<< "count = " << q.count << ", "
		<< "queueFront = " << q.queueFront << ", "
		<< "queueRear = " << q.queueRear;
	os << ")";
	return os;
}

template <typename Type>
queueType<Type>::queueType(const queueType<Type>& q) {
	std::cout << "YOU USED THE COPY CONSTRUCTOR\n";
	maxQueueSize = q.maxQueueSize;
	count = q.count;
	queueFront = q.queueFront;
	queueRear = q.queueRear;
	arr = new Type[maxQueueSize];
	for (int i = 0; i < maxQueueSize; i++) {
		arr[i] = q.arr[i];
	}
}

// fixed move front implementation
template <typename Type>
void queueType<Type>::moveNthFront(int n) {
	if (n > count) return;
	int temp;
	for (int i = n - 1; i > 0; i--) {
		temp = arr[(queueFront + i) % count];
		arr[(queueFront + i) % count] = arr[(queueFront + i - 1) % count];
		arr[(queueFront + i - 1) % count] = temp;
	}
}

template <typename Type>
const queueType<Type>& queueType<Type>::operator=(const queueType<Type>& q) {
	std::cout << "YOU USED THE ASSIGNMENT OPERATOR\n";
	if (this == &q) return *this;
	delete[] arr;
	maxQueueSize = q.maxQueueSize;
	count = q.count;
	queueFront = q.queueFront;
	queueRear = q.queueRear;
	arr = new Type[maxQueueSize];
	for (int i = 0; i < maxQueueSize; i++) {
		arr[i] = q.arr[i];
	}
	return *this;
}

template <typename Type>
void queueType<Type>::initializeQueue() {
	maxQueueSize = 0;
	count = 0;
	queueFront = 0;
	queueRear = 0;
}

template <typename Type>
queueType<Type>::queueType(int size) : maxQueueSize(size), count(0), queueFront(0), queueRear(0) {
	arr = new Type[maxQueueSize];
}

template <typename Type>
queueType<Type>::~queueType() {
	delete[] arr;
}

template <typename Type>
bool queueType<Type>::isFullQueue() const {
	return (count == maxQueueSize);
}

template <typename Type>
bool queueType<Type>::isEmptyQueue() const {
	return (count == 0);
}

template <typename Type>
void queueType<Type>::addQueue(const Type& queueElement) {
	if (!isFullQueue()) {
		arr[queueRear] = queueElement;
		queueRear = (queueRear + 1) % maxQueueSize;
		count++;
	}
}

template <typename Type>
void queueType<Type>::deleteQueue() {
	if (!isEmptyQueue()) {
		queueFront = (queueFront + 1) % maxQueueSize;
		count--;
	}
}

template <typename Type>
Type queueType<Type>::front() const {
	return arr[queueFront];
}

template <typename Type>
Type queueType<Type>::back() const {
	return arr[queueRear - 1];
}


#endif