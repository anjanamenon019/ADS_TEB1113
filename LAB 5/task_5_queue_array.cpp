#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;

class Queue {
private:
    string arr[MAX];
    int frontIndex;
    int rearIndex;

public:
    Queue() {
        frontIndex = 0;
        rearIndex = -1;
    }

    // ENQUEUE
    void enqueue(string name) {
        rearIndex++;
        arr[rearIndex] = name;
    }

    // DEQUEUE
    void dequeue() {
        frontIndex++;
    }

    // PEEK
    string peek() {
        return arr[frontIndex];
    }

    // DISPLAY
    void display_queue() {
        for (int i = frontIndex; i <= rearIndex; i++) {
            cout << arr[i] << " ";
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
    
    cout << "\nPEEK FRONT:" << endl;
    cout << myQueue->peek() << endl;

    cout << "\nDEQUEUE FRONT:" << endl;
    myQueue->dequeue(); 
    myQueue->display_queue();

    return 0;
}