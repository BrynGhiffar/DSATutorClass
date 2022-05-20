#include "test_sorting.h"

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

void test_selection_sort_ll() {
    srand(time(0));
    Node<int>* head = generate_random_ll(10);
    print(head);
    head = selection_sort_ll(head);
    print(head);
}

void test_insertion_sort_ll() {
    srand(time(0));
    Node<int>* head = generate_random_ll(10);
    print(head);
    head = insertion_sort_ll(head);
    print(head);
}

void test_benchmark() {
    std::cout << "---selection sort---\n";
    benchmark(selection_sort);
    std::cout << "---insertion sort---\n";
    benchmark(insertion_sort);
    std::cout << "---quick sort---\n";
    benchmark(quick_sort);
    std::cout << "---merge sort---\n";
    benchmark(merge_sort);
}