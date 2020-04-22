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

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        return (help(nums1, nums2, 0, m - 1, 0, n - 1, (m + n + 1) / 2) + help(nums1, nums2, 0, m - 1, 0, n - 1, (m + n + 2) / 2)) / 2.0;
    }

    double help(vector<int>& nums1, vector<int>& nums2, int s1, int e1, int s2, int e2, int k)
    {
        int len1 = e1 - s1 + 1;
        int len2 = e2 - s2 + 1;
        // 确保nums1是较小的数组。
        if (len1 > len2) {
            return help(nums2, nums1, s2, e2, s1, e1, k);
        }
        if (s1 > e1) {
            return nums2[s2 + k - 1];
        }

        if (k == 1) {
            return min(nums1[s1], nums2[s2]);
        }

        int index1 = s1 + min(len1, k / 2) - 1;
        int index2 = s2 + min(len2, k / 2) - 1;

        if (nums1[index1] < nums2[index2]) {
            return help(nums1, nums2, index1 + 1, e1, s2, e2, k - (index1 - s1 + 1));
        } else {
            return help(nums1, nums2, s1, e1, index2 + 1, e2, k - (index2 - s2 + 1));
        }
    }
};
// @lc code=end
