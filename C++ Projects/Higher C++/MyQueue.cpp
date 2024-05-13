#include <iostream>

class Node {
friend class Queue;
    int value;
    Node* next;
public:
    Node() : value(0), next(nullptr) {}
    Node(int v) : value(v), next(nullptr) {}
};

class Queue {
    Node* front;
    Node* back;
public:
    Queue() : front(nullptr), back(nullptr) {}
    void enqueue(int k) {
        Node *toQueue = new Node(k);
        if (front == nullptr || back == nullptr) {
            std::cout << "Queue is empty. Inserting a node to queue.\n";
            front = back = toQueue;
            return;
        }

        Node *scanNode = front;
        while (scanNode->next != nullptr) {
            scanNode = scanNode->next;
        }

        back = toQueue;
        scanNode->next = back;

        std::cout << "Value " << back->value << " has been added to the queue.\n";
    }
    void dequeue() {
        Node *forUnqueue = front;
        if (front == nullptr || back == nullptr) {
            std::cout << "Nothing to unqueue. Queue is empty.\n";
            return;
        }
        
        front = front->next;

        std::cout << "The front node of value " << forUnqueue->value << " has been removed.\n";
        delete forUnqueue;
    }

    void checkQueue() {
        Node *scanNode = front;
        
        std::cout << "Front: ";
        while (scanNode->next != nullptr) {
            std::cout << scanNode->value << "<<=";
            scanNode = scanNode->next;
        }

        std::cout << scanNode->value << " : Back\n";
    }
};

int main() {
    Queue belt1;

    belt1.enqueue(10);

    belt1.checkQueue();

    belt1.dequeue();

    belt1.checkQueue();
}