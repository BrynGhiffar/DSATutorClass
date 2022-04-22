#include <iostream>
#include "queueType.h"
#include <stack> // for question 3
#include <string> // for question 3

// The answer to question 3
bool isPalindrome(const std::string& s) {
	// What is a palindrome?
	// A palindrome is a string read the same forwards as it is backwards
	queueType<char> q(s.size());
	std::stack<char> st;
	for (char c : s) {
		q.addQueue(c);
		st.push(c);
	}
	bool palindrome = true;
	while (!st.empty()) {
		if (st.top() != q.front()) {
			palindrome = false;
			break;
		}
		st.pop();
		q.deleteQueue();
	}
	return palindrome;
}

void test_copyconstructor() {
	queueType<int> q;
	q.addQueue(10);
	q.addQueue(9);
	q.addQueue(8);
	{
		queueType<int> b(q);
	}
	queueType<int> a(q);
	for (int i = 0; i < 3; i++) {
		std::cout << q.front() << " " << a.front() << "\n";
		q.deleteQueue();
		a.deleteQueue();
	}
	std::cout << std::endl;
	std::cout << std::boolalpha << q.isEmptyQueue() << "\n";
	std::cout << std::boolalpha << a.isEmptyQueue() << "\n";
}

void test_assignment() {
	queueType<int> q;
	q.addQueue(1);
	q.addQueue(2);
	q.addQueue(8);
	queueType<int> a; // does this use the copy constructor or the assignment operator?
	a = q;
	std::cout << a << std::endl;
	for (int i = 0; i < 3; i++) {
		std::cout << q.front() << " " << a.front() << "\n";
		q.deleteQueue();
		a.deleteQueue();
	}
	std::cout << std::endl;
	std::cout << std::boolalpha << q.isEmptyQueue() << "\n";
	std::cout << std::boolalpha << a.isEmptyQueue() << "\n";
}

void test_moven() {
	queueType<int> q(6);
	q.addQueue(1);
	q.addQueue(2);
	q.addQueue(3);
	q.deleteQueue();
	q.deleteQueue();
	q.deleteQueue();
	q.addQueue(1);
	q.addQueue(2);
	q.addQueue(3);
	q.addQueue(4);
	q.addQueue(5);
	q.addQueue(6);
	std::cout << q << "\n";
	q.moveNthFront(5);
	std::cout << q << "\n";
}

void test_isPalindrome() {
	std::cout << std::boolalpha << isPalindrome("racecar") << std::endl;
	std::cout << std::boolalpha << isPalindrome("a") << std::endl;
	std::cout << std::boolalpha << isPalindrome("abc") << std::endl;
	std::cout << std::boolalpha << isPalindrome("bob") << std::endl;
	std::cout << std::boolalpha << isPalindrome("tut tut") << std::endl;
	std::cout << std::boolalpha << isPalindrome("magic") << std::endl;
}

int main()
{
	// test_assignment();
	// test_moven();
	test_isPalindrome();
}
