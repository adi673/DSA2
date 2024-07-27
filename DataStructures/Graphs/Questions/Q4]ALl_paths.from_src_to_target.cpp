class Solution {
public:

    void dfs(int node,  vector<int> adj[], vector<int>& vis, vector<int>& in, vector<vector<int>>& out, int n){
        vis[node] = 1;
        in.push_back(node);
        if(node == n) {
            out.push_back(in);
        }
        else {
            for(auto it: adj[node]){
                if(!vis[it]){
                    dfs(it, adj, vis, in, out, n);
                }
            }
        }
        in.pop_back(); // Backtrack after exploring all paths from current node
        vis[node] = 0; // Mark the node as unvisited for other paths
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>out;
        vector<int>in;
        int n=graph.size();
        vector<int> adj[n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < graph[i].size(); ++j) {
                int node = graph[i][j];
                adj[i].push_back(node);
            }
        }
        vector<int>vis (n,0);
        dfs(0, adj, vis, in, out,n-1);
        return out;
    }
};

//revise it again 2x


// All Paths From Source to Target
// Solved
// Medium
// Topics
// Companies
// Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

// The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

 

// Example 1:


// Input: graph = [[1,2],[3],[3],[]]
// Output: [[0,1,3],[0,2,3]]
// Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.