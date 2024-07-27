class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flipCount = 0;  // To keep track of the total number of flips
        int currentFlip = 0;  // To keep track of the current flip effect

        vector<int> isFlipped(n, 0);  // To mark the positions where a flip ends

        for (int i = 0; i < n; ++i) {
            // If the current index is out of the range of k flips, we update the current flip effect
            if (i >= k) {
                currentFlip ^= isFlipped[i - k];
            }
            // If the current bit is 0 and we have an even number of flips (currentFlip is 0)
            // or if the current bit is 1 and we have an odd number of flips (currentFlip is 1),
            // we need to flip the k-length subarray starting at the current index
            if (nums[i] == currentFlip) {
                // If there's not enough space to flip k bits, return -1
                if (i + k > n) {
                    return -1;
                }
                // Flip the current bit
                flipCount++;
                currentFlip ^= 1;
                isFlipped[i] = 1;
            }
        }

        return flipCount;
    }
};
//not done by me
//greedy approach
//get good hands on greedy also

//www.leetcod.com/problems/minimum-number-of-k-consecutive-bit-flips/