class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int starting_index;
        int ending_index;
        int sum=0;
        int start;
       for(int i=0; i<nums.size(); i++){
            if(sum==0){
                start=i;
            }
            sum=sum+nums[i];

            if(sum>maxi){
                maxi=sum;
                starting_index=start;
                ending_index=i;
            }


            if(sum<0){
                sum=0;
            }

       }
        return maxi;
    }
    
    
};

// Kadane's Algorithm

// Intuition:
// The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less than 0. A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum.

// Here, we will iterate the given array with a single loop and while iterating we will add the elements in a sum variable. Now, if at any point the sum becomes less than 0, we will set the sum as 0 as we are not going to consider any subarray with a negative sum. Among all the sums calculated, we will consider the maximum one.

// Thus we can solve this problem with a single loop.

// Approach:
// The steps are as follows:

// We will run a loop(say i) to iterate the given array.
// Now, while iterating we will add the elements to the sum variable and consider the maximum one.
// If at any point the sum becomes negative we will set the sum to 0 as we are not going to consider it as a part of our answer.
// Note: In some cases, the question might say to consider the sum of the empty subarray while solving this problem. So, in these cases, before returning the answer we will compare the maximum subarray sum calculated with 0(i.e. The sum of an empty subarray is 0). And after that, we will return the maximum one.
// For e.g. if the given array is {-1, -4, -5}, the answer will be 0 instead of -1 in this case. 

// This is applicable to all the approaches discussed above.

// But if this case is not explicitly mentioned we will not consider this case.


//https://www.youtube.com/watch?v=AHZpyENo7k4
//https://leetcode.com/problems/maximum-subarray/description/