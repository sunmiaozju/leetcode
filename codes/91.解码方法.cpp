/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 *
 * https://leetcode-cn.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (23.04%)
 * Likes:    321
 * Dislikes: 0
 * Total Accepted:    39.6K
 * Total Submissions: 170.2K
 * Testcase Example:  '"12"'
 *
 * 一条包含字母 A-Z 的消息通过以下方式进行了编码：
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 给定一个只包含数字的非空字符串，请计算解码方法的总数。
 * 
 * 示例 1:
 * 
 * 输入: "12"
 * 输出: 2
 * 解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "226"
 * 输出: 3
 * 解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
 * 
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int numDecodings(string s)
    {
        if (s.empty() || s[0] == '0') {
            return 0;
        }

        vector<int> dp(s.size(), 0);

        dp[0] = 1;
        if (s.size() >= 2) {
            if (s[1] >= '1' && s[1] <= '9') {
                dp[1] = 1;
            }
            int num = (s[0] - '0') * 10 + s[1] - '0';
            if (num >= 10 && num <= 26) {
                dp[1]++;
            }
        }

        for (int i = 2; i < s.size(); i++) {
            if (s[i] >= '1' && s[i] <= '9') {
                dp[i] = dp[i - 1];
            }
            int num = (s[i - 1] - '0') * 10 + s[i] - '0';
            if (num >= 10 && num <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }
};
// @lc code=end
