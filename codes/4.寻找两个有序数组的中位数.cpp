/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (36.78%)
 * Likes:    2227
 * Dislikes: 0
 * Total Accepted:    150.5K
 * Total Submissions: 407K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 * 
 * 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 * 
 * 你可以假设 nums1 和 nums2 不会同时为空。
 * 
 * 示例 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * 则中位数是 2.0
 * 
 * 
 * 示例 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * 则中位数是 (2 + 3)/2 = 2.5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        return (help(nums1, nums2, 0, 0, (m + n + 1) / 2) + help(nums1, nums2, 0, 0, (m + n + 2) / 2)) / 2.0;
    }

    int help(vector<int>& nums1, vector<int>& nums2, int i, int j, int k)
    {
        if (i >= nums1.size()) {
            return nums2[j + k - 1];
        } else if (j >= nums2.size()) {
            return nums1[i + k - 1];
        }

        if (k == 1) {
            return min(nums1[i], nums2[j]);
        }

        int val1 = i + k / 2 - 1 < nums1.size() ? nums1[i + k / 2 - 1] : INT_MAX;
        int val2 = j + k / 2 - 1 < nums2.size() ? nums2[j + k / 2 - 1] : INT_MAX;
        if (val1 < val2) {
            return help(nums1, nums2, i + k / 2, j, k - k / 2);
        } else {
            return help(nums1, nums2, i, j + k / 2, k - k / 2);
        }
    }
};
// @lc code=end
