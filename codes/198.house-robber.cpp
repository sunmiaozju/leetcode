/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (41.28%)
 * Likes:    3050
 * Dislikes: 95
 * Total Accepted:    372.3K
 * Total Submissions: 900.8K
 * Testcase Example:  '[1,2,3,1]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money =
 * 3).
 * Total amount you can rob = 1 + 3 = 4.
 * 
 * Example 2:
 * 
 * 
 * Input: [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house
 * 5 (money = 1).
 * Total amount you can rob = 2 + 9 + 1 = 12.
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums)
    {
        // int pre = 0, pre_pre = 0;
        // for (size_t i = 0; i < nums.size(); i++) {
        //     int tmp = max(pre_pre + nums[i], pre);
        //     pre_pre = pre;
        //     pre = tmp;
        // }
        // return pre;

        // if (nums.size() < 3) {
        //     return nums.empty() ? 0 : nums.size() == 1 ? nums[0] : max(nums[0], nums[1]);
        // }
        // int dp[nums.size()];
        // dp[0] = nums[0];
        // dp[1] = max(nums[1], nums[0]);
        // for (size_t i = 2; i < nums.size(); i++) {
        //     dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        // }
        // return dp[nums.size() - 1];

        if (nums.empty()) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        vector<int> dp(vector<int>(nums.size(), 0));
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (size_t i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
    // int rob(vector<int>& nums, int left, int right)
    // {
    //     switch (right - left) {
    //     case -1:
    //         return 0;
    //         break;
    //     case 0:
    //         return nums[left];
    //         break;
    //     case 1:
    //         return max(nums[left], nums[right]);
    //         break;
    //     case 2:
    //         return max(nums[left] + nums[right], nums[left + 1]);
    //         break;
    //     default:
    //         return max(nums[left] + rob(nums, left + 2, right), nums[left + 1] + rob(nums, left + 3, right));
    //         break;
    //     }
    //     return -1;
    // }
};
// @lc code=end
