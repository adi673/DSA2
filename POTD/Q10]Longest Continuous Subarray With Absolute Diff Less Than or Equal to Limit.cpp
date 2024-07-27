class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int low = 0, high = 0, sub_size = 0;
        deque<int> min_deque, max_deque;

        while (high < nums.size()) {
            while (!min_deque.empty() && nums[high] < nums[min_deque.back()]) {
                min_deque.pop_back();
            }
            while (!max_deque.empty() && nums[high] > nums[max_deque.back()]) {
                max_deque.pop_back();
            }
            min_deque.push_back(high);
            max_deque.push_back(high);

            if (nums[max_deque.front()] - nums[min_deque.front()] <= limit) {
                sub_size = max(sub_size, high - low + 1);
                high++;
            } else {
                if (min_deque.front() == low) {
                    min_deque.pop_front();
                }
                if (max_deque.front() == low) {
                    max_deque.pop_front();
                }
                low++;
                high++;
            }
        }
        return sub_size;
    }
};

//not understood properly
//sliding window apporaach using dqueue
//why dequeue didn't get it
//revise 2x
//https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/discuss/609743/C%2B%2B-Sliding-Window-Deque-O(N)-Time-O(N)-Space
