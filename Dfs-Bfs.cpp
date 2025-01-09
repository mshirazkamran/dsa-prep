#include <iostream>
#include <queue>
using namespace std;

// Node structure for the tree
struct TreeNode {
    int val;
    TreeNode *left, *right;

    // Constructor to initialize a new node
    TreeNode(int value) {
        val = value;
        left = right = nullptr;
    }
};

// BFS (Level-order Traversal) with complete nullptr checks
void bfs(TreeNode *root) {
    if (root == nullptr) { // Check if the root is null
        cout << "The tree is empty." << endl;
        return;
    }

    queue<TreeNode *> q; // Create a queue for nodes
    q.push(root);        // Enqueue the root node

    while (!q.empty()) {
        TreeNode *current = q.front(); // Get the front node
        q.pop();                       // Remove it from the queue

        // Process the current node
        if (current != nullptr) {
            cout << current->val << " ";

            // Enqueue the left child if it exists
            if (current->left != nullptr) 
                q.push(current->left);

            // Enqueue the right child if it exists
            if (current->right != nullptr) 
                q.push(current->right);
        }
    }
}

// DFS (In-order Traversal) with nullptr checks
void dfs(TreeNode *root) {
    if (root == nullptr) return; // Base case: If the node is null, return

    // Visit the left subtree
    dfs(root->left);

    // Visit the current node
    cout << root->val << " ";

    // Visit the right subtree
    dfs(root->right);
}

int main() {
    // Create a sample binary tree
    /*
        Tree structure:
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
    */
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Perform BFS
    cout << "BFS (Level-order Traversal): ";
    bfs(root);
    cout << endl;

    // Perform DFS
    cout << "DFS (In-order Traversal): ";
    dfs(root);
    cout << endl;

    // Free dynamically allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

// BFS (Level-order Traversal): 1 2 3 4 5 6 7
// DFS (In-order Traversal): 4 2 5 1 6 3 7
