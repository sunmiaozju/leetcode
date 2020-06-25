/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 *
 * https://leetcode-cn.com/problems/coin-change-2/description/
 *
 * algorithms
 * Medium (47.56%)
 * Likes:    137
 * Dislikes: 0
 * Total Accepted:    10.7K
 * Total Submissions: 21.5K
 * Testcase Example:  '5\n[1,2,5]'
 *
 * 给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。 
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: amount = 5, coins = [1, 2, 5]
 * 输出: 4
 * 解释: 有四种方式可以凑成总金额:
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 * 
 * 
 * 示例 2:
 * 
 * 输入: amount = 3, coins = [2]
 * 输出: 0
 * 解释: 只用面额2的硬币不能凑成总金额3。
 * 
 * 
 * 示例 3:
 * 
 * 输入: amount = 10, coins = [10] 
 * 输出: 1
 * 
 * 
 * 
 * 
 * 注意:
 * 
 * 你可以假设：
 * 
 * 
 * 0 <= amount (总金额) <= 5000
 * 1 <= coin (硬币面额) <= 5000
 * 硬币种类不超过 500 种
 * 结果符合 32 位符号整数
 * 
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        if (coins.size() == 0) {
            return amount == 0 ? 1 : 0;
        }
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));

        // 初始值的初始化很重要，这里amount=0标记为dp为0,有些不好理解。
        // 就是说我不拿出任何硬币，也可以满足amount=0，将不拿出也作为一种情况。
        for (int i = 0; i < coins.size(); i++) {
            dp[i][0] = 1;
        }

        for (int i = 0; i < coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {

                int p1 = 0;
                if (i >= 1) {
                    p1 = dp[i - 1][j];
                }

                int p2 = 0;
                if (j >= coins[i]) {
                    p2 = dp[i][j - coins[i]];
                }

                dp[i][j] = p1 + p2;
            }
        }

        return dp[coins.size() - 1][amount];
    }
};
// @lc code=end
