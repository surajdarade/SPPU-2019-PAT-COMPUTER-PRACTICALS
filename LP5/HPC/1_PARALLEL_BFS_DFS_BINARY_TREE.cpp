#include <iostream>
#include <queue>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <omp.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
public:
    TreeNode *root;

    BinaryTree() : root(nullptr) {}

    TreeNode *insertRandom(TreeNode *node, int val)
    {
        if (!node)
            return new TreeNode(val);
        if (rand() % 2)
            node->left = insertRandom(node->left, val);
        else
            node->right = insertRandom(node->right, val);
        return node;
    }

    void generate(int n)
    {
        for (int i = 1; i <= n; i++)
            root = insertRandom(root, i);
    }

    void serialDFS(TreeNode *node)
    {
        if (!node)
            return;
        serialDFS(node->left);
        serialDFS(node->right);
    }

    void parallelDFS(TreeNode *node)
    {
        if (!node)
            return;
#pragma omp parallel
        {
#pragma omp single nowait
            dfsHelper(node);
        }
    }

    void dfsHelper(TreeNode *node)
    {
        if (!node)
            return;

#pragma omp task shared(node)
        dfsHelper(node->left);

#pragma omp task shared(node)
        dfsHelper(node->right);
    }

    void serialBFS(TreeNode *node)
    {
        if (!node)
            return;
        queue<TreeNode *> q;
        q.push(node);
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }

    void parallelBFS(TreeNode *node)
    {
        if (!node)
            return;
        queue<TreeNode *> q;
        q.push(node);
        while (!q.empty())
        {
            int size = q.size();
#pragma omp parallel for
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr;
#pragma omp critical
                {
                    if (!q.empty())
                    {
                        curr = q.front();
                        q.pop();
                    }
                    else
                        continue;
                }

#pragma omp critical
                {
                    if (curr->left)
                        q.push(curr->left);
                    if (curr->right)
                        q.push(curr->right);
                }
            }
        }
    }
};

int main()
{
    srand(time(0));
    int N = 7896;
    BinaryTree tree;
    tree.generate(N);

    auto start_serial_bfs = high_resolution_clock::now();
    tree.serialBFS(tree.root);
    auto end_serial_bfs = high_resolution_clock::now();

    auto start_parallel_bfs = high_resolution_clock::now();
    tree.parallelBFS(tree.root);
    auto end_parallel_bfs = high_resolution_clock::now();

    auto start_serial_dfs = high_resolution_clock::now();
    tree.serialDFS(tree.root);
    auto end_serial_dfs = high_resolution_clock::now();

    auto start_parallel_dfs = high_resolution_clock::now();
    tree.parallelDFS(tree.root);
    auto end_parallel_dfs = high_resolution_clock::now();

    auto duration_serial_bfs = duration_cast<microseconds>(end_serial_bfs - start_serial_bfs);
    auto duration_parallel_bfs = duration_cast<microseconds>(end_parallel_bfs - start_parallel_bfs);
    auto duration_serial_dfs = duration_cast<microseconds>(end_serial_dfs - start_serial_dfs);
    auto duration_parallel_dfs = duration_cast<microseconds>(end_parallel_dfs - start_parallel_dfs);

    cout << "\nBREADTH FIRST SEARCH (BFS):\n";
    cout << "Sequential Time : " << duration_serial_bfs.count() << " microseconds\n";
    cout << "Parallel Time   : " << duration_parallel_bfs.count() << " microseconds\n";
    cout << "Speedup Factor  : " << static_cast<double>(duration_serial_bfs.count()) / duration_parallel_bfs.count() << "\n";

    cout << "\nDEPTH FIRST SEARCH (DFS):\n";
    cout << "Sequential Time : " << duration_serial_dfs.count() << " microseconds\n";
    cout << "Parallel Time   : " << duration_parallel_dfs.count() << " microseconds\n";
    cout << "Speedup Factor  : " << static_cast<double>(duration_serial_dfs.count()) / duration_parallel_dfs.count() << "\n";

    return 0;
}
