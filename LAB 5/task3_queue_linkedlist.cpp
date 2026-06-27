#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    Node* next;
};

class Queue {
public:
    Node* front = NULL; 
    Node* rear = NULL;  

    // ENQUEUE
    void enqueue(string name) {
        Node* newNode = new Node();
        newNode->name = name;
        newNode->next = NULL;
        
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // DEQUEUE
    void dequeue() {
        Node* temp = front;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete temp;
    }


    // DISPLAY
    void display_queue() {
        Node* current = front;
        while (current != NULL) {
            cout << current->name << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue* myQueue = new Queue();

    myQueue->enqueue("A");
    myQueue->enqueue("B");
    myQueue->enqueue("C");
    myQueue->enqueue("D");
    
    cout << "ENQUEUE:" << endl;
    myQueue->display_queue(); 
    

    cout << "\nDEQUEUE FRONT:" << endl;
    myQueue->dequeue(); // Remove A
    myQueue->display_queue();

    return 0;
}