#ifndef _QUEUETYPE_H_
#define _QUEUETYPE_H_

template <class Type>
class queueType : public queueADT<Type> {
public:
	queueType(int size = 100);
	bool isEmptyQueue() const;
	bool isFullQueue() const;
	void initializeQueue();
	Type front() const;
	Type back() const;
	void addQueue(const Type& queueElement);
	void deleteQueue();
	~queueType();
private:
	int maxQueueSize;
	int count;
	int queueFront;
	int queueRear;
	Type* arr;
};

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
