static bool comp(vector<int>& a, vector<int>& b){
    return a[2]<b[2];
}

class DisjointSet{
    vector<int> size,parent;
    public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1,0);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    
    int findParent(int n){
        if(parent[n]==n) return n;
        return parent[n] = findParent(parent[n]);
    }
    
    void unionBySize(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu==pv) return;
        if(size[pu]<size[pv]){
            parent[pu] = pv;
            size[pv]+=size[pu];
        } 
        else{
            parent[pv] = pu;
            size[pu]+=size[pv];
        }
    }

    int getSize(int i){
        return size[i];
    }

    int maxSize(int n){
        int ans = 0;
        for(int i=0;i<n;i++) if(parent[i]==i) ans++;
        return ans;
    }

    bool isConnected(int n){
        int flag=false;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                if(flag) return false;
                flag=true;
            } 
        }
        return flag;
    }
};

class Solution {
public:
    int getMSTCost(int n, vector<vector<int>>& edges, int skip, int force) {
        DisjointSet D(n);
        int ans = 0;
        if(force!=-1) {
            int u = edges[force][0];
            int v = edges[force][1];
            int dist = edges[force][2];
            D.unionBySize(u, v);
            ans += dist;
        }
        for(int i=0;i<edges.size();i++) {
            if (i == skip ) continue;
            int u = edges[i][0];
            int v = edges[i][1];
            int dist = edges[i][2];
            if (D.findParent(u) != D.findParent(v)) {
                D.unionBySize(u, v);
                ans += dist;
            }
        }
        if (!D.isConnected(n)) return INT_MAX;
        return ans;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++) edges[i].push_back(i);
        sort(edges.begin(),edges.end(),comp);
        int mst = getMSTCost(n,edges,-1,-1);
        vector<vector<int>> ans(2);
        for(int i=0;i<edges.size();i++) {
            int new_mst = getMSTCost(n,edges,i,-1);
            if (new_mst>mst) ans[0].push_back(edges[i][3]); 
            else{
                new_mst  = getMSTCost(n,edges,-1,i);
                if (new_mst == mst) ans[1].push_back(edges[i][3]);
            }
        }
        return ans;
    }
};
//revise 2x
//https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/
// https://www.youtube.com/watch?v=YCm7eQBovxE
// https://youtu.be/gDPh7gsK3F8