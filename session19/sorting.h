#ifndef _SORTING_H_
#define _SORTING_H_
#include <vector>
#include <iostream>
#include <chrono>
int min_index(std::vector<int>& arr, int start, int end);

template <typename T>
void print(const std::vector<T>& arr) {
    std::cout << "[ ";
    for (T item : arr) {
        std::cout << item << " ";
    }
    std::cout << "]\n";
}

template <typename T>
struct Node {
    T item;
    Node<T>* next;
};

template <typename T>
void print(const Node<T>* head) {
    const Node<T>* current = head;
    std::cout << "LL [ ";
    while (current != NULL) {
        if (current != NULL) {
			std::cout << current->item << " ";
			current = current->next;
        }
    }
    std::cout << "]\n";
}

void benchmark(void (*sort)(std::vector<int>&, const bool));
int randrange(int lo, int hi);
Node<int>* generate_random_ll(int size);
Node<int>* selection_sort_ll(Node<int>* head, const bool DEBUG_MODE = true);
Node<int>* insertion_sort_ll(Node<int>* head, const bool DEBUG_MODE = true);

void selection_sort(std::vector<int>& arr, const bool DEBUG_MODE = true);
void insertion_sort(std::vector<int>& arr, const bool DEBUG_MODE = true);
void quick_sort(std::vector<int>& arr, const bool DEBUG_MODE = true);
void quick_sort_aux(std::vector<int>& arr, int s, int e, const bool DEBUG_MODE = true);
std::pair<int, int> partition(std::vector<int>& arr, int s, int e, int p, const bool DEBUG_MODE = true);
void merge_sort(std::vector<int>& arr, const bool DEBUG_MODE = true);
void merge_sort_aux(std::vector<int>& arr, std::vector<int>& temp, int s, int e, const bool DEBUG_MODE = true);
void merge(std::vector<int>& arr, std::vector<int>& temp, int s, int m, int e);
#endif
