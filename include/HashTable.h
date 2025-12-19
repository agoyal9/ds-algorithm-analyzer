#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>

class HashTable {
private:
    std::vector<std::list<int>> table;
    int size;

    int hashFunction(int key);

public:
    HashTable(int size = 10);

    void insert(int key);
    bool search(int key);
    void remove(int key);
};

#endif
