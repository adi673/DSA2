class Solution {
public:
    int CountSold(vector<int>&row){
        return count(row.begin(),row.end(),1);
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> maxHeap;
        for(int i=0; i<mat.size(); i++){
            int soldierCount=CountSold(mat[i]);
            maxHeap.push({soldierCount,i});


            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }


        vector<int> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
    
        // Since we want the indices in ascending order, we reverse the result
        reverse(result.begin(), result.end());
    
        return result;
    }
};

// imp approach. this approach similar to learn in Q1]