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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap;
        map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
        }

        for (auto& entry : mp) {
            minHeap.push({entry.second, entry.first});

            if(minHeap.size()>k){
                minHeap.pop();
            }
        }

        vector<int>result;

        while(!minHeap.empty()){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return result;

    }
};