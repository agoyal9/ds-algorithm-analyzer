#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* topNode;

public:
    Stack();
    ~Stack();

    void push(int value);
    void pop();
    int top();
    bool isEmpty();
};

#endif
