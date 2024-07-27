class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k) - helper(nums, k-1);
    }

    int helper(vector<int>& nums, int k){
        int count = 0, left = 0, odd_count = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] % 2 == 1) {
                odd_count++;
            }

            while (odd_count > k) {
                if (nums[left] % 2 == 1) {
                    odd_count--;
                }
                left++;
            }

            count += right - left + 1;
        }

        return count;
    }
};