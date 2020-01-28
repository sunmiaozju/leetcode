/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (44.75%)
 * Likes:    1840
 * Dislikes: 68
 * Total Accepted:    116.8K
 * Total Submissions: 257.2K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (ie, buy one and sell one share of the stock
 * multiple times) with the following restrictions:
 * 
 * 
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1
 * day)
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,0,2]
 * Output: 3 
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 * 
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.empty()) {
            return 0;
        }

        vector<int> have(prices.size() + 1, 0);
        vector<int> nothave(prices.size() + 1, 0);

        have[0] = -prices[0];
        nothave[0] = 0;

        for (int i = 1; i < prices.size(); i++) {
            have[i] = max(have[i - 1], (i >= 2 ? nothave[i - 2] : 0) - prices[i]);
            nothave[i] = max(nothave[i - 1], have[i - 1] + prices[i]);
        }

        return nothave[prices.size() - 1];
    }
};
// @lc code=end
