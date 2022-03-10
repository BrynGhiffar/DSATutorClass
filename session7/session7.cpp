// Learning Materials - STL containers
// * introducing vectors
// * various ways to instantiate vectors
// * begin and end to tell a vectors positions
// * class methods of the vector class
// * iterators, these are mostly the same as pointers
// * output stream iterator
// * introducing deques
//      similar to vectors but you can insert and pop
//      from the front as well
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <deque>

int main()
{
	// uses default constructor
	std::vector<std::string> myStrs0;
	std::cout << myStrs0.size() << std::endl;

	std::vector<std::string> myStrs1(10);
	std::cout << myStrs1.size() << std::endl;

	std::vector<std::string> myStrs2(10, "CAT");
	for (std::string s : myStrs2) {
		std::cout << s << " ";
	}
	std::cout << std::endl;

	// std::vector<std::string> myStrs3(myStrs2);
	std::vector<std::string> myStrs3 = myStrs2;
	for (std::string s : myStrs3) {
		std::cout << s << " ";
	}
	std::cout << std::endl;

	std::vector<std::string> myStrs4(myStrs3.begin(), myStrs3.begin() + 2);
	for (std::string s : myStrs4) {
		std::cout << s << " ";
	}
	std::cout << std::endl;

	// random access with vectors
	std::cout << myStrs4[0] << std::endl;
	myStrs4.at(1) = "RAT";
	std::cout << myStrs4.at(1) << std::endl;

	myStrs4.at(myStrs4.size() - 1) = "CAT BACK";
	myStrs4.at(0) = "CAT FRONT";

	// accessing first and last elements
	std::cout << myStrs4.front() << std::endl;
	std::cout << myStrs4.back() << std::endl;

	// removes all elements in the vector, you now have an empty vector
	myStrs4.clear();
	std::cout << "size: " << myStrs4.size() << std::endl;

	std::cout << "myStrs3.size() = " << myStrs3.size() << std::endl;
	myStrs3.erase(myStrs3.begin() + 1, myStrs3.begin() + 3);
	std::cout << "myStrs3.size() = " << myStrs3.size() << std::endl;
	myStrs3.at(2) = "BAT";
	for (std::string s : myStrs3) {
		std::cout << s << " ";
	}
	std::cout << std::endl;
	myStrs3.erase(myStrs3.begin() + 2);
	for (std::string s : myStrs3) {
		std::cout << s << " ";
	}
	std::cout << std::endl;

	myStrs3.insert(myStrs3.begin() + 1, "Bunnies");
	for (std::string s : myStrs3) {
		std::cout << s << " ";
	}
	std::cout << std::endl;

	myStrs3.insert(myStrs3.begin(), 5, "Bunnies");
	for (std::string s : myStrs3) {
		std::cout << s << " ";
	}
	std::cout << std::endl;

	std::vector<std::string> toBeInserted = { "HAT", "MAT" };
	myStrs3.insert(myStrs3.end(), toBeInserted.begin(), toBeInserted.end() - 1);
	for (std::string s : myStrs3) {
		std::cout << s << " ";
	}
	std::cout << std::endl;

	myStrs3.push_back("Crazy");
	std::cout << myStrs3[myStrs3.size() - 1] << std::endl;
	
	std::cout << "myStrs3.size() = " << myStrs3.size() << std::endl;
	myStrs3.pop_back();
	std::cout << "myStrs3.size() = " << myStrs3.size() << std::endl;
	for (std::string s : myStrs3) {
		std::cout << s << " ";
	}
	std::cout << std::endl;

	myStrs3.resize(5);
	for (std::string s : myStrs3) {
		std::cout << s << " ";
	}
	std::cout << std::endl;

	std::cout << std::boolalpha << myStrs3.empty() << std::endl;

	std::vector<std::string>::iterator it = myStrs3.begin();
	*it = "SAT";
	std::cout << *it << std::endl;
	for (std::string s : myStrs3) {
		std::cout << s << " ";
	}
	std::cout << std::endl;
	it++;
	std::cout << *it << std::endl;
	it--;
	std::cout << *it << std::endl;

	std::vector<int> myInts = { 1, 2, 3 };
	std::vector<int> myIntsTarget(4, -1);
	std::copy(myInts.begin(), myInts.end(), myIntsTarget.begin() + 1);
	for (int e : myIntsTarget) {
		std::cout << e << " ";
	}
	std::cout << std::endl;

	std::ostream_iterator<std::string> stringOut(std::cout, " ");
	std::copy(myStrs3.begin(), myStrs3.end(), stringOut);
	std::cout << std::endl;

	// Deques
	std::deque<char> deq;
	deq.push_front('r');
	deq.push_back('y');
	deq.push_front('b');
	deq.push_back('n');
	std::cout << "deq.size() = " << deq.size() << std::endl;
	
	std::ostream_iterator<char> charOut(std::cout, " ");
	std::copy(deq.begin(), deq.end(), charOut);
	std::cout << std::endl;

	std::cout << deq.at(0) << std::endl;
	std::cout << deq[1] << std::endl;
}