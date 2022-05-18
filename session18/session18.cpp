#include <iostream>
#include <vector>
#include "sorting.h"

void test_selection_sort() {
    std::cout << "SELECTION SORT TEST\n";
    std::vector<int> arr = { 3, 1, 4, 1, 5, 9 };
    selection_sort(arr);
    print(arr);
}

void test_insertion_sort() {
    std::cout << "INSERTION SORT TEST\n";
    std::vector<int> arr = { 4, 7, 8, 6, 6, 8, 3, 2, 1, 7 };
    insertion_sort(arr);
    print(arr);
}

void test_quick_sort() {
    std::cout << "QUICK SORT TEST\n";
    std::vector<int> arr = { 4, 7, 8, 6, 6, 8, 3, 2, 1, 7 };
    quick_sort(arr);
    print(arr);
}


void test_merge_sort() {
    std::cout << "MERGE SORT TEST\n";
    std::vector<int> arr = { 4, 7, 1, 6, 6, 8, 3, 2, 1, 7 };
    // std::vector<int> arr = { 3, 2, 1 };
    merge_sort(arr);
    print(arr);
}

void test_partition() {
    std::cout << "QUICK SORT PARTITION TEST\n";
    std::vector<int> arr = {3, 3, 3, 3, 1, 4, 1, 5, 9 };
    std::pair<int, int> p = partition(arr, 0, arr.size(), 3);
    std::cout << "pivots: " << p.first << " " << p.second << "\n";
}

void test_merge() {
    std::cout << "MERGE SORT MERGE TEST\n";
    std::vector<int> arr = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    std::vector<int> temp(arr.size());
    merge(arr, temp, 0, 5, arr.size());
    print(arr);
}

int main()
{
    // test_selection_sort();
    // test_insertion_sort();
    // test_partition();
    test_quick_sort();
    // test_merge();
    // test_merge_sort();
}
