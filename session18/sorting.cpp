#include "sorting.h"


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
