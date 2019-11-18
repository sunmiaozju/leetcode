/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (27.86%)
 * Likes:    4624
 * Dislikes: 417
 * Total Accepted:    696.3K
 * Total Submissions: 2.5M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s)
    {
        // int start = 0, len = 0;
        // int left = 0, right = 0;
        // for (size_t i = 0; i < s.size();) {
        //     left = right = i;
        //     while (right < s.size() - 1 && s[right] == s[right + 1]) {
        //         right++;
        //     }
        //     i = right + 1;
        //     while (left >= 0 && right < s.size() && s[left] == s[right]) {
        //         left--;
        //         right++;
        //     }
        //     if (len < right - left - 1) {
        //         len = right - left - 1;
        //         start = left + 1;
        //     }
        // }
        // return s.substr(start, len);
        if (s.size() < 2) {
            return s;
        }
        int n = s.size(), len = 1, start = 0;
        int table[n][n] = { 0 };
        for (size_t i = 0; i < n; i++) {
            table[i][i] = 1;
            for (size_t j = 0; j < i; j++) {
                table[j][i] = (s[j] == s[i]) && (i == j + 1 || table[j + 1][i - 1]);
                if (table[j][i] && len < i - j + 1) {
                    len = i - j + 1;
                    start = j;
                }
            }
        }
        return s.substr(start, len);
    }
};
// @lc code=end
