/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (22.83%)
 * Likes:    1756
 * Dislikes: 1992
 * Total Accepted:    303.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 * 
 * Example 1:
 * 
 * 
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 * 
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s)
    {
        //
        // if (s.size() == 0 || s[0] == '0') {
        //     return 0;
        // }
        // if (s.size() == 1) {
        //     return 1;
        // }
        // if (s.size() == 2 && (s[0] - '0') * 10 + (s[1] - '0') <= 26) {
        //     if (s[1] == '0') {
        //         return 1;
        //     } else {
        //         return 2;
        //     }
        // }
        // if ((s[0] - '0') * 10 + (s[1] - '0') > 26) {
        //     return numDecodings(s.substr(1, s.size() - 1));
        // }
        // return numDecodings(s.substr(1, s.size() - 1)) + numDecodings(s.substr(2, s.size() - 2));

        // 动态规划1
        // if (s.empty() || s[0] == '0') {
        //     return 0;
        // }
        // int dp[s.size() + 1] = { 0 };
        // dp[0] = 1;
        // dp[1] = 1;
        // for (size_t i = 1; i < s.size(); i++) {
        //     dp[i + 1] = (s[i] == '0') ? 0 : dp[i];
        //     if (i > 0 && (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6')) {
        //         dp[i + 1] += dp[i - 1];
        //     }
        // }
        // return dp[s.size()];

        // 动态规划2
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        vector<int> dp(vector<int>(s.size() + 1, 0));
        dp[0] = 1;
        dp[1] = 1;

        for (size_t i = 2; i <= s.size(); i++) {
            int num = stoi(s.substr(i - 2, 2));
            int num_single = num % 10;
            if (num_single != 0) {
                dp[i] += dp[i - 1];
            }
            if (num >= 10 && num <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[s.size()];
    }
};

// @lc code=end
