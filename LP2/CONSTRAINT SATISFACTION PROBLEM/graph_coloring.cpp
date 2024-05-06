#include <iostream>
#include <list>
#include <string>
using namespace std;

// A class representing the graph
class Graph {
   int V;
   list<int> *graph;

public:
   // Constructor
   Graph(int V) {
      this->V = V;
      graph = new list<int>[V];
   }

   // a function that will add an edge to the graph.
   void insertEdge(int u, int v) {
      graph[u].push_back(v);
      graph[v].push_back(u);
   }

   // Greedy algo of printing the colors
   void graphColoringAlgorithm() {
      string colorNames[] = {"Red", "Green", "Blue", "Yellow", "Orange", "Purple", "Pink", "Cyan", "Magenta", "Brown"};
      int colorArray[V];

      // Assign 0 as the first vertex
      colorArray[0] = 0;

      /*
      Assigning -1 to the rest of the vertex means the rest of the colors are not yet assigned
      */
      for (int i = 1; i < V; i++)
         colorArray[i] = -1;

      // A temporary array to store the available colors.
      bool temp[V];
      for (int i = 0; i < V; i++)
         temp[i] = false;

      // Assign colors to the rest of the vertices.
      for (int u = 1; u < V; u++) {
         // an iterator to iterate over graph list.
         list<int>::iterator i;

         for (i = graph[u].begin(); i != graph[u].end(); i++)
            if (colorArray[*i] != -1)
               temp[colorArray[*i]] = true;

         int j;
         for (j = 0; j < V; j++)
            if (temp[j] == false)
               break;

         colorArray[u] = j;

         for (i = graph[u].begin(); i != graph[u].end(); ++i)
            if (colorArray[*i] != -1)
               temp[colorArray[*i]] = false;
      }

      // printing the assigned colors.
      for (int i = 0; i < V; i++)
         cout << "Vertex: " << i << " Color: " << colorNames[colorArray[i]] << endl;
   }
};

int main() {
   int V;
   cout << "Enter the number of vertices: ";
   cin >> V;

   Graph g(V);
   int u, v;
   char cont;
   do {
      cout << "Enter an edge (u v): ";
      cin >> u >> v;
      g.insertEdge(u, v);
      cout << "Do you want to enter another edge? (y/n): ";
      cin >> cont;
   } while (cont == 'y' || cont == 'Y');

   cout << "The assigned colors of the graph are:" << endl;
   g.graphColoringAlgorithm();

   return 0;
}

// Sample Input and Output:

/*

Enter the number of vertices: 5
Enter an edge (u v): 0 1
Do you want to enter another edge? (y/n): y
Enter an edge (u v): 0 2
Do you want to enter another edge? (y/n): y
Enter an edge (u v): 1 2
Do you want to enter another edge? (y/n): y
Enter an edge (u v): 1 3
Do you want to enter another edge? (y/n): y
Enter an edge (u v): 2 3
Do you want to enter another edge? (y/n): y
Enter an edge (u v): 3 4
Do you want to enter another edge? (y/n): n
The assigned colors of the graph are:
Vertex: 0 Color: Red
Vertex: 1 Color: Green
Vertex: 2 Color: Blue
Vertex: 3 Color: Red
Vertex: 4 Color: Green

*/



/*

---------- Direct input ----------


#include <bits/stdc++.h>
using namespace std;

// A class representing the graph
class Graph {
   int V;
   list<int> *graph;

public:
   // Constructor
   Graph(int V) {
      this->V = V;
      graph = new list<int>[V];
   }

   // a function that will add an edge to the graph.
   void insertEdge(int u, int v) {
      graph[u].push_back(v);
      graph[v].push_back(u);
   }

   // Greedy algo of printing the colors
   void graphColoringAlgorithm() {
      string colorNames[] = {"Red", "Green", "Blue", "Yellow", "Orange", "Purple", "Pink", "Cyan", "Magenta", "Brown"};
      int colorArray[V];

      // Assign 0 as the first vertex
      colorArray[0] = 0;

      /*
      Assigning -1 to the rest of the vertex means the rest of the colors are not yet assigned
      
      for (int i = 1; i < V; i++)
         colorArray[i] = -1;

      // A temporary array to store the available colors.
      bool temp[V];
      for (int i = 0; i < V; i++)
         temp[i] = false;

      // Assign colors to the rest of the vertices.
      for (int u = 1; u < V; u++) {
         // an iterator to iterate over graph list.
         list<int>::iterator i;

         for (i = graph[u].begin(); i != graph[u].end(); i++)
            if (colorArray[*i] != -1)
               temp[colorArray[*i]] = true;

         int j;
         for (j = 0; j < V; j++)
            if (temp[j] == false)
               break;

         colorArray[u] = j;

         for (i = graph[u].begin(); i != graph[u].end(); ++i)
            if (colorArray[*i] != -1)
               temp[colorArray[*i]] = false;
      }

      // printing the assigned colors.
      for (int i = 0; i < V; i++)
         cout << "Vertex: " << i << " Color: " << colorNames[colorArray[i]] << endl;
   }
};

int main() {
   Graph g(5);
   g.insertEdge(0, 1);
   g.insertEdge(0, 2);
   g.insertEdge(1, 2);
   g.insertEdge(1, 3);
   g.insertEdge(2, 3);
   g.insertEdge(3, 4);
   cout << "The assigned colors of the graph are:" << endl;
   g.graphColoringAlgorithm();

   return 0;
}

*/