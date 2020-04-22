/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
 *
 * algorithms
 * Medium (61.09%)
 * Likes:    142
 * Dislikes: 0
 * Total Accepted:    13.7K
 * Total Submissions: 21.6K
 * Testcase Example:  '[1,3,2,8,4,9]\n2'
 *
 * 给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。
 * 
 * 你可以无限次地完成交易，但是你每次交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
 * 
 * 返回获得利润的最大值。
 * 
 * 示例 1:
 * 
 * 输入: prices = [1, 3, 2, 8, 4, 9], fee = 2
 * 输出: 8
 * 解释: 能够达到的最大利润:  
 * 在此处买入 prices[0] = 1
 * 在此处卖出 prices[3] = 8
 * 在此处买入 prices[4] = 4
 * 在此处卖出 prices[5] = 9
 * 总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
 * 
 * 注意:
 * 
 * 
 * 0 < prices.length <= 50000.
 * 0 < prices[i] < 50000.
 * 0 <= fee < 50000.
 * 
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        if (prices.size() == 0) {
            return 0;
        }

        vector<int> have(prices.size(), 0);
        vector<int> notHave(prices.size(), 0);

        have[0] = -prices[0];
        notHave[0] = 0;

        for (int i = 1; i < prices.size(); i++) {
            notHave[i] = max(notHave[i - 1], have[i - 1] + prices[i] - fee);
            have[i] = max(have[i - 1], notHave[i - 1] - prices[i]);
        }

        return max(0, notHave[prices.size() - 1]);
    }
};
// @lc code=end
