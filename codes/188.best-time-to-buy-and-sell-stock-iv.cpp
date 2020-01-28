/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (26.82%)
 * Likes:    1090
 * Dislikes: 66
 * Total Accepted:    109.8K
 * Total Submissions: 401.5K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * Say you have an array for which the i-th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most k
 * transactions.
 * 
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * 
 * Example 1:
 * 
 * 
 * Input: [2,4,1], k = 2
 * Output: 2
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit
 * = 4-2 = 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,6,5,0,3], k = 2
 * Output: 7
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit
 * = 6-2 = 4.
 * Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 =
 * 3.
 * 
 * 
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices)
    {
        if (prices.empty()) {
            return 0;
        }

        if (k >= prices.size() / 2) {
            int maxProfit = 0;
            for (int i = 1; i < prices.size(); i++) {
                if (prices[i] > prices[i - 1]) {
                    maxProfit += prices[i] - prices[i - 1];
                }
            }
            return maxProfit;
        }

        vector<vector<int>> global(prices.size(), vector<int>(k + 1, 0));
        vector<vector<int>> local(prices.size(), vector<int>(k + 1, 0));

        for (int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i - 1];
            for (int j = 1; j <= k; j++) {
                local[i][j] = max(local[i - 1][j] + diff, global[i - 1][j - 1] + max(0, diff));
                global[i][j] = max(local[i][j], global[i - 1][j]);
            }
        }

        return global[prices.size() - 1][k];
    }
};
// @lc code=end
