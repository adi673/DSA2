class Solution {
public:
    class DisjointSet {
        vector<int> rank, parent, size;
    public:
        DisjointSet(int n) {
            rank.resize(n+1, 0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i = 0; i < n+1; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUltimateParent(int node) {
            if(node == parent[node]) {
                return node;
            }
            return parent[node] = findUltimateParent(parent[node]);
        }

        void unionByRank(int u, int v) {
            int ulp_u = findUltimateParent(u);
            int ulp_v = findUltimateParent(v);

            if(ulp_u == ulp_v) {
                return;
            }

            if(rank[ulp_u] > rank[ulp_v]) {
                parent[ulp_v] = ulp_u;
            } else if(rank[ulp_v] > rank[ulp_u]) {
                parent[ulp_u] = ulp_v;
            } else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
    };
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;

        // Construct the graph with all possible edges and their Manhattan distances
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({distance, i, j});
            }
        }

        // Sort the edges by their weights (Manhattan distances)
        sort(edges.begin(), edges.end());

        DisjointSet ds(n);
        int minCost = 0;

        // Kruskal's algorithm to find the minimum spanning tree
        for (auto& edge : edges) {
            int distance = edge[0];
            int u = edge[1];
            int v = edge[2];

            if (ds.findUltimateParent(u) != ds.findUltimateParent(v)) {
                ds.unionByRank(u, v);
                minCost += distance;
            }
        }

        return minCost;
    }
};
// revise 1x
// leetode.com/problems/min-cost-to-connect-all-points/
// logic: we want to form min spanning tree as  we want mimnimum cost to connect all points (we need connnected componenets)
// here first we will connect every point with each other
// now sort them according to edges weight
// applying krushkal algo wil make shure we are connecting points with minimum cost