// Don't forget your header guards
#ifndef _LINKEDSTACKTYPE_H_
#define _LINKEDSTACKTYPE_H_

#include <iostream>

// a template node for a template linked stack
template <typename T>
struct NodeType {
	T item;
	NodeType<T>* next;
};

template <typename T>
class LinkedStackType {
private:
	int length;
	NodeType<T>* top;
public:
	LinkedStackType();
	void push(const T& item);
	T pop();
	T peek() const;
	const LinkedStackType<T>& operator=(const LinkedStackType<T>& stack);
	
	template <typename K>
	friend std::ostream& operator<<(std::ostream& os, const LinkedStackType<K>& stack);
	~LinkedStackType();
};

template <typename T>
LinkedStackType<T>::LinkedStackType() {
	length = 0;
	top = NULL;
}

template <typename T>
void LinkedStackType<T>::push(const T& item) {
	// creating the new node
	NodeType<T>* new_node = new NodeType<T>();
	new_node->item = item;
	
	// connect the node with the old linked list
	new_node->next = top;
	top = new_node;
	length++;
}

template <typename T>
T LinkedStackType<T>::pop() {
	// Because when top is null the stack is empty, we can't do pop elements
	// from the stack
	if (top != NULL) {

		T item = top->item;
		NodeType<T>* to_be_deleted = top;
		top = top->next;
		delete to_be_deleted;
		length--;
		return item;
	}
	throw "Stack is empty, cannot pop from an empty stack\n";
}

template <typename T>
T LinkedStackType<T>::peek() const {
	if (top != NULL) return top->item;
	throw "Stack is empty, there is nothing to peek\n";
}

template <typename T>
LinkedStackType<T>::~LinkedStackType() {
	NodeType<T>* deleteme;
	while (top != NULL) {
		deleteme = top;
		top = top->next;
		delete deleteme;
	}
}

template <typename T>
const LinkedStackType<T>& LinkedStackType<T>::operator=(const LinkedStackType<T>& stack) {
	if (this != &stack) {
		length = 0;
		
		// destroy stack elements
		NodeType<T>* deleteme;
		while (top != NULL) {
			deleteme = top;
			top = top->next;
			delete deleteme;
		}
		NodeType<T>* currentFrom = stack.top;
		NodeType<T>* currentTo = NULL;
		while (currentFrom != NULL) {
			// LinkedStackType::push(currentFrom->item);
			// currentFrom = currentFrom->next;
			if (currentTo == NULL) {
				currentTo = new NodeType<T>();
				currentTo->item = currentFrom->item;
				currentFrom = currentFrom->next;
				top = currentTo;
			}
			else {
				currentTo->next = new NodeType<T>();
				currentTo->next->item = currentFrom->item;
				currentFrom = currentFrom->next;
				currentTo = currentTo->next;
			}
		}
	}
	return *this;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedStackType<T>& stack) {
	NodeType<T>* current = stack.top;
	os << "Stack([";
	while (current != NULL) {
		os << current->item << ", ";
		current = current->next;
	}
	os << "], size = " << stack.length << ")";
	return os;
}
#endif