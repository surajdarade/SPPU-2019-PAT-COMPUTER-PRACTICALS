#include <iostream>
#include <map>
#include <list>
#include <stack>

using namespace std;

// Graph class represents a directed graph using adjacency list representation
class Graph {
public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    // Function to add an edge to the graph
    void addEdge(int v, int w);

    // Iterative function to perform DFS traversal from a given vertex
    void DFS(int v);
};

void Graph::addEdge(int v, int w) {
    // Add w to v's list of adjacent vertices
    adj[v].push_back(w);
}

void Graph::DFS(int v) {
    // Create a stack for DFS traversal
    stack<int> stack;

    // Push the starting vertex onto the stack
    stack.push(v);

    // Mark the starting vertex as visited
    visited[v] = true;

    // Iterate until the stack is empty
    while (!stack.empty()) {
        // Get the top vertex from the stack
        int currentVertex = stack.top();
        stack.pop();

        // Print the current vertex
        cout << currentVertex << " ";

        // Traverse all adjacent vertices of the current vertex
        for (int neighbor : adj[currentVertex]) {
            // If the adjacent vertex has not been visited, mark it as visited and push it onto the stack
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                stack.push(neighbor);
            }
        }
    }
}

int main() {
    Graph g;
    int numEdges;

    cout << "Enter the number of edges in the graph: ";
    cin >> numEdges;

    cout << "Enter the edges (source -> destination):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int source, destination;
        cin >> source >> destination;
        g.addEdge(source, destination);
    }

    int startVertex;
    cout << "Enter the starting vertex for DFS traversal: ";
    cin >> startVertex;

    cout << "Depth First Traversal (starting from vertex " << startVertex << "): ";
    g.DFS(startVertex);

    return 0;
}


// Sample Input and Output:

/*

Enter the number of edges in the graph: 6
Enter the edges (source -> destination):
0 
1
0
2
1
2
2
0
2
3
3
3
Enter the starting vertex for DFS traversal: 2
Depth First Traversal (starting from vertex 2): 2 3 0 1

*/