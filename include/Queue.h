#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

class Queue {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    Queue();
    ~Queue();

    void enqueue(int value);
    void dequeue();
    int peek();
    bool isEmpty();
};

#endif
