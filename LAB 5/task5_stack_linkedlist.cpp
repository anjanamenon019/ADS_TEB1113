#include <iostream>
#include <string>

using namespace std;

// Node structure to store the data
struct Node {
    string name;
    Node* next;
};

class Stack {
public:
    Node* top = NULL;

    // PUSH
    void push(string name) {
        Node* newNode = new Node();
        newNode->name = name;
        newNode->next = top;
        top = newNode;
    }

    // POP
    void pop() {
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // PEEK
    string peek() {
        return top->name;
    }

    // DISPLAY
    void display_stack() {
        Node* display_node = top;
        while (display_node != NULL) {
            cout << display_node->name << endl;
            display_node = display_node->next;
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

    cout << "\nPOP TOP" << endl;
    myStack->pop(); 
    myStack->display_stack();

    return 0;

}