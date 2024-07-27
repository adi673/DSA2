class Graph {
public:
    // Constructor to initialize the graph with given edges
    Graph(int n, vector<vector<int>>& edges) {
        numNodes = n;
        adjList.resize(n);
        for (const auto& edge : edges) {
            addEdge(edge);
        }
    }
    
    // Method to add an edge to the graph
    void addEdge(vector<int> edge) {
        int node1 = edge[0];
        int node2 = edge[1];
        int weight = edge[2];
        adjList[node1].push_back({node2, weight});
 
    }

    // Dijkstra's algorithm to find the shortest path from src to all other nodes
    int dijkstra(int src, int V, int destination) {
        set<pair<int, int>> s; // Set to store (distance, node) pairs
        vector<int> dist(V, INT_MAX); // Vector to store the distance of each node from the source node
        s.insert(make_pair(0, src)); // Inserting the source node with distance 0

        dist[src] = 0; // Distance of source node from itself is 0
        while(!s.empty()) {
            pair<int, int> p = *(s.begin());
            int u = p.second;
            s.erase(s.begin());
            for(auto it: adjList[u]) {
                int v = it.first;
                int weight = it.second;

                // If there is a shorter path to v through u
                if (dist[v] > dist[u] + weight) {
                    // If the distance of v is not infinite, then remove the old pair from the set
                    if (dist[v] != INT_MAX) {
                        s.erase(s.find(make_pair(dist[v], v)));
                    }

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
        return dist[destination];
    }

    // Method to find the shortest path between two nodes using Dijkstra
    int shortestPath(int node1, int node2) {
        if (node1 == node2) return 0;
        
        int dist = dijkstra(node1, numNodes, node2);
        if (dist != INT_MAX) {
            return dist;
        }
        
        return -1; // Return -1 if there's no path between node1 and node2
    }

private:
    int numNodes;
    vector<vector<pair<int, int>>> adjList;
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */

// www.leetcode.com/problems/design-a-graph-with-shortest-path-calculator