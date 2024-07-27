#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int detectCycle(int node, int parent, vector<int> adj[], vector<int>& vis) {
    vis[node] = 1;

    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (detectCycle(it, node, adj, vis)) {
                return 1;
            }
        } else if (it != parent) {
            return 1;
        }
    }

    return 0;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m) {
    vector<int> adj[n + 1];
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];

        // Add the edge to the adjacency list
        adj[u].push_back(v);
        adj[v].push_back(u);  // Comment this out if the graph is directed
    }

    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int val = detectCycle(i, -1, adj, vis);
            if (val == 1) {
                return "Yes";
            }
        }
    }
    return "No";
}

