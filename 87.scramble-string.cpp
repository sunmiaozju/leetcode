/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 *
 * https://leetcode.com/problems/scramble-string/description/
 *
 * algorithms
 * Hard (32.18%)
 * Likes:    359
 * Dislikes: 572
 * Total Accepted:    97.9K
 * Total Submissions: 301.9K
 * Testcase Example:  '"great"\n"rgeat"'
 *
 * Given a string s1, we may represent it as a binary tree by partitioning it
 * to two non-empty substrings recursively.
 * 
 * Below is one possible representation of s1 = "great":
 * 
 * 
 * ⁠   great
 * ⁠  /    \
 * ⁠ gr    eat
 * ⁠/ \    /  \
 * g   r  e   at
 * ⁠          / \
 * ⁠         a   t
 * 
 * 
 * To scramble the string, we may choose any non-leaf node and swap its two
 * children.
 * 
 * For example, if we choose the node "gr" and swap its two children, it
 * produces a scrambled string "rgeat".
 * 
 * 
 * ⁠   rgeat
 * ⁠  /    \
 * ⁠ rg    eat
 * ⁠/ \    /  \
 * r   g  e   at
 * ⁠          / \
 * ⁠         a   t
 * 
 * 
 * We say that "rgeat" is a scrambled string of "great".
 * 
 * Similarly, if we continue to swap the children of nodes "eat" and "at", it
 * produces a scrambled string "rgtae".
 * 
 * 
 * ⁠   rgtae
 * ⁠  /    \
 * ⁠ rg    tae
 * ⁠/ \    /  \
 * r   g  ta  e
 * ⁠      / \
 * ⁠     t   a
 * 
 * 
 * We say that "rgtae" is a scrambled string of "great".
 * 
 * Given two strings s1 and s2 of the same length, determine if s2 is a
 * scrambled string of s1.
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "great", s2 = "rgeat"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "abcde", s2 = "caebd"
 * Output: false
 * 
 */
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isScramble(string s1, string s2)
    {
        // 递归解法，注意如果子字符串的字母不一样，要提前处理加快速度
        // return help(s1, s2, 0, 0, s1.length());
        // dp解法
        int n = s1.length();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1, false)));
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                dp[i][j][1] = s1[i] == s2[j];
            }
        }
        for (size_t len = 2; len <= n; len++) {
            for (size_t i = 0; i <= n - len; i++) {
                for (size_t j = 0; j <= n - len; j++) {
                    for (size_t k = 0; k < len - 1; k++) {
                        if (dp[i][j][k + 1] && dp[i + k + 1][j + k + 1][len - k - 1] || dp[i][j + len - k - 1][k + 1] && dp[i + k + 1][j][len - k - 1]) {
                            dp[i][j][len] = true;
                        }
                    }
                }
            }
        }
        return dp[0][0][n];
    }
    // bool help(string& s1, string& s2, int l1, int l2, int length)
    // {
    //     if (length == 1) {
    //         return s1[l1] == s2[l2];
    //     }
    //     string str1 = s1.substr(l1, length);
    //     string str2 = s2.substr(l2, length);
    //     sort(str1.begin(), str1.end());
    //     sort(str2.begin(), str2.end());
    //     if (str1 != str2)
    //         return false;

    //     for (int i = 0; i < length - 1; i++) {
    //         bool result1 = help(s1, s2, l1, l2, i + 1) && help(s1, s2, l1 + i + 1, l2 + i + 1, length - i - 1);
    //         if (result1) {
    //             return true;
    //         }
    //         bool result2 = help(s1, s2, l1, l2 + length - i - 1, i + 1) && help(s1, s2, l1 + i + 1, l2, length - i - 1);
    //         if (result2) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }
};

// @lc code=end
