/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (51.23%)
 * Likes:    254
 * Dislikes: 0
 * Total Accepted:    19.3K
 * Total Submissions: 36.6K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * 给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​
 * 
 * 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
 * 
 * 
 * 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 * 
 * 
 * 示例:
 * 
 * 输入: [1,2,3,0,2]
 * 输出: 3 
 * 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.size() == 0) {
            return 0;
        }

        vector<int> have(prices.size(), 0);
        vector<int> notHave(prices.size(), 0);

        have[0] = -prices[0];
        notHave[0] = 0;
        for (int i = 1; i < prices.size(); i++) {
            have[i] = max(have[i - 1], (i >= 2 ? notHave[i - 2] : 0) - prices[i]);
            notHave[i] = max(notHave[i - 1], have[i - 1] + prices[i]);
        }
        return notHave[prices.size() - 1];
    }
};
// @lc code=end
