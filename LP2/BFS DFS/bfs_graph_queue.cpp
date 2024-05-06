#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Function to perform Breadth First Search on a graph
// represented using adjacency list
void bfs(vector<vector<int>>& adjList, int startNode, vector<bool>& visited) {
    // Create a queue for BFS
    queue<int> q;

    // Mark the current node as visited and enqueue it
    visited[startNode] = true;
    q.push(startNode);

    // Iterate over the queue
    while (!q.empty()) {
        // Dequeue a vertex from queue and print it
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent vertex has not been visited,
        // then mark it visited and enqueue it
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// Function to add an edge to the graph
void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
}

int main() {
    // Number of vertices and edges in the graph
    int vertices, edges;

    cout << "Enter the number of vertices in the graph: ";
    cin >> vertices;

    // Adjacency list representation of the graph
    vector<vector<int>> adjList(vertices);

    cout << "Enter the number of edges in the graph: ";
    cin >> edges;

    cout << "Enter the edges (source -> destination):" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(adjList, u, v);
    }

    // Mark all the vertices as not visited
    vector<bool> visited(vertices, false);

    // Perform BFS traversal starting from vertex 0
    cout << "Breadth First Traversal starting from vertex 0: ";
    bfs(adjList, 0, visited);

    return 0;
}

// Sample Input and Output: 

/*

Enter the number of vertices in the graph: 5
Enter the number of edges in the graph: 5
Enter the edges (source destination):
0 
1
0
2
1
3
1
4
2
4
Breadth First Traversal starting from vertex 0: 0 1 2 3 4

*/