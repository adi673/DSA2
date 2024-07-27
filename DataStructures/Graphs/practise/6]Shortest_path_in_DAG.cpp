//Convert given edge weight directed graph in Adjacency list
//vector<pair<int,int>> adj[n]  value of node and weight of edge

//DFS topological sort stack

#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>

using namespace std;

class Graph {
    int V; // Number of vertices
    vector<pair<int, int>> *adj; // Adjacency list to store (destination, weight) pairs

public:
    Graph(int V) {
        this->V = V;
        adj = new vector<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back(make_pair(v, weight));
    }

    void topologicalSortUtil(int v, vector<bool> &visited, stack<int> &Stack) {
        visited[v] = true;

        for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[i->first]) {
                topologicalSortUtil(i->first, visited, Stack);
            }
        }

        Stack.push(v);
    }

    void shortestPath(int src) {
        stack<int> Stack;
        vector<int> dist(V, INT_MAX);
        vector<bool> visited(V, false);

        // Perform topological sort
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, Stack);
            }
        }

        // Initialize source distance
        dist[src] = 0;

        // Process vertices in topological order
        while (!Stack.empty()) {
            int u = Stack.top();
            Stack.pop();

            // Update distances of all adjacent vertices
            if (dist[u] != INT_MAX) {
                for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
                    if (dist[i->first] > dist[u] + i->second) {
                        dist[i->first] = dist[u] + i->second;
                    }
                }
            }
        }

        // Print the calculated shortest distances
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << dist[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    int V = 6; // Number of vertices in the graph
    Graph g(V);

    // Adding edges to the graph
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    int src = 1; // Source node
    cout << "Following are the shortest distances from source node " << src << ":\n";
    g.shortestPath(src);

    return 0;
}
