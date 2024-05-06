#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

class Graph {
    int V;
    list<iPair>* adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestPath(int src);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::shortestPath(int src) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(V, INF);
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        list<iPair>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    cout << "Vertex Distance from Source\n";
    for (int i = 0; i < V; ++i)
        cout << i << "\t\t" << dist[i] << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    Graph g(V);
    cout << "Enter edges with weights (source, destination, weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    int src;
    cout << "Enter the source vertex: ";
    cin >> src;
    g.shortestPath(src);
    return 0;
}

// Sample Input and Output:

/*

Enter the number of vertices: 7
Enter the number of edges: 8
Enter edges with weights (source, destination, weight):
0 1 2
0 2 6 
1 3 5
2 3 8
3 4 10
3 5 15
4 6 2
5 6 6
Enter the source vertex: 0
Vertex Distance from Source
0               0
1               2
2               6
3               7
4               17
5               22
6               19

*/

/*

---------- Direct input ----------


#include <bits/stdc++.h> 
using namespace std; 
#define INF 0x3f3f3f3f 
  
// iPair ==> Integer Pair 
typedef pair<int, int> iPair; 
  
// This class represents a directed graph using 
// adjacency list representation 
class Graph { 
    int V; // No. of vertices 
  
    // In a weighted graph, we need to store vertex 
    // and weight pair for every edge 
    list<pair<int, int> >* adj; 
  
public: 
    Graph(int V); // Constructor 
  
    // function to add an edge to graph 
    void addEdge(int u, int v, int w); 
  
    // prints shortest path from s 
    void shortestPath(int s); 
}; 
  
// Allocates memory for adjacency list 
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<iPair>[V]; 
} 
  
void Graph::addEdge(int u, int v, int w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
} 
  
// Prints shortest paths from src to all other vertices 
void Graph::shortestPath(int src) 
{ 
    // Create a priority queue to store vertices that 
    // are being preprocessed. This is weird syntax in C++. 
    // Refer below link for details of this syntax 
    // https://www.geeksforgeeks.org/implement-min-heap-using-stl/ 
    priority_queue<iPair, vector<iPair>, greater<iPair> > 
        pq; 
  
    // Create a vector for distances and initialize all 
    // distances as infinite (INF) 
    vector<int> dist(V, INF); 
  
    // Insert source itself in priority queue and initialize 
    // its distance as 0. 
    pq.push(make_pair(0, src)); 
    dist[src] = 0; 
  
    /* Looping till priority queue becomes empty (or all 
    distances are not finalized) 
    while (!pq.empty()) { 
        // The first vertex in pair is the minimum distance 
        // vertex, extract it from priority queue. 
        // vertex label is stored in second of pair (it 
        // has to be done this way to keep the vertices 
        // sorted distance (distance must be first item 
        // in pair) 
        int u = pq.top().second; 
        pq.pop(); 
  
        // 'i' is used to get all adjacent vertices of a 
        // vertex 
        list<pair<int, int> >::iterator i; 
        for (i = adj[u].begin(); i != adj[u].end(); ++i) { 
            // Get vertex label and weight of current 
            // adjacent of u. 
            int v = (*i).first; 
            int weight = (*i).second; 
  
            // If there is shorted path to v through u. 
            if (dist[v] > dist[u] + weight) { 
                // Updating distance of v 
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    } 
  
    // Print shortest distances stored in dist[] 
    printf("Vertex Distance from Source\n"); 
    for (int i = 0; i < V; ++i) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 
  
// Driver program to test methods of graph class 
int main() 
{ 
    // create the graph given in above figure 
    int V = 7; 
    Graph g(V); 
  
    // making above shown graph 
    g.addEdge(0, 1, 2); 
    g.addEdge(0, 2, 6); 
    g.addEdge(1, 3, 5); 
    g.addEdge(2, 3, 8); 
    g.addEdge(3, 4, 10); 
    g.addEdge(3, 5, 15); 
    g.addEdge(4, 6, 2); 
    g.addEdge(5, 6, 6); 
    g.shortestPath(0); 
  
    return 0; 
}

*/