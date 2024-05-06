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

// Function to perform BFS traversal on the binary tree
void bfsTraversal(TreeNode* root) {
    if (root == NULL) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        cout << current->val << " ";

        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        }
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
    bfsTraversal(root);

    return 0;
}