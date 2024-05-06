#include <iostream>
#include <vector>

using namespace std;

// Function to perform Breadth First Search on a graph
// represented using adjacency list
void bfsRecursive(vector<vector<int>>& adjList, vector<int>& queue, vector<bool>& visited) {
    if (queue.empty()) return; // Base case: if the queue is empty, return

    // Dequeue a vertex from the queue-like structure and print it
    int currentNode = queue.front();
    queue.erase(queue.begin()); // Remove the front element
    cout << currentNode << " ";

    // Iterate over the neighbors of the current node
    for (int neighbor : adjList[currentNode]) {
        if (!visited[neighbor]) {
            visited[neighbor] = true; // Mark the neighbor as visited
            queue.push_back(neighbor); // Enqueue the neighbor
        }
    }

    // Recursively call BFS on the updated queue-like structure
    bfsRecursive(adjList, queue, visited);
}

// Function to add an edge to the graph
void addEdge(vector<vector<int>>& adjList, int u, int v) {
    adjList[u].push_back(v);
}

int main() {
    // Number of vertices in the graph
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

    // Create a queue-like structure to maintain BFS order
    vector<int> queue;

    // Perform BFS traversal starting from vertex 0
    cout << "Breadth First Traversal starting from vertex 0: ";
    queue.push_back(0); // Enqueue the starting vertex
    visited[0] = true; // Mark the starting vertex as visited
    bfsRecursive(adjList, queue, visited);

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