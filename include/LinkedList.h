#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList();
    ~LinkedList();

    void insert(int value);
    bool search(int value);
    void remove(int value);
    void display();
};

#endif
