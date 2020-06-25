/*
 * @lc app=leetcode.cn id=664 lang=cpp
 *
 * [664] 奇怪的打印机
 *
 * https://leetcode-cn.com/problems/strange-printer/description/
 *
 * algorithms
 * Hard (41.85%)
 * Likes:    45
 * Dislikes: 0
 * Total Accepted:    1.6K
 * Total Submissions: 3.7K
 * Testcase Example:  '"aaabbb"'
 *
 * 有台奇怪的打印机有以下两个特殊要求：
 * 
 * 
 * 打印机每次只能打印同一个字符序列。
 * 每次可以在任意起始和结束位置打印新字符，并且会覆盖掉原来已有的字符。
 * 
 * 
 * 给定一个只包含小写英文字母的字符串，你的任务是计算这个打印机打印它需要的最少次数。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "aaabbb"
 * 输出: 2
 * 解释: 首先打印 "aaa" 然后打印 "bbb"。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "aba"
 * 输出: 2
 * 解释: 首先打印 "aaa" 然后在第二个位置打印 "b" 覆盖掉原来的字符 'a'。
 * 
 * 提示: 输入字符串的长度不会超过 100。
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int strangePrinter(string s)
    {
        if (s.size() == 0) {
            return 0;
        }
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = 1;
        }

        for (int i = s.size() - 2; i >= 0; i--) {
            for (int j = i + 1; j < s.size(); j++) {
                // 如果s[i]字符和[i+1, j]里面的每一个字符都不一样，那么就相当于1次新的印刷
                dp[i][j] = dp[i + 1][j] + 1;

                // 这里的递推公式可以这么理解：
                // 当[i, j]根据字符s[i] == s[k] 分为了两部分，然后两个子区间的结果加和。
                // 为什么加和呢，是因为对于左边的区间，可以先不印刷，然后将s[i]和s[k]脸片印刷，也就是看作一个点
                // 这样的话，就和印刷子区间dp[k, j]一样了，
                // 然后再覆盖印刷区间[i+1, k-1],所以是这两个子区间的加和。
                for (int k = i + 1; k <= j; k++) {
                    if (s[i] == s[k]) {
                        dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
                    }
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};
// @lc code=end
