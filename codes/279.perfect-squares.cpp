/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (43.00%)
 * Likes:    1856
 * Dislikes: 156
 * Total Accepted:    222.2K
 * Total Submissions: 511.2K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 * 
 * Example 1:
 * 
 * 
 * Input: n = 12
 * Output: 3 
 * Explanation: 12 = 4 + 4 + 4.
 * 
 * Example 2:
 * 
 * 
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */

// @lc code=start

#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n)
    {
        // vector<int> dp(n + 1, INT_MAX);
        // dp[0] = 0;
        // for (size_t i = 1; i <= n; i++) {
        //     for (size_t j = 1; j * j <= i; j++) {
        //         dp[i] = min(dp[i - j * j] + 1, dp[i]);
        //     }
        // }
        // return dp[n];
        vector<int> dp(vector<int>(n + 1, INT_MAX));
        dp[0] = 0;
        dp[1] = 1;

        for (size_t i = 2; i <= n; i++) {
            for (size_t j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];

        // vector<int> squareNumbers;
        // vector<int> dp(n + 1, 0);
        // for (size_t i = 1; i * i <= n; i++) {
        //     squareNumbers.push_back(i * i);
        //     dp[i * i] = 1;
        // }
        // if (n == squareNumbers.back())
        //     return 1;

        // int cnt = 1, nums, item;
        // queue<int> q;
        // for (auto k : squareNumbers) {
        //     q.push(k);
        // }
        // while (!q.empty()) {
        //     cnt++;
        //     nums = q.size();
        //     while (nums--) {
        //         item = q.front();
        //         q.pop();
        //         for (auto k : squareNumbers) {
        //             if (item + k == n) {
        //                 return cnt;
        //             } else if (item + k < n && dp[item + k] == 0) {
        //                 dp[item + k] = dp[item] + 1;
        //                 q.push(item + k);
        //             } else if (item + k > n) {
        //                 break;
        //             }
        //         }
        //     }
        // }
        // return -1;
    }
};
// @lc code=end
