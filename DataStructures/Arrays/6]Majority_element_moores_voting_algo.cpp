class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int element;
        int count=0;
        for(int i=0; i<nums.size(); i++){
           if(count==0){
            count=1;
            element=nums[i];
           }else if(element==nums[i]){
            count++;
           }else{
            count--;
           }
        }
        int cnt1=0;
        for(int i=0; i<nums.size();i++){
            if(nums[i]==element){
                cnt1++;
            }
        }
        
        if(cnt1>(nums.size())/2){
            return element;
        }
        return -1;
    }
   
};


//Moore’s Voting Algorithm
// Optimal Approach: Moore’s Voting Algorithm:
// Intuition:
// If the array contains a majority element, its occurrence must be greater than the floor(N/2). Now, we can say that the count of minority elements and majority elements is equal up to a certain point in the array. So when we traverse through the array we try to keep track of the count of elements and the element itself for which we are tracking the count. 

// After traversing the whole array, we will check the element stored in the variable. If the question states that the array must contain a majority element, the stored element will be that one but if the question does not state so, then we need to check if the stored element is the majority element or not. If not, then the array does not contain any majority element.

// Approach: 
// Initialize 2 variables:
// Count –  for tracking the count of element
// Element – for which element we are counting
// Traverse through the given array.
// If Count is 0 then store the current element of the array as Element.
// If the current element and Element are the same increase the Count by 1.
// If they are different decrease the Count by 1.
// The integer present in Element should be the result we are expecting 