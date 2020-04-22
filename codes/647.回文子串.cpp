/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 *
 * https://leetcode-cn.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (60.56%)
 * Likes:    217
 * Dislikes: 0
 * Total Accepted:    22.6K
 * Total Submissions: 36.9K
 * Testcase Example:  '"abc"'
 *
 * 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
 * 
 * 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "abc"
 * 输出: 3
 * 解释: 三个回文子串: "a", "b", "c".
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "aaa"
 * 输出: 6
 * 说明: 6个回文子串: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 注意:
 * 
 * 
 * 输入的字符串长度不会超过1000。
 * 
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int countSubstrings(string s)
    {
        int ans = 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = true;
            ans++;
            for (int j = 0; j < i; j++) {
                if (s[j] == s[i] && j + 1 == i) {
                    dp[j][i] = true;
                    ans++;
                } else if (s[j] == s[i] && dp[j + 1][i - 1]) {
                    dp[j][i] = true;
                    ans++;
                } else {
                    dp[j][i] = false;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
