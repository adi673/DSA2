
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

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<int> adj[n+1];
  for (const auto& edge : edges) {
    int u = edge.first;
    int v = edge.second;
    adj[u].push_back(v);
    
  }


  vector<int>vis(n+1,0);
  vector<int>dfs_vis(n+1,0);

  for(int i=0; i<=n; i++){
   int val=cycleDetect(i,adj,vis,dfs_vis);
    if(val){
      return 1;
    }
  }
  return 0;

}
