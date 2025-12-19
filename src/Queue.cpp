#include "Queue.h"
#include <stdexcept>

Queue::Queue() : front(nullptr), rear(nullptr) {}

Queue::~Queue() {
    while (!isEmpty()) dequeue();
}

void Queue::enqueue(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void Queue::dequeue() {
    if (isEmpty()) return;
    Node* temp = front;
    front = front->next;
    if (!front) rear = nullptr;
    delete temp;
}

int Queue::peek() {
    if (isEmpty()) throw std::runtime_error("Queue empty");
    return front->data;
}

bool Queue::isEmpty() {
    return front == nullptr;
}
