#include <iostream>
#include <vector>

class Stack {
    int sizeCap;
    int top;
    int *arr;
    int *origArr;
public:
    Stack() : sizeCap(100), top(0), arr(new int[100]) {}
    Stack(int size) : sizeCap(size), top(0), arr(new int[size]) {}
    bool beyondOriginal() {
        return (top > sizeCap-1);
    }
    void push(int k) {
        if (beyondOriginal()) {
            expandSize();
            std::cout << "Original size: " << sizeCap << " Size after push: " << top+1 << std::endl;
        }
        
        std::cout << "Index to assign k: " << top;
        arr[top] = k;
        top++;
        std::cout << " Index then points to: " << top << std::endl;
        std::cout << "The value on top of stack: " << arr[top-1] << std::endl; //top->8**** 
    }

    void expandSize() {
        origArr = arr;
        int *larger = new int[top+1];
        for (int i = 0; i < top; i++) {
            larger[i] = arr[i];
        }
        
        arr = larger;
    }

    void pop() {
        std::cout << "Pointing index currently but not in size: " << top; //7 (7 elements from 0-6)
        top--; //6;
        int dispPop = arr[top]; //arr[6]
        if (top+1 == sizeCap) {
            arr = origArr;
            std::cout << "\nReplacing to original size: " << sizeCap;
            arr[top] = 0;
            std::cout << " Popped value: " << dispPop;
            std::cout << " from index: " << top << std::endl;
            return;
        } 

        if (top+1 < sizeCap) {
            std::cout << "\nUsing original size: " << sizeCap << " now pointing to " << top << std::endl;
            arr[top] = 0;
            std::cout << "Popped value: " << dispPop << std::endl;
            return;
        }

        int *smaller = new int[top]; //new int[6]
        std::cout << "\nShrinking to size: " << top;
        for (int i = 0; i < top; i++) {
            smaller[i] = arr[i];
        }

        arr = smaller;

        std::cout << " Index to pop-off: " << top;
        std::cout << "\nPopped value: " << dispPop << std::endl;
    }
};

int main() {
    Stack myStack(5);

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);
    myStack.push(60);
    myStack.push(70);
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
}