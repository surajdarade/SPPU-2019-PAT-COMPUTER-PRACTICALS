#include <iostream>
#include <map>
#include <list>
#include <vector>

using namespace std;

// Graph class represents a directed graph using adjacency list representation
class Graph {
public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    // Function to add an edge to the graph
    void addEdge(int v, int w);

    // Recursive function to perform DFS traversal from a given vertex
    void DFS(int v);
};

void Graph::addEdge(int v, int w) {
    // Add w to v's list of adjacent vertices
    adj[v].push_back(w);
}

void Graph::DFS(int v) {
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all adjacent vertices of the current vertex
    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            DFS(neighbor);
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
Depth First Traversal (starting from vertex 2): 2 0 1 3

*/