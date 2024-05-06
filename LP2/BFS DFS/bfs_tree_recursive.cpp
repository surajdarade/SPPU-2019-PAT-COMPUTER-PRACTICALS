// Note : Tree input should be binary search tree


#include <iostream>
#include <queue>

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

// Recursive function to perform BFS traversal on the binary tree
void bfsTraversal(TreeNode* root, int level) {
    if (root == NULL) return;
    // Print nodes at the current level
    if (level == 1) {
        cout << root->val << " ";
    } else if (level > 1) {
        // Recur for left and right subtrees
        bfsTraversal(root->left, level - 1);
        bfsTraversal(root->right, level - 1);
    }
}

// Function to calculate the height of the binary tree
int getHeight(TreeNode* root) {
    if (root == NULL) return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

// Function to perform BFS traversal on the binary tree using recursion
void bfsRecursive(TreeNode* root) {
    int height = getHeight(root);
    for (int i = 1; i <= height; i++) {
        bfsTraversal(root, i);
    }
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

    cout << "BFS Traversal of the binary tree: ";
    bfsRecursive(root);

    return 0;
}
