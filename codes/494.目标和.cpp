/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 *
 * https://leetcode-cn.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (43.19%)
 * Likes:    250
 * Dislikes: 0
 * Total Accepted:    24.6K
 * Total Submissions: 56K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或
 * -中选择一个符号添加在前面。
 * 
 * 返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
 * 
 * 示例 1:
 * 
 * 输入: nums: [1, 1, 1, 1, 1], S: 3
 * 输出: 5
 * 解释: 
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * 一共有5种方法让最终目标和为3。
 * 
 * 
 * 注意:
 * 
 * 
 * 数组非空，且长度不会超过20。
 * 初始的数组的和不会超过1000。
 * 保证返回的最终结果能被32位整数存下。
 * 
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S)
    {
        if (nums.size() == 0) {
            return 0;
        }
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        if (sum < S || (sum + S) % 2 == 1) {
            return 0;
        }

        int target = (sum + S) / 2;

        // 问题转化为在数组里面找到子数组使得子数组的和等于target, 计算子数组的个数。
        vector<vector<long>> dp(nums.size(), vector<long>(target + 1, 0));

        if (nums[0] <= target) {
            dp[0][nums[0]] = 1;
        }

        for (int i = 0; i < nums.size(); i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j <= target; j++) {
                dp[i][j] = dp[i - 1][j];

                if (nums[i] <= j) {
                    dp[i][j] += dp[i - 1][j - nums[i]];
                }

                cout << i << " " << j << " " << dp[i][j] << endl;
                // cout << p1 << " " << p2 << endl;
            }
        }

        return dp[nums.size() - 1][target];
    }
};
// @lc code=end
