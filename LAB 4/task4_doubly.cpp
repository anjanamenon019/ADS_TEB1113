#include <iostream>
#include <string>

using namespace std;

class Node {
public: 
    string name;
    Node* next = NULL;
    Node* prev = NULL; 
};

int main() {
    // Allocation (Removed the unused node5)
    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    Node* node4 = new Node();
    
    node1->name = "Aimar";    
    node2->name = "Ahmad";    
    node3->name = "Anjana";  
    node4->name = "Jessy";    
    
    // Forward Links
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;
    
    // Backward Links
    node1->prev = NULL;
    node2->prev = node1;
    node3->prev = node2;
    node4->prev = node3;
   
    // Print list forward
    cout << "--- Forward ---" << endl;
    Node* display_node = node1;
    while(display_node != NULL){
        cout << display_node->name << endl;
        display_node = display_node->next;
    }
    
    // Print list backward
    cout << "\n--- Backward ---" << endl;
    display_node = node4; 
    while(display_node != NULL){
        cout << display_node->name << endl;
        display_node = display_node->prev; // Changed .next to .prev
    }
    
    
    return 0;
}