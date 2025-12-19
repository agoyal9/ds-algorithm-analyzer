#include "HashTable.h"

HashTable::HashTable(int size) : size(size) {
    table.resize(size);
}

int HashTable::hashFunction(int key) {
    return key % size;
}

void HashTable::insert(int key) {
    int index = hashFunction(key);
    table[index].push_back(key);
}

bool HashTable::search(int key) {
    int index = hashFunction(key);
    for (int val : table[index]) {
        if (val == key) return true;
    }
    return false;
}

void HashTable::remove(int key) {
    int index = hashFunction(key);
    table[index].remove(key);
}
