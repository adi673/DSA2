class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flipCount = 0;  // To keep track of the total number of flips
        int currentFlip = 0;  // To keep track of the current flip effect

        for (int i = 0; i < n; ++i) {
            // If the current index is beyond the flip range k, revert the flip effect
            if (i >= k && nums[i - k] < 0) {
                currentFlip ^= 1;
            }

            // If nums[i] == currentFlip, it means we need to flip the k-length subarray starting at i
            if (nums[i] == currentFlip) {
                // If there is not enough space to flip k bits, return -1
                if (i + k > n) {
                    return -1;
                }
                // Flip the current bit
                flipCount++;
                currentFlip ^= 1;
                // Mark the start of a flip operation using a negative value
                nums[i] -= 2; // Any negative value to mark the flip, here using -2 as an example
            }
        }

        return flipCount;
    }
};

//not done by me
//get good hands on sliding windowASAP

//https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/