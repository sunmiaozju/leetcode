/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (44.36%)
 * Likes:    4934
 * Dislikes: 184
 * Total Accepted:    608.8K
 * Total Submissions: 1.4M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        // ???
        // int max_sum = -INT_MAX;
        // for (size_t i = 0; i < nums.size(); i++) {
        //     int sum_single = nums[i];
        //     if (nums[i] > 0) {
        //         int sum = nums[i];
        //         sum_single = sum;
        //         for (size_t j = i + 1; j < nums.size(); j++) {
        //             sum += nums[j];
        //             if (nums[j] > 0 && sum > sum_single) {
        //                 sum_single = sum;
        //             }
        //         }
        //     }
        //     if (sum_single > max_sum) {
        //         max_sum = sum_single;
        //     }
        // }
        // return max_sum;

        // ?????
        // if (nums.empty()) {
        //     return 0;
        // }
        // int sum_min = INT_MAX;
        // int sum = 0;
        // int sum_max = -INT_MAX;
        // for (size_t i = 0; i < nums.size(); i++) {
        //     if (sum < sum_min) {
        //         sum_min = sum;
        //     }
        //     if (sum + nums[i] - sum_min > sum_max) {
        //         sum_max = sum + nums[i] - sum_min;
        //     }
        //     sum += nums[i];
        // }
        // return sum_max;

        // ??????
        if (nums.empty()) {
            return 0;
        }
        int max, rmax, lmax, sum;
        maxSubArray(nums, 0, nums.size() - 1, max, lmax, rmax, sum);
        return max;
    }

    void maxSubArray(vector<int>& nums, int l, int r, int& max, int& lmax, int& rmax, int& sum)
    {
        if (l == r) {
            max = lmax = rmax = sum = nums[l];
            return;
        }

        int m = r + ((l - r) >> 1);
        int max_l, lmax_l, rmax_l, sum_l;
        int max_r, lmax_r, rmax_r, sum_r;

        maxSubArray(nums, l, m, max_l, lmax_l, rmax_l, sum_l);
        maxSubArray(nums, m + 1, r, max_r, lmax_r, rmax_r, sum_r);

        max = std::max(rmax_l + lmax_r, std::max(max_l, max_r));
        lmax = std::max(lmax_l, sum_l + lmax_r);
        rmax = std::max(rmax_r, rmax_l + sum_r);
        sum = sum_l + sum_r;
        return;
    }
};
