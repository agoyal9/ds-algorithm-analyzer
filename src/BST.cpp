#include "BST.h"

BST::BST() : root(nullptr) {}

BST::~BST() {
    destroy(root);
}

BST::Node* BST::insert(Node* node, int value) {
    if (!node) return new Node(value);
    if (value < node->data)
        node->left = insert(node->left, value);
    else
        node->right = insert(node->right, value);
    return node;
}

void BST::insert(int value) {
    root = insert(root, value);
}

bool BST::search(Node* node, int value) {
    if (!node) return false;
    if (node->data == value) return true;
    return value < node->data ? search(node->left, value)
                              : search(node->right, value);
}

bool BST::search(int value) {
    return search(root, value);
}

void BST::inorder(Node* node) {
    if (!node) return;
    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}

void BST::displayInorder() {
    inorder(root);
    std::cout << "\n";
}

void BST::destroy(Node* node) {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}
