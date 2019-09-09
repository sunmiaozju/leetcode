/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (36.63%)
 * Likes:    1274
 * Dislikes: 3036
 * Total Accepted:    410.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * Note:
 * 
 * 
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * Output: [1,2,2,3,5,6]
 * 
 * 
 */
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        // vector<int> ans = nums1;
        // int a = 0, b = 0, c = 0;
        // while (c < m + n) {
        //     if (a < m && b < n) {
        //         if (nums1[a] <= nums2[b]) {
        //             ans[c++] = nums1[a++];
        //         } else {
        //             ans[c++] = nums2[b++];
        //         }
        //     } else if (a < m) {
        //         ans[c++] = nums1[a++];
        //     } else {
        //         ans[c++] = nums2[b++];
        //     }
        // }
        // nums1 = ans;

        int a = m - 1, b = n - 1, c = m + n - 1;

        while (b >= 0) {
            if (a >= 0 && nums1[a] >= nums2[b]) {
                nums1[c--] = nums1[a--];
            } else {
                nums1[c--] = nums2[b--];
            }
        }
    }
};
