#ifndef BST_H
#define BST_H

#include <iostream>

class BST {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, int value);
    bool search(Node* node, int value);
    void inorder(Node* node);
    void destroy(Node* node);

public:
    BST();
    ~BST();

    void insert(int value);
    bool search(int value);
    void displayInorder();
};

#endif
