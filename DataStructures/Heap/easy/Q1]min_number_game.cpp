class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minheap;
        int i=0;
        while(i<nums.size()){
            minheap.push(nums[i]);
            i++;
        }
        vector<int> result;
        while(!minheap.empty()){
            int top1=minheap.top();
            minheap.pop();
            if(!minheap.empty()){ //corner case when after Alice removes the element the heap becomes empty
                result.push_back(minheap.top());
                minheap.pop();
            }
            result.push_back(top1);
        }
        return result;
    }
};