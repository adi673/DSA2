class Solution{
    public:
        long long pairWithMaxSum(long long arr[], long long N)
    {
        long long maxi=0;
        for(int i=0;i<N-1;i++) {
            maxi = max(maxi, arr[i]+arr[i+1]);
        }
        return maxi;
    }
};

//Q]Given an array Arr, with indexes running from 0 to N, select any two indexes, i and j such that i<=j-1. From subarray Arr[i...j], find the two smallest numbers and add them, you will get score for that subarray. Your task is to return maximum score possible in the given array Arr.
 
 //https://practice.geeksforgeeks.org/problems/pair-with-maximum-sum/0


 //logic is simplay 2 consecutive numbers having highest sum will be pair with maximum sum always