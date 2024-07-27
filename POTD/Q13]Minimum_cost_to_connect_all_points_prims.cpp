class Solution {
public:
    
    int findMin(vector<int>& key,vector<bool>& mst){
        int min=INT_MAX;
        int min_index;
        for(int i=0; i<key.size(); i++){
            if(key[i]<min && !mst[i]){
                min=key[i];
                min_index=i;
            }
    
        } 
        return min_index;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int,int>> adj[n];
        int V=n;
        // Construct the graph with all possible edges and their Manhattan distances
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, distance});
                // Since it's an undirected graph, add the reverse edge as well
                adj[j].push_back({i, distance});
            }
        }
        vector<int> key(V,INT_MAX);
        vector<bool> mst(V,false);
        vector<int> parent(V);
    
        key[0]=0;
    
    
        for(int i=0; i<V-1; i++){
            int min_index=findMin(key,mst);
            mst[min_index]=true;
        
            for(auto it: adj[min_index]){
                if(key[it.first]>it.second && mst[it.first]==false){
                    key[it.first]=it.second;
                    parent[it.first]=min_index;
                }
            }
        }
        int minCost=0;
        for(int i=0; i<V; i++){
            minCost+=key[i];
        }

        return minCost;
    }
};

// Using Prim's Algorithm