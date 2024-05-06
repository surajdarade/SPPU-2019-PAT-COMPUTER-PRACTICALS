// Note : Tree input should be binary search tree

#include <iostream>
#include <stack>

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

// Function to perform DFS traversal (inorder) on the binary tree
void dfsTraversal(TreeNode* root) {
    if (root == NULL) return;

    stack<TreeNode*> stk;
    TreeNode* current = root;

    while (current != NULL || !stk.empty()) {
        while (current != NULL) {
            stk.push(current);
            current = current->left;
        }
        current = stk.top();
        stk.pop();
        cout << current->val << " ";
        current = current->right;
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

    cout << "DFS Traversal of the binary tree: ";
    dfsTraversal(root);

    return 0;
}