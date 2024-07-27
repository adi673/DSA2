int detect(int node, vector<int>adj[], vecotr<int>vis){
    vis[node]=1;
    unordered_map<int,int> parent; //parent,child
    parent[node]=-1;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int top=q.front();
        q.pop();

        for(auto it: adj[top]){
            if(!vis[it]){
                q.push(it);
                vis[it]=1;
                parent[top]=it;
            }else if(parent[top]!=it){
                return true;
            }
        }
    }
    return false;
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
            int val=detect(i,adj,vis,);
            if(val){
                return "Yes";
            }
        }
    }
    return "No";

}