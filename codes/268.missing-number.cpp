/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (49.19%)
 * Likes:    1129
 * Dislikes: 1530
 * Total Accepted:    328.9K
 * Total Submissions: 665.6K
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,0,1]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * 
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        // int table[nums.size() + 1] = { 0 };
        // for (size_t i = 0; i < nums.size(); i++) {
        //     table[nums[i]] = 1;
        // }
        // for (size_t i = 0; i < nums.size() + 1; i++) {
        //     if (table[i] != 1) {
        //         return i;
        //     }
        // }
        // return -1;

        // int sum = 0, n = nums.size();
        // for (auto& a : nums) {
        //     sum += a;
        // }
        // return 0.5 * n * (n + 1) - sum;

        int ans = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            ans ^= (i + 1) ^ nums[i];
        }
        return ans;
    }
};
// @lc code=end
