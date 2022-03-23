#include <iostream>

// recursion
void f(int i) {
	// let n = i
	// space complexity: O(n)
	if (i == 1) {
		// base case
		std::cout << i << std::endl;
	} else if (i == 3) {
		// other base case...
		std::cout << i << std::endl;
	}
	else {
		// inductive case
		// do something
		std::cout << i << std::endl;
		f(i - 1);
	}
}

// n! = n * (n - 1)!
// 0! = 1

int factorial(int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}

// what is a fibonacci sequence?
// 0 1 1 2 3 5
// 1 2 3 4 5 6
// fib(i) = fib(i - 1) + fib(i - 2)
// when i == 1 return 0
// when i == 2 return 1
int fib(int i) {
	if (i == 1) return 0;
	if (i == 2) return 1;
	return fib(i - 1) + fib(i - 2);
}


// iterative version of the fib
int fib_it(int i) {
	int a = 0;
	int b = 1;
	if (i == 1) return a;
	if (i == 2) return b;
	int temp;
	for (;i > 2; i--) {
		temp = b;
		b += a;
		a = temp;
	}
	return b;
}

// finding the maximum
int max_rec(int* arr, const int length, int i) {
	if (i == length - 1) {
		return arr[length - 1];
	}
	else {
		int curr = arr[i];
		int next = max_rec(arr, length, i + 1);
		if (curr > next) {
			return curr;
		}
		else {
			return next;
		}
	}
}

// using recursion when dealing with linked lists
struct Node {
	int item;
	Node* next;
};

// printing linked lists using recursion
void print(Node* current) {
	if (current != NULL) {
		std::cout << current->item << " ";
		print(current->next);
	}
}

// solving the hanoi tower problem using recursion
void move_hanoi(int disk, int src, int aux, int trg) {
	if (disk == 1) {
		std::cout << "move disk " << disk << " from " << src << " to " << trg << std::endl;
	}
	else {
		move_hanoi(disk - 1, src, trg, aux);
		std::cout << "move disk " << disk << " from " << src << " to " << trg << std::endl;
		move_hanoi(disk - 1, aux, src, trg);
	}
}


int main()
{
	std::cout << factorial(4) << std::endl;
	std::cout << "fib: " << fib(6) << std::endl;
	std::cout << "fib_it: " << fib_it(6) << std::endl;

	const int LENGTH = 5;
	int* arr = new int[LENGTH];
	arr[0] = 3;
	arr[1] = 1;
	arr[2] = 4;
	arr[3] = 10;
	arr[4] = 5;
	std::cout << "max_rec: " << max_rec(arr, LENGTH, 0) << std::endl;

	Node* head = new Node();
	head->item = 5;
	head->next = new Node();
	head->next->item = 4;
	head->next->next = new Node();
	head->next->next->item = 3;
	head->next->next->next = new Node();
	head->next->next->next->item = 12;
	head->next->next->next->next = new Node();
	head->next->next->next->next->item = 10;
	head->next->next->next->next->next = NULL;
	print(head);
	std::cout << std::endl;
	head = NULL;
	print(head);
	move_hanoi(4, 1, 2, 3);

}