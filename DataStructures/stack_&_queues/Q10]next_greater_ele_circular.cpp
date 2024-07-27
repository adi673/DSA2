class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        map <int,int>mp;
        stack<int>st;
        int n=nums.size();
        vector < int > temp1(n, -1);
        for(int i=2*n-1; i>=0; i--){
            while(!st.empty()&&st.top()<=nums[i%n]){
                st.pop();
            }
            if(i<n){
                if(!st.empty()){
                    temp1[i]=st.top();
                }
            }
            st.push(nums[i%n]);
        }
        return temp1;
    }
};