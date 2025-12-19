# Data Structures & Algorithms Performance Analyzer

This project implements core data structures and algorithms in c++ and benchmarks their runtime performance across different input sizes.

## Features
- Implemented data structures: Linked List, Stack, Queue, Binary Search Tree, Hash Table
- Implemented sorting algorithms: Merge Sort, Quick Sort, Heap Sort
- Implemented searching algorithms: Linear Search, Binary Search
- Runtime benchmarking using C++ chrono utilities
- CSV export for reproducible performance analysis

## Technologies
- C++
- GNU g++ (MSYS2 MinGW64)
- STL (vector, algorithm, chrono)

## How to Compile and Run
```bash
g++ src/*.cpp -Iinclude -o analyzer.exe
./analyzer.exe
