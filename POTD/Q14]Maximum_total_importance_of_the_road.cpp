class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n,0);
        for(auto it: roads){
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        set<pair<int, int>> s;
        for(int i=0; i<n; i++){
            s.insert({indegree[i],i});
        }
        vector<int>val(n,0);
        int i=1;
        while(i<=n){
            pair<int, int>p = *(s.begin());
            int index=p.second;
            val[index]=i;
            s.erase(s.begin());
            i++;
        }
        long long sum=0LL;
        for(auto it:roads ){
            int node1=it[0];
            int node2=it[1];
            sum=sum+val[node1]+val[node2];
        }
        return sum;
    }
};