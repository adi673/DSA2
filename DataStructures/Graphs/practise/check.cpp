#include <iostream>
#include <vector>
#include <set>
#include <limits.h>

using namespace std;

const int MAX_VERTICES = 1000; // Adjust this as needed

// Adjacency list to store (node, weight) pairs
vector<pair<int, int>> adj[MAX_VERTICES];

// Function to add an edge to the graph
void addEdge(int u, int v, int weight) {
    adj[u].push_back(make_pair(v, weight));
    adj[v].push_back(make_pair(u, weight)); // Since the graph is undirected
}

// Function to find the shortest path using Dijkstra's algorithm
void dijkstra(int src, int V) {
     // Add your Dijkstra's algorithm logic here
    set<pair<int, int>> s; // Set to store (distance, node) pairs
    vector<int> dist(V, INT_MAX); // Vector to store the distance of each node from the source node
    s.insert(make_pair(0, src)); // Inserting the source node with distance 0

    dist[src] = 0; // Distance of source node from itself is 0
    while(!s.empty()) {
        pair<int, int>p = *(s.begin());
        int u=p.second;
        s.erase(s.begin());
        for(auto it: adj[u]) {
            int v = it.first;
            int weight = it.second;

            
            // If there is a shorter path to v through u
            if (dist[v] > dist[u] + weight) {
                // If the distance of v is not infinite, then remove the old pair from the set
                // if (dist[v] != INT_MAX) {
                //     s.erase(s.find(make_pair(dist[v], v)));
                // }
                //optimization lines above 2-3 lines above

                // Update the distance of v
                dist[v] = dist[u] + weight;
                s.insert(make_pair(dist[v], v));
            }
        }
    }

    // Print the shortest paths from the source node
    for (int i = 0; i < V; ++i) {
        cout << "Shortest distance from node " << src << " to node " << i << " is " << dist[i] << endl;
    }
}

int main() {
    int V = 5; // Number of vertices

    // Adding edges to the graph
    addEdge(0, 1, 10);
    addEdge(0, 4, 5);
    addEdge(1, 2, 1);
    addEdge(1, 4, 2);
    addEdge(2, 3, 4);
    addEdge(3, 4, 9);
    addEdge(3, 2, 6);
    addEdge(4, 2, 3);

    int src = 0; // Source node
    cout << "Shortest paths from source node " << src << ":\n";
    dijkstra(src, V);

    return 0;
}
