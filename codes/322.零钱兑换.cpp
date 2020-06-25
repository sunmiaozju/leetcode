/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 *
 * https://leetcode-cn.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (37.41%)
 * Likes:    525
 * Dislikes: 0
 * Total Accepted:    71.1K
 * Total Submissions: 183.1K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给定不同面额的硬币 coins 和一个总金额
 * amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
 * 
 * 示例 1:
 * 
 * 输入: coins = [1, 2, 5], amount = 11
 * 输出: 3 
 * 解释: 11 = 5 + 5 + 1
 * 
 * 示例 2:
 * 
 * 输入: coins = [2], amount = 3
 * 输出: -1
 * 
 * 说明:
 * 你可以认为每种硬币的数量是无限的。
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, INT_MAX));

        // 初始值的初始化很重要，这里amount=0标记为dp为0,有些不好理解。
        // 就是说我不拿出任何硬币，也可以满足amount=0，将不拿出也作为一种情况。
        for (int i = 0; i < coins.size(); i++) {
            dp[i][0] = 0;
        }

        for (int i = 0; i < coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {

                int p1 = INT_MAX;
                if (i >= 1) {
                    p1 = dp[i - 1][j];
                }

                int p2 = INT_MAX;
                if (j >= coins[i] && dp[i][j - coins[i]] != INT_MAX) {
                    p2 = dp[i][j - coins[i]] + 1;
                }

                dp[i][j] = min(p1, p2);
            }
        }

        return dp[coins.size() - 1][amount] == INT_MAX ? -1 : dp[coins.size() - 1][amount];
    }
};

// @lc code=end
