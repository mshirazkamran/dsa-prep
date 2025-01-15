#include <iostream>
using namespace std;

// Node structure for the AVL Tree
struct Node {
    int value;       // Value of the node
    Node* left;      // Pointer to the left child
    Node* right;     // Pointer to the right child
    int height;      // Height of the node
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1; // New node is initially added at height 1
    return newNode;
}

// Function to get the height of a node
int getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

// Function to get the balance factor of a node
int getBalanceFactor(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Function to perform a right rotation
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T = x->right;

    // Perform rotation
    x->right = y;
    y->left = T;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x; // Return new root
}

// Function to perform a left rotation
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T = y->left;

    // Perform rotation
    y->left = x;
    x->right = T;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y; // Return new root
}

// Function to insert a value into the AVL tree
Node* insert(Node* node, int value) {
    if (node == nullptr) {
        return createNode(value); // Create a new node if the tree is empty
    }

    // Perform standard BST insertion
    if (value < node->value) {
        node->left = insert(node->left, value);
    } else if (value > node->value) {
        node->right = insert(node->right, value);
    } else {
        return node; // Duplicates are not allowed in this AVL tree
    }

    // Update height of the current node
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    // Get the balance factor to check if the node is unbalanced
    int balance = getBalanceFactor(node);

    // Left-Left case
    if (balance > 1 && value < node->left->value) {
        return rotateRight(node);
    }

    // Right-Right case
    if (balance < -1 && value > node->right->value) {
        return rotateLeft(node);
    }

    // Left-Right case
    if (balance > 1 && value > node->left->value) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right-Left case
    if (balance < -1 && value < node->right->value) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node; // Return the unchanged node pointer
}

// Function to perform an in-order traversal of the AVL tree
void inOrderTraversal(Node* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->value << " ";
        inOrderTraversal(root->right);
    }
}

// Main function
int main() {
    Node* root = nullptr; // Start with an empty tree

    // Insert values into the AVL tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Display the AVL tree in in-order traversal
    cout << "In-order traversal of the AVL tree: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
