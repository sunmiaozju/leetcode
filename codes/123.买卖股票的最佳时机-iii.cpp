/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *
 * algorithms
 * Hard (40.95%)
 * Likes:    331
 * Dislikes: 0
 * Total Accepted:    28.4K
 * Total Submissions: 67.3K
 * Testcase Example:  '[3,3,5,0,0,3,1,4]'
 *
 * 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
 * 
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
 * 
 * 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 
 * 示例 1:
 * 
 * 输入: [3,3,5,0,0,3,1,4]
 * 输出: 6
 * 解释: 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
 * 随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
 * 
 * 示例 2:
 * 
 * 输入: [1,2,3,4,5]
 * 输出: 4
 * 解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4
 * 。   
 * 注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
 * 因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
 * 
 * 
 * 示例 3:
 * 
 * 输入: [7,6,4,3,1] 
 * 输出: 0 
 * 解释: 在这个情况下, 没有交易完成, 所以最大利润为 0。
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.empty()) {
            return 0;
        }

        vector<vector<int>> local(prices.size(), vector<int>(3, 0));
        vector<vector<int>> global(prices.size(), vector<int>(3, 0));
        for (int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i - 1];
            for (int j = 1; j <= 2; j++) {
                /*
                可以这样来理解：local[i][j]=max(global[i-1][j-1]+max(diff,0),local[i-1][j]+diff)
                第 i 天卖第 j 支股票的话，一定是下面的一种：

                1. 今天刚买的
                那么 Local(i, j) = Global(i-1, j-1)
                相当于啥都没干

                2. 昨天买的
                那么 Local(i, j) = Global(i-1, j-1) + diff
                等于Global(i-1, j-1) 中的交易，加上今天干的那一票

                3. 更早之前买的
                那么 Local(i, j) = Local(i-1, j) + diff
                昨天别卖了，留到今天卖
                */
                local[i][j] = max(global[i - 1][j - 1] + max(0, diff), local[i - 1][j] + diff);
                global[i][j] = max(global[i - 1][j], local[i][j]);
            }
        }
        return global[prices.size() - 1][2];
    }
};
// @lc code=end
