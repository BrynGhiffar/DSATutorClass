#include "sorting.h"

void benchmark(void (*sort)(std::vector<int>&, const bool)) {
    std::vector<int> sizes = { 10, 100, 1000, 10000 };

    std::cout << "size\ttime elapsed\n";
    for (int size : sizes) {

        // generate random array
        std::vector<int> arr(size);
        for (int i = 0; i < size; i++) arr[i] = randrange(1, 9);

        // Start benchmarking
        auto start = std::chrono::steady_clock::now();
        sort(arr, false);
        auto end = std::chrono::steady_clock::now();

        std::cout << size << "\t" <<
            std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
            << "ns" << std::endl;
    }
}

// Generates random integer between given range
int randrange(int lo, int hi) {
    return lo + (rand() % (hi - lo + 1));
}

// Generates a random linked list
Node<int>* generate_random_ll(int size) {
    if (size <= 0) return NULL;
    Node<int>* head = new Node<int>;
    head->item = randrange(1, 10);
    Node<int>* current = head;
    while (size > 1) {
		current->next = new Node<int>;
		current->next->item = randrange(1, 9);
        current->next->next = NULL;
		current = current->next;
        size--;
    }
    return head;
}

Node<int>* pop_min_node(Node<int>* head) {
    if (head == NULL)
        return NULL;
    //  3 1 4 1 5
    //  ^ ^
    //          ^ ^

    // 3 4 1 5
    // with 1 still 1 -> 4
    // but then 1 -> head and so 1 -> 3 as a result
    // 1 3 4 1 5
    Node<int>* pre_min_node = NULL;
    Node<int>* min_node = head;
    Node<int>* pre_current = head;
    Node<int>* current = head->next;
    while (current != NULL) {
        if (current->item < min_node->item) {
            min_node = current;
            pre_min_node = pre_current;
        }
        current = current->next;
        pre_current = pre_current->next;
    }
    // extract min node
    if (pre_min_node != NULL) {
        pre_min_node->next = min_node->next;
    }
    // Edge case if min_node == head
    if (min_node != head)
		min_node->next = head;
    return min_node;
}

// return the head pointer
Node<int>* selection_sort_ll(Node<int>* head, const bool DEBUG_MODE) {
    Node<int>* new_head = pop_min_node(head);
    Node<int>* current = new_head;
    if (DEBUG_MODE)
        print(new_head);
    while (current != NULL) {
      current->next = pop_min_node(current->next);
      current = current->next;
      if (DEBUG_MODE)
		  print(new_head);
    }
    return new_head;
}

Node<int>* insertion_sort_ll(Node<int>* head, const bool DEBUG_MODE) {

    Node<int>* lastInOrder;
    Node<int>* firstOutOfOrder;
    Node<int>* current;
    Node<int>* trailCurrent;
    
    lastInOrder = head;
    if (head == NULL)
        return NULL;
    else if (head->next == NULL)
        return head;
    else {
        while (lastInOrder->next != NULL) {
            firstOutOfOrder = lastInOrder->next;
            if (firstOutOfOrder->item < head->item) {
                lastInOrder->next = firstOutOfOrder->next;
                firstOutOfOrder->next = head;
                head = firstOutOfOrder;
            }
            else {
                trailCurrent = head;
                current = head->next;

                while (current->item < firstOutOfOrder->item) {
                    trailCurrent = current;
                    current = current->next;
                }

                if (current != firstOutOfOrder) {
                    lastInOrder->next = firstOutOfOrder->next;
                    firstOutOfOrder->next = current;
                    trailCurrent->next = firstOutOfOrder;
                }
                else {
                    lastInOrder = lastInOrder->next;
                }
            }
            if (DEBUG_MODE)
                print(head);
        }
    }
    return head;
}



// █▀ █▀▀ █░░ █▀▀ █▀▀ ▀█▀ █ █▀█ █▄░█   █▀ █▀█ █▀█ ▀█▀
// ▄█ ██▄ █▄▄ ██▄ █▄▄ ░█░ █ █▄█ █░▀█   ▄█ █▄█ █▀▄ ░█░
int min_index(std::vector<int>& arr, int start, int end) {
    // Returns the index of the minimum value in the array
    int mi = start;
    for (int i = start + 1; i < end; i++) {
        if (arr[i] < arr[mi]) mi = i;
    }
    return mi;
}

void selection_sort(std::vector<int>& arr, const bool DEBUG_MODE) {
    int mi, tmp;
    for (int s = 0; s < arr.size(); s++) {
        mi = min_index(arr, s, arr.size());
        std::swap(arr[mi], arr[s]);
//        tmp = arr[mi];
//        arr[mi] = arr[s];
//        arr[s] = tmp;
        if (DEBUG_MODE)
			print(arr);
    }
}

// █ █▄░█ █▀ █▀▀ █▀█ ▀█▀ █ █▀█ █▄░█   █▀ █▀█ █▀█ ▀█▀
// █ █░▀█ ▄█ ██▄ █▀▄ ░█░ █ █▄█ █░▀█   ▄█ █▄█ █▀▄ ░█░
void insertion_sort(std::vector<int>& arr, const bool DEBUG_MODE) {
	for (int s = 1; s < arr.size(); s++) {
		int j = s;
		while (j > 0 && arr[j] < arr[j - 1]) {
			// Swap arr[j] and arr[j - 1]
			// tmp = arr[j];
			// arr[j] = arr[j - 1];
			// arr[j - 1] = tmp;
			std::swap(arr[j], arr[j - 1]);
			j--;
		}
        if (DEBUG_MODE)
			print(arr);
	}
}


// █▀█ █░█ █ █▀▀ █▄▀   █▀ █▀█ █▀█ ▀█▀
// ▀▀█ █▄█ █ █▄▄ █░█   ▄█ █▄█ █▀▄ ░█░
std::pair<int, int> partition(std::vector<int>& arr, int s, int e, int p, const bool DEBUG_MODE) {
    // Dutch Partition Algorithm
    // dutch flag problem
    int blue = s;
    int white = s;
    int red = e - 1;
    while (white <= red) {
        if (arr[white] < p) {
            std::swap(arr[white], arr[blue]);
            blue++;
            white++;
        }
        else if (arr[white] == p) {
            white++;
        }
        else {
            std::swap(arr[white], arr[red]);
            red--;
        }
        if (DEBUG_MODE)
			print(arr);
    }
    return std::pair<int, int>(blue, white);
}

void quick_sort(std::vector<int>& arr, const bool DEBUG_MODE) {
    quick_sort_aux(arr, 0, arr.size(), DEBUG_MODE);
}
void quick_sort_aux(std::vector<int>& arr, int s, int e, const bool DEBUG_MODE) {
    if (s < e) {
        if (DEBUG_MODE)
            std::cout << "--- PARTITION DEBUG START " << "[" << s << " " << e << "]" << " ---\n";
        std::pair<int, int> res = partition(arr, s, e, arr[s], DEBUG_MODE);
        if (DEBUG_MODE)
            std::cout << "*** PARTITION DEBUG END ***\n";
        quick_sort_aux(arr, s, res.first, DEBUG_MODE);
        quick_sort_aux(arr, res.second, e, DEBUG_MODE);
    }
}


// █▀▄▀█ █▀▀ █▀█ █▀▀ █▀▀   █▀ █▀█ █▀█ ▀█▀
// █░▀░█ ██▄ █▀▄ █▄█ ██▄   ▄█ █▄█ █▀▄ ░█░
void merge_sort(std::vector<int>& arr, const bool DEBUG_MODE) {
    std::vector<int> temp(arr.size());
    merge_sort_aux(arr, temp, 0, arr.size(), DEBUG_MODE);
}

void merge_sort_aux(std::vector<int>& arr, std::vector<int>& temp, int s, int e, const bool DEBUG_MODE) {
    if (s < e - 1) {
        int m = s + (e - s) / 2;
        merge_sort_aux(arr, temp, s, m, DEBUG_MODE);
        merge_sort_aux(arr, temp, m, e, DEBUG_MODE);
        merge(arr, temp, s, m, e);
        if (DEBUG_MODE) {
            std::cout << "--- MERGE SORT DEBUG [" << s << " " << e << "] ---\n";
            print(arr);
        }
    }
}

void merge(std::vector<int>& arr, std::vector<int>& temp, int s, int m, int e) {
    int i1 = s, i2 = m, k = 0;
    // Merging the sorted arrays arr[s..m] and arr[m..e]
    while (i1 < m && i2 < e) {
        if (arr[i1] <= arr[i2]) {
            temp[k] = arr[i1];
            i1++; k++;
        }
        else {
            temp[k] = arr[i2];
            i2++; k++;
        }
    }
    while (i1 < m) {
        temp[k] = arr[i1];
        k++; i1++;
    }
    while (i2 < e) {
        temp[k] = arr[i2];
        k++; i2++;
    }
    // Copy everything back
    for (int i = 0; i < k; i++) {
        arr[s + i] = temp[i];
    }
}