#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    Node* curr = head;
    while (curr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

void LinkedList::insert(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

bool LinkedList::search(int value) {
    Node* curr = head;
    while (curr) {
        if (curr->data == value) return true;
        curr = curr->next;
    }
    return false;
}

void LinkedList::remove(int value) {
    Node* curr = head;
    Node* prev = nullptr;

    while (curr && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    if (!curr) return;

    if (!prev) head = curr->next;
    else prev->next = curr->next;

    delete curr;
}

void LinkedList::display() {
    Node* curr = head;
    while (curr) {
        std::cout << curr->data << " -> ";
        curr = curr->next;
    }
    std::cout << "NULL\n";
}
