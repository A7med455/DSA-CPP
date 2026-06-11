#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};


Node* insert(Node* root, int value) {
    if (root == nullptr) { // If current position is empty, insert here
        Node* newNode = new Node{value, nullptr, nullptr};
        return newNode;
    }
    
    if (value < root->data) {
        // If value is less, go to the left subtree
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        // If value is greater, go to the right subtree
        root->right = insert(root->right, value);
    }
    
    return root; // Return the current node back up the recursion chain
}


bool search(Node* root, int target) {
    if (root == nullptr) { // If current node is null, value not found
        return false;
    }
    
    if (target == root->data) { // If value matches current node, found it
        return true;
    } else if (target < root->data) {
        // If target is smaller, search in left subtree
        return search(root->left, target);
    } else {
        // If target is greater, search in right subtree
        return search(root->right, target);
    }
}


void inorder(Node* root) {
    if (root == nullptr) return; // Base case: if tree is empty, do nothing
    
    inorder(root->left); // Step 1: Visit left subtree
    cout << root->data << " "; // Step 2: Visit root
    inorder(root->right); // Step 3: Visit right subtree
}


Node* findMax(Node* root) {
    while (root && root->right != nullptr) {
        root = root->right; // Move down to the right as far as possible
    }
    return root;
}


Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    // Traverse the tree to find the node to delete
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node found. 
        
        // Case 1 & 2: Node has no children (leaf) OR only one child [cite: 140, 141]
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Node has two children [cite: 142]
        // Locate the inorder predecessor (max value in left subtree) [cite: 148]
        Node* temp = findMax(root->left); 
        
        // Copy data of inorder predecessor node into current node [cite: 149]
        root->data = temp->data; 
        
        // Delete the inorder predecessor node and re-link [cite: 150]
        root->left = deleteNode(root->left, temp->data); 
    }
    return root;
}

// --- Main Function ---
int main() {
    Node* root = nullptr;

    // Inserting nodes
    root = insert(root, 31);
    root = insert(root, 12);
    root = insert(root, 78);
    root = insert(root, 3);
    root = insert(root, 16);
    root = insert(root, 95);
    root = insert(root, 7);
    root = insert(root, 81);

    cout << "Inorder traversal before deletion: ";
    inorder(root);
    cout << "\n";

    // Searching for a value
    int target = 16;
    if (search(root, target)) {
        cout << "Value " << target << " found in the tree.\n";
    } else {
        cout << "Value " << target << " not found.\n";
    }

    // Deleting a node
    cout << "Deleting node 31...\n";
    root = deleteNode(root, 31);

    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << "\n";

    return 0;
}