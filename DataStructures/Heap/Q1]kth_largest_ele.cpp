class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minheap;

        for(int i=0; i<nums.size(); i++){
            if(i<k){
                cout<<"pushing : "<<nums[i]<<endl;
                minheap.push(nums[i]);
            }else{
                if(nums[i]>minheap.top()){
                    cout<<"poping : "<<minheap.top()<<endl;
                    minheap.pop();
                    cout<<"pushing : "<<nums[i]<<endl;
                    minheap.push(nums[i]);
                }
            }
        }

        return minheap.top();

    }
};