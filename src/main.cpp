#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <fstream>
#include <algorithm>

#include "Sorting.h"
#include "Searching.h"

using namespace std;
using namespace std::chrono;

vector<int> generateData(int size) {
    vector<int> data(size);
    mt19937 gen(42);
    uniform_int_distribution<> dist(1, size * 10);

    for (int i = 0; i < size; i++) {
        data[i] = dist(gen);
    }
    return data;
}

long long benchmarkSort(void (*sortFunc)(vector<int>&), vector<int> data) {
    auto t1 = high_resolution_clock::now();
    sortFunc(data);
    auto t2 = high_resolution_clock::now();
    return duration_cast<milliseconds>(t2 - t1).count();
}

int main() {
    ofstream file("results.csv");
    file << "InputSize,MergeSort,QuickSort,HeapSort\n";

    vector<int> sizes = {10000, 30000, 50000};

    // ---------- SORT BENCHMARK ----------
    for (int size : sizes) {
        vector<int> baseData = generateData(size);

        long long mergeTime = benchmarkSort(mergeSort, baseData);
        long long quickTime = benchmarkSort(quickSort, baseData);
        long long heapTime  = benchmarkSort(heapSort,  baseData);

        cout << "Sorting done for size " << size << endl;

        file << size << ","
             << mergeTime << ","
             << quickTime << ","
             << heapTime << "\n";
    }

    // ---------- SEARCH BENCHMARK ----------
    vector<int> searchData = generateData(50000);
    sort(searchData.begin(), searchData.end());

    int key = searchData[searchData.size() / 2];

    auto t1 = high_resolution_clock::now();
    linearSearch(searchData, key);
    auto t2 = high_resolution_clock::now();
    cout << "Linear Search took "
         << duration_cast<microseconds>(t2 - t1).count()
         << " us\n";

    t1 = high_resolution_clock::now();
    binarySearch(searchData, key);
    t2 = high_resolution_clock::now();
    cout << "Binary Search took "
         << duration_cast<microseconds>(t2 - t1).count()
         << " us\n";

    file.close();
    cout << "Results saved to results.csv\n";

    return 0;
}
