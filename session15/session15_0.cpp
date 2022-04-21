#include <iostream>
#include "queueADT.h"
#include "queueType.h"

int main()
{
	// queueADT<int> q;
	queueType<int> a(4);
	a.addQueue(1);
	a.addQueue(2);
	a.addQueue(3);
	a.addQueue(4);
	for (int i = 0; i < 4; i++) {
		std::cout << a.front() << " ";
		a.deleteQueue();
	}
	std::cout << std::endl;
	a.addQueue(5);
	std::cout << a.front() << " ";
	a.deleteQueue();
}
