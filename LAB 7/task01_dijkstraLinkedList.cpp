#include <iostream>
#include <climits>
using namespace std;

//GRAPH DIJKSTRA LINKED LIST

// 1. Linked List Node to represent an edge (neighbor + weight)
struct Node {
    int vtx;
    int weight;
    Node* next;

    Node(int v, int w) {
        vtx = v;
        weight = w;
        next = NULL;
    }
};

// 2. Add edge to the linked list
void addEdge(Node* head[], int u, int v, int w) {
    // Add v to u's list
    Node* newNode1 = new Node(v, w);
    newNode1->next = head[u];
    head[u] = newNode1;

    // Add u to v's list (undirected graph)
    Node* newNode2 = new Node(u, w);
    newNode2->next = head[v];
    head[v] = newNode2;
}

// 3. Function: to find unvisited node with min dist
int minDistance(int dist[], bool visited[], int V) {
    int minVal = INT_MAX, minIndex = -1;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] <= minVal) {
            minVal = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// 4. Dijkstra Algorithm
void dijkstra(Node* head[], int V, int src) {
    int dist[V];
    bool visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        if (u == -1) break;

        visited[u] = true;

        // Traverse u's linked list
        Node* curr = head[u];
        while (curr != NULL) {
            int v = curr->vtx;
            int w = curr->weight;

            if (!visited[v] && dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
            curr = curr->next;
        }
    }

    // Print output with 0->A, 1->B, 2->C, 3-> D, 4-> E
    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < V; i++) {
        // 0=A, 1=B, 2=C, 3=D, 4=E
        char name = 'A' + i; 
        cout << name << "\t" << dist[i] << endl;
    }
}

int main() {
    int V = 5;
    Node* head[5] = {NULL}; // Array of Linked List heads for A, B, C, D, E

    // 0=A, 1=B, 2=C, 3=D, 4=E
    addEdge(head, 0, 1, 4);  // A - B (weight 4)
    addEdge(head, 0, 2, 8);  // A - C (weight 8)
    addEdge(head, 1, 2, 3);  // B - C (weight 3)
    addEdge(head, 1, 4, 6);  // B - E (weight 6)
    addEdge(head, 2, 3, 2);  // C - D (weight 2)
    addEdge(head, 3, 4, 10); // D - E (weight 10)

    dijkstra(head, V, 0); // Start from A (0)

    return 0;
}