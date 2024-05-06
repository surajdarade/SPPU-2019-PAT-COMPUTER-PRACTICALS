// Note : Tree input should be binary search tree

#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to insert a new node into the binary tree
TreeNode* insertNode(TreeNode* root, int value) {
    if (root == NULL) {
        root = new TreeNode(value);
    } else {
        if (value <= root->val) {
            root->left = insertNode(root->left, value);
        } else {
            root->right = insertNode(root->right, value);
        }
    }
    return root;
}

// Recursive function to perform DFS traversal (inorder) on the binary tree
void dfsTraversal(TreeNode* root) {
    if (root == NULL) return;
    // Visit left subtree
    dfsTraversal(root->left);
    // Print current node value
    cout << root->val << " ";
    // Visit right subtree
    dfsTraversal(root->right);
}

int main() {
    TreeNode* root = NULL;
    int n, val;

    cout << "Enter the number of nodes in the binary tree: ";
    cin >> n;

    cout << "Enter the values of the nodes:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insertNode(root, val);
    }

    cout << "DFS Traversal of the binary tree: ";
    dfsTraversal(root);

    return 0;
}
