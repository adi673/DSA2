#include<unordered_map>
#include<queue>

int detectCycle(int node,vector<int> adj[],vector<int>& vis){
    vis[node]=1;
    unordered_map<int,int> parent;
    parent[node]=-1;
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        int top=q.front();
        q.pop();
        for(auto it : adj[top]){
            if(!vis[it]){
                q.push(it);
                vis[it]=1;
                parent[it]=top;
            }else if(vis[it]==1 &&  parent[top]!=it){
                return true; 
            }
        }
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> adj[n + 1];
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];

        // Add the edge to the adjacency list
        adj[u].push_back(v);
        adj[v].push_back(u);  // Comment this out if the graph is directed
    }

    vector<int>vis(n+1,0);
    for(int i=0; i<n; i++){
        if(!vis[i]){
            int val=detectCycle(i,adj,vis);
            if(val==1){
                return "Yes";
            }
        }
    }
    return "No";
}
