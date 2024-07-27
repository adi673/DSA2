class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> result;
        vector<vector<int>> reverse_adj(n);

        // Create the reverse adjacency list
        for (const auto& edge : edges) {
            int from_node = edge[0];
            int to_node = edge[1];
            reverse_adj[to_node].push_back(from_node);
        }

        // Collect nodes with no incoming edges
        for (int node = 0; node < n; ++node) {
            if (reverse_adj[node].empty()) {
                result.push_back(node);
            }
        }

        return result;
    }
};

//since graph is directed acyclic graph, we can use reverse adjacency list to find the nodes with no incoming edges. Meaning, these nodes are the starting nodes of the graph. So, we can return these nodes as the answer.
//revise x2