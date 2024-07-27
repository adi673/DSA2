bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    // Create the adjacency list
    vector<vector<int>> adj(n);
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }




    vector<int> adj[n + 1];
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];

        // Add the edge to the adjacency list
        adj[u].push_back(v);
        adj[v].push_back(u);  // Comment this out if the graph is directed
    }




     bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int size=rooms.size();
        vector<int>adj[size];
        for(int i=0; i<size; i++){
            for(int j=0; j<rooms[i].size; i++){
                int node = graph[i][j];
                adj[i].push_back(node);
            }
        }
    }
}