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

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount){
        // vector<vector<int>> dp(2, vector<int>(amount+1, 0));
        // for(int i=0;i<coins.size();i++){
        //     for(int j=1;j<=amount;j++){
        //         int num1 = INT_MAX;
        //         if(i>=1){
        //             num1 = dp[(i-1)%2][j];
        //         }
        //         int num2 = INT_MAX;
        //         if(j >= coins[i]){
        //             if(dp[i%2][j-coins[i]] != INT_MAX){
        //                 num2 = dp[i%2][j-coins[i]] + 1;                        
        //             }
        //         }
        //         dp[i%2][j] = min(num1, num2);
        //     }
        // }
        // return dp[(coins.size()-1)%2][amount] == INT_MAX ? -1 : dp[(coins.size()-1)%2][amount];

        vector<int> dp(amount+1, 0);
        for(int i=0;i<coins.size();i++){
            for(int j=1;j<=amount;j++){
                int num1 = INT_MAX;  
                if(i>=1){
                    num1 = dp[j];
                }    
                int num2 = INT_MAX;
                if(j >= coins[i]){
                    if(dp[j-coins[i]] != INT_MAX){
                        num2 = dp[j-coins[i]] + 1;                        
                    }
                }
                dp[j] = min(num1, num2);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

// @lc code=end

