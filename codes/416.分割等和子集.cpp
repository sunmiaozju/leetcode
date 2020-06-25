/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode-cn.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (44.95%)
 * Likes:    241
 * Dislikes: 0
 * Total Accepted:    24.9K
 * Total Submissions: 53.6K
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 
 * 注意:
 * 
 * 
 * 每个数组中的元素不会超过 100
 * 数组的大小不会超过 200
 * 
 * 
 * 示例 1:
 * 
 * 输入: [1, 5, 11, 5]
 * 
 * 输出: true
 * 
 * 解释: 数组可以分割成 [1, 5, 5] 和 [11].
 * 
 * 
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1, 2, 3, 5]
 * 
 * 输出: false
 * 
 * 解释: 数组不能分割成两个元素和相等的子集.
 * 
 * 
 * 
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1) {
            return false;
        }

        int target = sum / 2;

        vector<vector<bool>> dp(nums.size(), vector<bool>(target + 1, false));

        if (nums[0] <= target) {
            dp[0][nums[0]] = true;
        }

        for (int i = 0; i < nums.size(); i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 1; j <= target; j++) {
                bool p1 = dp[i - 1][j];
                bool p2 = false;
                if (nums[i] <= j) {
                    p2 = dp[i - 1][j - nums[i]];
                }
                dp[i][j] = p1 || p2;
                // cout << i << " " << j << " " << dp[i][j] << endl;
            }
        }
        return dp[nums.size() - 1][target];
    }
};
// @lc code=end
