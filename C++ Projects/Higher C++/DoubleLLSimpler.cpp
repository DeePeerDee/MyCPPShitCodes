#include <iostream>

class Node {
friend class DoubleLL;
    int value;
    Node* prev;
    Node* next;
public:
    Node() : value(0), prev(nullptr), next(nullptr) {}
    Node(int k) : value(k), prev(nullptr), next(nullptr) {}
};

class DoubleLL {
    Node* head;
    Node* tail;
public:
    DoubleLL() : head(nullptr), tail(nullptr) {}

    bool isEmpty() {
        return (head == nullptr || tail == nullptr);
    }

    void prepend(int k) {
        Node *addBfre = new Node(k);

        if (isEmpty()) {
            //std::cout << "List Is Empty\n";
            head = addBfre;
            tail = addBfre;
            return;
        }

        Node *goBkwd = tail, *ptFrwd = nullptr;

        while (goBkwd->prev != nullptr) {
            ptFrwd = goBkwd; //Fw = 30
            goBkwd = goBkwd->prev; //Fw = 20
            goBkwd->next = ptFrwd; //20 ->> 30 next
            ptFrwd->prev = goBkwd; //30 <<->> 20 prev
        }

        head->prev = addBfre;
        head = addBfre;
        head->next = goBkwd;
    }

    void append(int k) {
        Node *addAftr = new Node(k);

        if (isEmpty()) {
            //std::cout << "List Is Empty\n";
            head = addAftr;
            tail = addAftr;
            return;
        }

        Node *goFrwd = head, *ptBkwd = nullptr;

        while (goFrwd->next != nullptr) {
            ptBkwd = goFrwd; //Fw = 30
            goFrwd = goFrwd->next; //Fw = 20
            goFrwd->prev = ptBkwd; //20 ->> 30 next
            ptBkwd->next = goFrwd; //30 <<->> 20 prev
        }

        tail->next = addAftr;
        tail = addAftr;
        tail->prev = goFrwd;
    }

    void printBkwd() {
        if (isEmpty()) {
            std::cout << "Empty Linked List.\n";
            return;
        }

        Node *cntBkwd = tail;

        while (cntBkwd->prev != nullptr) {
            std::cout << cntBkwd->value << "<->";
            cntBkwd = cntBkwd->prev;
        }

        std::cout << cntBkwd->value << std::endl;
    }

    void printFrwd() {
        if (isEmpty()) {
            std::cout << "Empty Linked List.\n";
            return;
        }

        Node *cntFrwd = head;

        while (cntFrwd->next != nullptr) {
            std::cout << cntFrwd->value << "<->";
            cntFrwd = cntFrwd->next;
        }

        std::cout << cntFrwd->value << std::endl;
    }

    void insFromHead(int k, int o) {
        Node *newNode = new Node(k), *toRef = head;
        int ndCnt = 0;

        while (toRef != nullptr) {
            toRef = toRef->next;
            ndCnt++;
        }

        if (o < 1 || ndCnt+1 < o) {
            std::cout << "Illegal order\n";
            return;
        }

        toRef = head;

        if (o == 1) {
            prepend(k);
            return;
        }

        if (o == ndCnt+1) {
            append(k);
            return;
        }

        Node *gdeNd = toRef;
        toRef = toRef->next;

        while (--o > 1) {
            gdeNd = gdeNd->next;
            toRef = toRef->next;
        }

        newNode->next = toRef;
        gdeNd->next = newNode;

        toRef->prev = newNode;
        newNode->prev = gdeNd;
    }

    void insFromTail(int k, int o) {
        Node *newNode = new Node(k), *toRef = tail;
        int ndCnt = 0;

        while (toRef != nullptr) {
            toRef = toRef->prev;
            ndCnt++;
        }

        if (o < 1 || ndCnt+1 < o) {
            std::cout << "Illegal order\n";
            return;
        }

        toRef = tail;

        if (o == 1) {
            append(k);
            return;
        }

        if (o == ndCnt+1) {
            prepend(k);
            return;
        }

        Node *gdeNd = toRef;
        toRef = toRef->prev;

        while (--o > 1) {
            gdeNd = gdeNd->prev;
            toRef = toRef->prev;
        }

        newNode->prev = toRef;
        gdeNd->prev = newNode;

        toRef->next = newNode;
        newNode->next = gdeNd;
    }

    void delFromHead(int o) {
        if (isEmpty()) {
            std::cout << "Nothing to delete\n";
            return;
        }

        Node *toRef = head;
        int ndCnt = 0;

        while (toRef != nullptr) {
            toRef = toRef->next;
            ndCnt++;
        }

        toRef = head;

        if (o < 1 || ndCnt < o) {
            std::cout << "Illegal order\n";
            return;
        }

        if (o == 1) {
            if (head == tail) {
                head->next = nullptr;
                head = nullptr;
                
                tail->prev = nullptr;
                tail = nullptr;

                delete toRef;
                return;
            }

            head = head->next;
            head->prev = nullptr;

            delete toRef;
            return;
        }

        if (o == ndCnt) {
            toRef = tail;
            tail = tail->prev;
            tail->next = nullptr;

            delete toRef;
            return;
        }


        Node *ldNd = nullptr, *jmpNd = nullptr;

        while (o > 1) {
            ldNd = toRef;
            jmpNd = toRef->next->next;
            toRef = toRef->next;
            o--;
        }

        ldNd->next = jmpNd;
        jmpNd->prev = ldNd;
        
        delete toRef;
    }

    void delFromTail(int o) {
        if (isEmpty()) {
            std::cout << "Nothing to delete\n";
            return;
        }

        Node *toRef = tail;
        int ndCnt = 0;

        while (toRef != nullptr) {
            toRef = toRef->prev;
            ndCnt++;
        }

        toRef = tail;

        if (o < 1 || ndCnt < o) {
            std::cout << "Illegal order\n";
            return;
        }

        if (o == 1) {
            if (head == tail) {
                head->next = nullptr;
                head = nullptr;
                
                tail->prev = nullptr;
                tail = nullptr;

                delete toRef;
                return;
            }

            tail = tail->prev;
            tail->next = nullptr;

            delete toRef;
            return;
        }

        if (o == ndCnt) {
            toRef = head;
            head = head->next;
            head->prev = nullptr;

            delete toRef;
            return;
        }


        Node *ldNd = nullptr, *jmpNd = nullptr;

        while (o > 1) {
            ldNd = toRef;
            jmpNd = toRef->prev->prev;
            toRef = toRef->prev;
            o--;
        }

        ldNd->prev = jmpNd;
        jmpNd->next = ldNd;
        
        delete toRef;
    }
};

int main() {
    DoubleLL list;

    list.prepend(30);
    
    list.prepend(20);

    list.append(40);

    list.prepend(0);

    list.append(60);

    list.printFrwd();

    list.insFromHead(10,2);

    list.printFrwd();

    list.insFromTail(50,2);

    list.printFrwd();

}