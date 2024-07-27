
int detect(int node, vector<int> adj[], vector<int>vis, int parent){
    vis[node]=1;

    for(auto it : adj[node]){
        if(!vis[it]){
            int val=detect(it,adj,vis,node);
            if(val){
                return true;
            }
        }else if(it!=parent){
            return true;
        }
    }
    return true;
}


string cycleDetection (vector<vector<int>>& edges, int n, int m){
    vector<int>adj[n+1];
    for(auto it : edges){
        int u= it[0];
        int v= it[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
        
    }

    vector<int> vis(n+1,0);
    for (int i=0; i<=n; i++){
        if(!vis[i]){
            int val=detect(i,adj,vis,-1);
            if(val){
                return "Yes";
            }
        }
    }
    return "No";

}