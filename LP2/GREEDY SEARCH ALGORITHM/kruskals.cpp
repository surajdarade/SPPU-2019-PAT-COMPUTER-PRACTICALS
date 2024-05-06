#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DSU {
    int* parent;
    int* rank;

public:
    DSU(int n) : parent(new int[n]), rank(new int[n]) {
        fill(parent, parent + n, -1);
        fill(rank, rank + n, 1);
    }

    int find(int i) {
        return parent[i] == -1 ? i : parent[i] = find(parent[i]);
    }

    void unite(int x, int y) {
        int s1 = find(x), s2 = find(y);
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) parent[s1] = s2;
            else if (rank[s1] > rank[s2]) parent[s2] = s1;
            else parent[s2] = s1, rank[s1]++;
        }
    }
};

class Graph {
    vector<vector<int>> edgelist;
    int V;

public:
    Graph(int V) : V(V) {}

    void addEdge(int x, int y, int w) {
        edgelist.push_back({w, x, y});
    }

    void kruskals_mst() {
        sort(edgelist.begin(), edgelist.end());
        DSU s(V);
        int ans = 0;
        for (int i = 0; i < edgelist.size(); ++i) {
            int w = edgelist[i][0], x = edgelist[i][1], y = edgelist[i][2];
            if (s.find(x) != s.find(y)) {
                s.unite(x, y);
                ans += w;
                cout << x << " -- " << y << " == " << w << endl;
            }
        }
        cout << "Minimum Cost Spanning Tree: " << ans;
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices: "; cin >> V;
    cout << "Enter the number of edges: "; cin >> E;

    Graph g(V);
    cout << "Enter edge details (source, destination, weight) for each edge:\n";
    for (int i = 0, src, dest, weight; i < E && cin >> src >> dest >> weight; i++)
        g.addEdge(src, dest, weight);

    g.kruskals_mst();
    return 0;
}


// Sample Input and Output: 

/*

Enter the number of vertices: 4
Enter the number of edges: 5
Enter edge details (source, destination, weight) for each edge:
0 1 10
1 3 15
2 3 4
2 0 6      
0 3 5
2 -- 3 == 4
0 -- 3 == 5
0 -- 1 == 10
Minimum Cost Spanning Tree: 19

*/


/*

---------- Direct input ----------

#include <bits/stdc++.h> 
using namespace std; 
  
// DSU data structure 
// path compression + rank by union 
class DSU { 
    int* parent; 
    int* rank; 
  
public: 
    DSU(int n) 
    { 
        parent = new int[n]; 
        rank = new int[n]; 
  
        for (int i = 0; i < n; i++) { 
            parent[i] = -1; 
            rank[i] = 1; 
        } 
    } 
  
    // Find function 
    int find(int i) 
    { 
        if (parent[i] == -1) 
            return i; 
  
        return parent[i] = find(parent[i]); 
    } 
  
    // Union function 
    void unite(int x, int y) 
    { 
        int s1 = find(x); 
        int s2 = find(y); 
  
        if (s1 != s2) { 
            if (rank[s1] < rank[s2]) { 
                parent[s1] = s2; 
            } 
            else if (rank[s1] > rank[s2]) { 
                parent[s2] = s1; 
            } 
            else { 
                parent[s2] = s1; 
                rank[s1] += 1; 
            } 
        } 
    } 
}; 
  
class Graph { 
    vector<vector<int> > edgelist; 
    int V; 
  
public: 
    Graph(int V) { this->V = V; } 
  
    // Function to add edge in a graph 
    void addEdge(int x, int y, int w) 
    { 
        edgelist.push_back({ w, x, y }); 
    } 
  
    void kruskals_mst() 
    { 
        // Sort all edges 
        sort(edgelist.begin(), edgelist.end()); 
  
        // Initialize the DSU 
        DSU s(V); 
        int ans = 0; 
        cout << "Following are the edges in the "
                "constructed MST"
             << endl; 
        for (auto edge : edgelist) { 
            int w = edge[0]; 
            int x = edge[1]; 
            int y = edge[2]; 
  
            // Take this edge in MST if it does 
            // not forms a cycle 
            if (s.find(x) != s.find(y)) { 
                s.unite(x, y); 
                ans += w; 
                cout << x << " -- " << y << " == " << w 
                     << endl; 
            } 
        } 
        cout << "Minimum Cost Spanning Tree: " << ans; 
    } 
}; 
  
// Driver code 
int main() 
{ 
    Graph g(4); 
    g.addEdge(0, 1, 10); 
    g.addEdge(1, 3, 15); 
    g.addEdge(2, 3, 4); 
    g.addEdge(2, 0, 6); 
    g.addEdge(0, 3, 5); 
  
    // Function call 
    g.kruskals_mst(); 
  
    return 0; 
}

*/