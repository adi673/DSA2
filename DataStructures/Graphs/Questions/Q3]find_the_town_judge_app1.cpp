class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> adj(n+1);
        vector<int> trustCount(n + 1, 0);
        for (const auto& edge : trust) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            trustCount[v]++;
            
        }

        for(int i=1; i<n+1; i++){
            if(adj[i].empty() && trustCount[i]==n-1){
                return i;
            }
        }
        return -1;

    }
};