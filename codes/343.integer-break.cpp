/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (48.46%)
 * Likes:    774
 * Dislikes: 199
 * Total Accepted:    94.4K
 * Total Submissions: 192.1K
 * Testcase Example:  '2'
 *
 * Given a positive integer n, break it into the sum of at least two positive
 * integers and maximize the product of those integers. Return the maximum
 * product you can get.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: 2
 * Output: 1
 * Explanation: 2 = 1 + 1, 1 × 1 = 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 10
 * Output: 36
 * Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 * 
 * Note: You may assume that n is not less than 2 and not larger than 58.
 * 
 * 
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int integerBreak(int n)
    {
        // if (n == 2) {
        //     return 1;
        // } else if (n == 3) {
        //     return 2;
        // } else if (n == 4) {
        //     return 4;
        // }

        // int sum = 1;
        // while (n >= 5) {
        //     sum *= 3;
        //     n -= 3;
        // }
        // sum *= n;
        // return sum;

        vector<int> dp(vector<int>(n + 1, 1));
        for (size_t i = 3; i <= n; i++) {
            for (size_t j = 1; j < i; j++) {
                dp[i] = max(dp[i], int(max(j * (i - j), j * dp[i - j])));
            }
        }
        return dp[n];
    }
};
// @lc code=end
