#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        // Min-heap to store projects by their capital requirements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        // Max-heap to store profits of projects that can be funded with the current capital
        priority_queue<int> maxHeap;
        
        // Initialize the min-heap with all projects
        for (int i = 0; i < n; i++) {
            minHeap.push({capital[i], profits[i]});
        }
        
        // Iterate up to k times to select at most k projects
        for (int i = 0; i < k; i++) {
            // Move all projects that can be funded with current capital to the max-heap
            while (!minHeap.empty() && minHeap.top().first <= w) {
                maxHeap.push(minHeap.top().second);
                minHeap.pop();
            }
            
            // If there are no projects that can be funded, break the loop
            if (maxHeap.empty()) {
                break;
            }
            
            // Select the project with the maximum profit
            w += maxHeap.top();
            maxHeap.pop();
        }
        
        return w;
    }
};
