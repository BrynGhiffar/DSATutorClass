#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

int sequentialSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr.at(i) == target) return i;
    }
    return -1;
}

void sequentialSearch_test() {
    //                  0  1  2  3  4  5
    vector<int> arr = { 1, 2, 3, 4, 5, 6 };
    cout << sequentialSearch(arr, 4) << endl;
    cout << sequentialSearch(arr, 10) << endl;
}

// binary search 
// divide and conquer => reducing the problem into smaller parts
// 100
// 
// 2 3 4 10 12 45 100
// ^              ^
// 2 3 4 10 12 45 100
// ^     ^        ^

// 2 3 4 10 12 45 100
//          ^     ^

// 2 3 4 10 12 45 100
//          ^  ^  ^
// 2 3 4 10 12 45 100
//                ^
//                ^
// now we know that 3 is in the array

// When the element is not in the array
// 9
// 
// 2 3 4 10 12 45 100
// ^              ^
// 2 3 4 10 12 45 100
// ^     ^        ^
// 2 3 4 10 12 45 100
// ^   ^           
// 2 3 4 10 12 45 100
// ^ ^ ^           
// 2 3 4 10 12 45 100
//     ^           
//     ^
//     ^

// 2 3 4 10 12 45 100
//     ^ hi          
//       ^ lo
//     ^
// where you conclude that 8 is not in the array

// iterative implementation
int binarySearchIter(const vector<int>& arr, int target) {
    // time complexity: O(log n) (worst case)
    // can we achieve better time complexity: O(1), with hashing
    int lo = 0, hi = arr.size() - 1, mid;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        // mid = (hi + lo) / 2; // prone to overflows
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return -1;
}

void binarySearchIter_test() {
    cout << "--- binarySearchIter_test ---" << endl;
    vector<int> arr = { 2,3,4,10,12,45,100 };
    cout << binarySearchIter(arr, 45) << endl;
    cout << binarySearchIter(arr, 9) << endl;
}


int binarySearchRec(const vector<int>& arr, int target, int lo, int hi) {
    // 
    if (lo > hi) {
        return -1;
    }
	int mid = lo + (hi - lo) / 2;
	if (arr[mid] == target) return mid;
	else if (arr[mid] < target)
		return binarySearchRec(arr, target, mid + 1, hi);
	else
		return binarySearchRec(arr, target, lo, mid - 1);
}

void binarySearchRec_test() {
    cout << "binarySearchRec_test\n";
    vector<int> arr = { 2,3,4,10,12,45,100 };
    cout << binarySearchRec(arr, 45, 0, arr.size() - 1) << endl;
    cout << binarySearchRec(arr, 9, 0, arr.size() - 1) << endl;
}

// mid-square method => 10, 1011010010101 ** 2 => 10101 01011101011 10111
// folding => 101 011 011 101 => 101+011+011+101
// division (modular arithmetic) => 123456 % 20 (HTSize) => ?

int hashFunction(const string& val, int htsize) {
    // Assume hash function works in O(1) time complexity
    int sum = 0;
    for (int i = 0; i < val.size(); i++) {
        sum += static_cast<int>(val[i]);
    }
    return (sum) % htsize; // using modular arithmetic
}

void hashFunction_test() {
    cout << "--- hashFunction_test ---" << endl;
    vector<string> table(20);
    string s = "Hello";
    int i = hashFunction(s, table.size());
    table[i] = s;
    i = hashFunction(s, table.size());
    // check if table[i] == s
    cout << (table[i] == s) << endl;
}
// 7
// [][3][][][]
//    7

// collision resolution methods
// open addressing (closed hashing)
// linear probing
// quadratic probing
// chaining (open hashing)

int main()
{
    sequentialSearch_test();
    binarySearchIter_test();
    binarySearchRec_test();
    hashFunction_test();
}
