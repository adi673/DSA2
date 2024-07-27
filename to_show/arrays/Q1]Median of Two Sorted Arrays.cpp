class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        // Ensure nums1 is smaller or equal in size to nums2 for convenience
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int left = 0, right = m;
        while (left <= right) {
            int i = left + (right - left) / 2;
            int j = (m + n + 1) / 2 - i;
            
            // Binary search condition:
            // nums1[i-1] <= nums2[j] && nums2[j-1] <= nums1[i]
            if (i < m && nums2[j-1] > nums1[i]) {
                left = i + 1; // i is too small
            } else if (i > 0 && nums1[i-1] > nums2[j]) {
                right = i - 1; // i is too big
            } else {
                // i is perfect partition point
                int maxLeft;
                if (i == 0) {
                    maxLeft = nums2[j-1];
                } else if (j == 0) {
                    maxLeft = nums1[i-1];
                } else {
                    maxLeft = max(nums1[i-1], nums2[j-1]);
                }
                
                if ((m + n) % 2 == 1) {
                    return maxLeft;
                }
                
                int minRight;
                if (i == m) {
                    minRight = nums2[j];
                } else if (j == n) {
                    minRight = nums1[i];
                } else {
                    minRight = min(nums1[i], nums2[j]);
                }
                
                return (maxLeft + minRight) / 2.0;
            }
        }
        
        return 0.0; // Unreachable, provided both arrays are not empty
    }
};
