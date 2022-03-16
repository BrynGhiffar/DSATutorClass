#include <iostream>

struct LinkedListNode {
    int data;
    LinkedListNode* next;
};

void printLinkedList(LinkedListNode* front) {
    // Time complexity: O(n), where n is the length of the LinkedList
    LinkedListNode* current = front;
    // std::cout << current->data << " ";
    // current = current->next;
    while (current != NULL) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}

LinkedListNode* appendLinkedList(LinkedListNode* front, int item) {
    if (front == NULL) {
        front = new LinkedListNode();
        front->data = item;
        return front;
    }
    LinkedListNode* current = front;

    // getting the last node
    // time complexity: O(n)
    while (current->next != NULL) {
        current = current->next;
    }
    
    // creating the node for the item to be inserted
    current->next = new LinkedListNode();
    current->next->data = item;
    current->next->next = NULL;
    return front;
}

LinkedListNode* popLinkedList(LinkedListNode* front) {
    LinkedListNode* current = front;
    if (current == NULL) {
         return NULL;
    }
    if (current->next == NULL) {
        LinkedListNode* toBeDeleted = current;
        delete toBeDeleted;
        return NULL;
    }
    while (current->next->next != NULL) {
        current = current->next;
    }
    LinkedListNode* toBeDeleted = current->next;
    delete toBeDeleted;
    current->next = NULL;
    return front;
}


int main()
{
    LinkedListNode* front = NULL;
    front = popLinkedList(front);
    // front->data = 10;
    // front->next = new LinkedListNode();
    // front->next->data = 12;
    // front->next->next = NULL;
    // front->next->next = new LinkedListNode();
    // printLinkedList(front);
    front = appendLinkedList(front, 9);
    front = appendLinkedList(front, 19);
    front = appendLinkedList(front, 20);
    printLinkedList(front);
    front = popLinkedList(front);
    front = popLinkedList(front);
    front = popLinkedList(front);
    printLinkedList(front);
}