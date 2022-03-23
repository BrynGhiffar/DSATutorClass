#ifndef _LINKEDLISTTYPE_H_
#define _LINKEDLISTTYPE_H_
#include <iostream>
using std::cout;
using std::endl;

//Definition of the node
template <class Type>
struct nodeType
{
	Type info;
	nodeType<Type>* link;
};

//***********************************************************
// Author: D.S. Malik
//***********************************************************
template <class Type>
class linkedListType
{
public:
	void print() const;
	//Function to output the data contained in each node.
	//Postcondition: none
	int length() const;
	//Function to return the number of nodes in the list.
	//Postcondition: The value of count is returned.
	bool search(const Type& searchItem) const;
	//Function to determine whether searchItem is in the list.
	//Postcondition: Returns true if searchItem is in the list,
	//otherwise the value false is returned.
	void insertFirst(const Type& newItem);
	//Function to insert newItem at the beginning of the list.
	//Postcondition: first points to the new list, newItem is
	//inserted at the beginning of the list, last points to
	//the last node in the list, and count is incremented by
	//1.
	void deleteNode(const Type& deleteItem);
	//Function to delete deleteItem from the list.
	//Postcondition: If found, the node containing deleteItem is
	//deleted from the list. first points to the first node,
	//last points to the last node of the updated list, and
	//count is decremented by 1.
	linkedListType();
	//default constructor
	//Initializes the list to an empty state.
	//Postcondition: first = NULL, last = NULL, count = 0;
	linkedListType(const linkedListType<Type>& otherList);
	//copy constructor
	~linkedListType();
	//destructor
	//Deletes all the nodes from the list.
	//Postcondition: The list object is destroyed.
protected:
	int count; //variable to store the number of list elements
					//
	nodeType<Type>* first; //pointer to the first node of the list
	nodeType<Type>* last; //pointer to the last node of the list
};

template <class Type>
linkedListType<Type>::linkedListType() {
	this->first = NULL;
	this->last = NULL;
	this->count = 0;
}

template <class Type>
linkedListType<Type>::~linkedListType() {
	nodeType<Type>* current = this->first;
	nodeType<Type>* toBeDeleted;
	while (current != NULL) {
		toBeDeleted = current;
		current = current->link;
		delete toBeDeleted;
	}
	this->first = NULL;
	this->last = NULL;
	this->count = 0;
}

template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList) {
	nodeType<Type>* current = otherList.first;
	if (current != NULL) {
		nodeType<Type>* currentThis = new nodeType<Type>();
		currentThis->info = current->info;
		current = current->next;
		this->first = currentThis;
		while (current != NULL) {
			currentThis->next = new nodeType<Type>();
			currentThis->next->info = current->info;
			current = current->next;
			currentThis = currentThis->next;
		}
		this->last = currentThis;
		this->last->next = NULL;
	}
	this->count = otherList.count;
}

template <class Type>
void linkedListType<Type>::insertFirst(const Type& newItem) {
	if (this->first == NULL) {
		this->first = new nodeType<Type>();
		this->first->info = newItem;
		this->last = this->first;
		this->first->link = NULL;
	}
	else {
		nodeType<Type>* next = this->first;
		this->first = new nodeType<Type>();
		this->first->info = newItem;
		this->first->link = next;
	}
	count++;
}

template <class Type>
void linkedListType<Type>::deleteNode(const Type& deleteItem) {
	if (this->first == NULL) return;
	if (this->first->info == deleteItem) {
		nodeType<Type>* next = this->first->link;
		if (next == NULL) this->last = NULL;
		delete this->first;
		this->first = next;
		count--;
		return;
	}
	nodeType<Type>* current = this->first;
	while ((current->link != NULL) && (current->link->info != deleteItem)) {
		current = current->link;
	}
	if (current->link != NULL && current->link->info == deleteItem) {
		nodeType<Type>* toBeDeleted = current->link;
		current->link = current->link->link;
		if (current->link == NULL) {
			this->last = current;
		}
		else {
			this->last = current->link;
		}
		delete toBeDeleted;
		count--;
	}
}

template <class Type>
void linkedListType<Type>::print() const {
	nodeType<Type>* current = this->first;
	while (current != NULL) {
		cout << current->info << " ";
		current = current->link;
	}
	cout << endl;
}

template <class Type>
int linkedListType<Type>::length() const {
	return count;
}
//Function to return the number of nodes in the list.
//Postcondition: The value of count is returned.
template <class Type>
bool linkedListType<Type>::search(const Type& searchItem) const {
	bool found = false;
	nodeType<Type>* current = this->front;
	while (current != NULL) {
		if (current->info == searchItem)
			found = true;
		current = current->next;
	}
	return found;
}
#endif
