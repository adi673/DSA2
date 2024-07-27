class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
            if (p1.first == p2.first) {
                return p1.second > p2.second; // When counts are equal, compare indices
            }
            return p1.first > p2.first; // Otherwise, compare counts
        }
    };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        int cols = mat[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap;

        // Count ones for each row and push into the min-heap
        for (int i = 0; i < rows; ++i) {
            int countOnes = 0;
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] == 1) {
                    countOnes++;
                } else {
                    break;
                }
            }
            minHeap.push({countOnes, i});
            
        }

        // Extract the k weakest rows from the heap
        vector<int> result;
        while(k){
            pair<int,int> val=minHeap.top();
            minHeap.pop();
            result.push_back(val.second);
            k--;
        }
        return result;
    }
};