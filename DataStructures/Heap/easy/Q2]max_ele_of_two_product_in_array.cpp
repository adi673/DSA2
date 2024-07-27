class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> maxheap;

        for(int i=0; i<nums.size(); i++){
            maxheap.push(nums[i]);
        }

        int n1=maxheap.top();
        maxheap.pop();
        int n2=maxheap.top();
        maxheap.pop();

        return ((n1-1)*(n2-1));
    }
};