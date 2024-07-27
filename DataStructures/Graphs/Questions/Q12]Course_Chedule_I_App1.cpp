class Solution {
public:

    int cycleDetect(int node,vector<int> adj[],vector<int>vis,vector<int>dfs_vis){
        dfs_vis[node]=1;
        vis[node]=1;

        for(auto it: adj[node]){
            if(!vis[it]){
                int resu=cycleDetect(it, adj, vis, dfs_vis);  
                if(resu){
                 return 1;
                }
            }else if(dfs_vis[it]){
                return 1;
            }
        }
        dfs_vis[node]=0;
        return 0;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int> adj[n + 1];
        for (const auto& edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];

            // Add the edge to the adjacency list
            adj[u].push_back(v);
        }

        vector<int>vis(n+1,0);
        vector<int>dfs_vis(n+1,0);

        for(int i=0; i<=n; i++){
            int val=cycleDetect(i,adj,vis,dfs_vis);
            if(val){
                return false;
            }
        }
        return true;
    }
};

//dfs cycle detection. if cycle present then return false else return true
//giving TLE