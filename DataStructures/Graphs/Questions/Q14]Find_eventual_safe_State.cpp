class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> revadj[n];
        vector<int> indegree(n,0);
        for(int i=0; i<n; i++){
            for(auto it1 : graph[i]){
                revadj[it1].push_back(i);
                indegree[i]++;
            }
        }
        vector<int> result;
        queue<int> q;
        for (int i = 0; i < n; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

        while(!q.empty()){
            int node=q.front();
            q.pop();
            result.push_back(node);
            for (auto it : revadj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
        }
        sort(result.begin(),result.end());
        return result; 
    }
};

//reverse the adjacecy list
//and we will start fron node with indegree 0
//and perform BFS
//https://takeuforward.org/data-structure/find-eventual-safe-states-bfs-topological-sort-g-25/
//revise x2
// https://youtu.be/2gtg3VsDGyc