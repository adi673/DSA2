class Solution {
public:

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int> adjList[n + 1];  // Assuming nodes are 1-indexed
        if(source==destination){
            return true;
        }
        // Iterate through the edge list
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // Add the edge to the adjacency list
            adjList[u].push_back(v);
            adjList[v].push_back(u);  // Comment this out if the graph is directed
        }

    
        vector<int>vis (n+1,0);
        queue<int> q;
        
        
        vis[source]=1;
        q.push(source);
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
           
            
            for(auto it : adjList[node]){
                if(it==destination){
                    return true;
                }
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return false;;
        

    }
};

//DFS approach may lead to Time limit exceeded error