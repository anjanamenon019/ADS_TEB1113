#include <iostream>
#include <string>

using namespace std;

//Stack Max size
const int MAX = 100;

class Stack {
private:
    string arr[MAX];
    int topIndex;

public:
    Stack() {
        topIndex = -1; // Initialize empty stack
    }

    // PUSH
    void push(string name) {
        topIndex = topIndex + 1;
        arr[topIndex] = name;
    }

    // POP
    void pop() {
        topIndex = topIndex - 1;
    }

    // PEEK
    string peek() {
        return arr[topIndex];
    }

    // DISPLAY
    void display_stack() {
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    Stack* myStack = new Stack();

    myStack->push("A");
    myStack->push("B");
    myStack->push("C");
    myStack->push("D");
    
    cout << "PUSH" << endl;
    myStack->display_stack(); 
    
    cout << "\nPEEK TOP:" << endl;
    cout << myStack->peek() << endl;

    cout << "\nPOP" << endl;
    myStack->pop(); 
    myStack->display_stack();

    return 0;
}