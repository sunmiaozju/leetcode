/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (48.14%)
 * Likes:    3107
 * Dislikes: 139
 * Total Accepted:    585.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * If you were only permitted to complete at most one transaction (i.e., buy
 * one and sell one share of the stock), design an algorithm to find the
 * maximum profit.
 * 
 * Note that you cannot sell a stock before you buy one.
 * 
 * Example 1:
 * 
 * 
 * Input: [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit
 * = 6-1 = 5.
 * Not 7-1 = 6, as selling price needs to be larger than buying price.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 * 
 */
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        // int min = INT_MAX, max = -INT_MAX;
        // for (size_t i = 1; i < prices.size(); i++) {
        //     min = std::min(min, prices[i - 1]);
        //     max = std::max(max, prices[i] - min);
        // }
        // return std::max(max, 0);
        if (prices.empty()) {
            return 0;
        }
        int ans = 0, min_num = prices[0];
        for (size_t i = 1; i < prices.size(); i++) {
            ans = std::max(ans, prices[i] - min_num);
            min_num = min(min_num, prices[i]);
        }
        return ans;
    }
};
