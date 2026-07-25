#include <iostream>
using namespace std;


// BINARY SEARCH TREE
struct Node {
    int data;
    Node* left = NULL;
    Node* right = NULL;

    Node(int val) {
        data = val;
    }
};

// INSERT FUNCTION
Node* insert(Node* root, int val) {
    if (root == NULL) return new Node(val);
    
    if (val < root->data) 
        root->left = insert(root->left, val);
    else 
        root->right = insert(root->right, val);
        
    return root;
}

// 1. PRE-ORDER TRAVERSAL (Root, Left, Right)
void display_preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    display_preorder(root->left);
    display_preorder(root->right);
}

// 2. IN-ORDER TRAVERSAL (Left, Root, Right)
void display_inorder(Node* root) {
    if (root == NULL) return;
    display_inorder(root->left);
    cout << root->data << " ";
    display_inorder(root->right);
}

// 3. POST-ORDER TRAVERSAL (Left, Right, Root)
void display_postorder(Node* root) {
    if (root == NULL) return;
    display_postorder(root->left);
    display_postorder(root->right);
    cout << root->data << " ";
}

int main() {
    int order[] = {50, 30, 70, 20, 40, 60, 80};
    Node* root = NULL;

    
    for (int val : order) {
        root = insert(root, val);
    }

    cout << "Pre-Order  : ";
    display_preorder(root);
    cout << "\n";

    cout << "In-Order   : ";
    display_inorder(root);
    cout << "\n";

    cout << "Post-Order : ";
    display_postorder(root);
    cout << "\n";

    return 0;
}