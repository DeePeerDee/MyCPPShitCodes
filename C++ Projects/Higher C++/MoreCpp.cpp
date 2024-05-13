#include <iostream>

class Node {
public:
    int value;
    Node *next;
    Node() : value(0), next(nullptr) {}
    Node(int val) : value(val), next(nullptr) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void createNewList(int value) {
        Node *startNode = new Node(value);
        if (head != nullptr) {
            std::cout << "The Linked List has already been created.\n";
            return;
        }

        head = startNode;
        std::cout << "New linked list created: Head location(" << head << ") with value(" << value << ").\n";
        printList();
    }

    void insertToEnd(int value) {
        Node *endNode = new Node(value);
        int listCount = 2;

        if (head == nullptr) {
            std::cout << "The linked list associated is non-existent.\n";
            createNewList(value);
            return;
        }

        Node *temp = head;

        while (temp->next != nullptr) {
            listCount++;
            temp = temp->next;
        }

        temp->next = endNode;
        std::cout << "Successfully added to end of linked list: " << endNode->value << " with order " << listCount << std::endl;
        printList();
    }

    void insertWithin(int value, int order) {
        Node *betweenNode = new Node(value), *temp1 = head, *temp2 = nullptr;
        int listCount = 0, accessNo = 1;

        while (temp1 != nullptr) {
            temp1 = temp1->next;
            listCount++;
        }

        if (order < 1 || order-1 > listCount) {
            std::cout << "Order number not allowed for this linked list.\n";
            return;
        }

        temp1 = head;
        
        if (order == 1) {
            head = betweenNode;
            head->next = temp1;
            std::cout << "New Head: " << head->value << " leading " << temp1->value << std::endl;
            printList();
            return;
        }
        
        while (accessNo < order) {
            temp2 = temp1;
            temp1 = temp1->next;
            accessNo++;
        }

        std::cout << "Insert: " << temp2->value << "->" << temp1->value << std::endl;
        temp2->next = betweenNode;
        betweenNode->next = temp1;

        std::cout << "Updated: " << temp2->value << "->" << betweenNode->value << "->" << temp1->value << std::endl;
        printList();
    }

    void deleteNode(int order) {
        Node *temp1 = head, *temp2 = nullptr;
        int listCount = 0;

        if (head == nullptr) {
            std::cout << "The list is already empty.\n";
            return;
        }

        while (temp1 != nullptr) {
            temp1 = temp1->next;
            listCount++;
        }

        if (order < 1 || order-1 > listCount) {
            std::cout << "Order number not allowed for this linked list.\n";
            return;
        }

        while(order > 1) {
            temp2 = temp1;
            temp1 = temp1->next;
            order--;
        }

        temp2->next = temp1->next;

        delete temp1;
    }

    void printList() {
        Node* temp = head;

        if (head == nullptr) {
            std::cout << "The linked list is empty.\n";
        }

        std::cout << "Linked List Connection: ";

        while (temp != nullptr) {
            std::cout << temp->value << "->";
            temp = temp->next;
        }

        std::cout << "()\n";
    }

    void printNode(int order) {
        Node* temp = head;
        int listCount = 0, accessNo = 0;

        if (head == nullptr) {
            std::cout << "The linked list is empty.\n";
            return;
        }

        while (temp != nullptr) {
            temp = temp->next;
            listCount++;
        }

        if (order < 1 || order-1 > listCount) {
            std::cout << "Order number is beyond the range of this linked list.\n";
            return;
        }

        accessNo++;
        temp = head;
        while (accessNo < order) {
            temp = temp->next;
            accessNo++;
        }

        std::cout << "Value at node " << order << ": " << temp->value << std::endl;
    }
};

int main() {
    LinkedList myList1;
    LinkedList myList2;

    myList1.insertToEnd(3);
    myList1.insertToEnd(11);
    myList1.insertToEnd(9);
    myList1.insertToEnd(37);
    myList1.insertToEnd(7);
    myList1.insertToEnd(8);

    myList1.printNode(5);

    myList1.insertWithin(23,4);

    myList1.printNode(5);
}