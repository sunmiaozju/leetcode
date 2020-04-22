/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 *
 * https://leetcode-cn.com/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (50.03%)
 * Likes:    180
 * Dislikes: 0
 * Total Accepted:    17K
 * Total Submissions: 32K
 * Testcase Example:  '"bbbab"'
 *
 * 给定一个字符串s，找到其中最长的回文子序列。可以假设s的最大长度为1000。
 * 
 * 示例 1:
 * 输入:
 * 
 * 
 * "bbbab"
 * 
 * 
 * 输出:
 * 
 * 
 * 4
 * 
 * 
 * 一个可能的最长回文子序列为 "bbbb"。
 * 
 * 示例 2:
 * 输入:
 * 
 * 
 * "cbbd"
 * 
 * 
 * 输出:
 * 
 * 
 * 2
 * 
 * 
 * 一个可能的最长回文子序列为 "bb"。
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 1));

        for (int i = 0; i < s.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (s[i] == s[j]) {
                    if (j + 1 == i) {
                        dp[j][i] = 2;
                    } else {
                        dp[j][i] = dp[j + 1][i - 1] + 2;
                    }
                } else {
                    dp[j][i] = max(dp[j][i - 1], dp[j + 1][i]);
                }
                // cout << j << " " << i << " " << dp[j][i] << endl;
            }
        }

        return dp[0][s.size() - 1];
    }
};
// @lc code=end
