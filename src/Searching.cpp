#include "Searching.h"

bool linearSearch(const std::vector<int>& arr, int key) {
    for (int val : arr) {
        if (val == key) return true;
    }
    return false;
}

bool binarySearch(const std::vector<int>& arr, int key) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return true;
        if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}
