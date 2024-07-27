class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        vector<priority_queue<int>> heaps;

    // Convert each row into a max-heap
    for (const auto& row : grid) {
        priority_queue<int> maxHeap(row.begin(), row.end());
        heaps.push_back(maxHeap);
    }

    int answer = 0;

    while(!heaps.empty() && !heaps[0].empty()){ //didnt ge condition after and oeprator

        int maxInThisRound = 0;

        // Remove the maximum element from each heap and track the maximum value among them
        for (auto& heap : heaps) {
            if (!heap.empty()) {
                int maxValue = heap.top();
                heap.pop();
                maxInThisRound = max(maxInThisRound, maxValue);
            }
        }
        answer=answer+maxInThisRound;
    }

    return answer;
    }
};

//revise once