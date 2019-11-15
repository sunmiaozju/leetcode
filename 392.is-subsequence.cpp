/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 *
 * https://leetcode.com/problems/is-subsequence/description/
 *
 * algorithms
 * Easy (47.45%)
 * Likes:    746
 * Dislikes: 152
 * Total Accepted:    116.5K
 * Total Submissions: 244.6K
 * Testcase Example:  '"abc"\n"ahbgdc"'
 *
 * 
 * Given a string s and a string t, check if s is subsequence of t.
 * 
 * 
 * 
 * You may assume that there is only lower case English letters in both s and
 * t. t is potentially a very long (length ~= 500,000) string, and s is a short
 * string (
 * 
 * 
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (ie, "ace" is a
 * subsequence of "abcde" while "aec" is not).
 * 
 * 
 * Example 1:
 * s = "abc", t = "ahbgdc"
 * 
 * 
 * Return true.
 * 
 * 
 * Example 2:
 * s = "axc", t = "ahbgdc"
 * 
 * 
 * Return false.
 * 
 * 
 * Follow up:
 * If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you
 * want to check one by one to see if T has its subsequence. In this scenario,
 * how would you change your code?
 * 
 * Credits:Special thanks to @pbrother for adding this problem and creating all
 * test cases.
 */
#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        if (s.empty()) {
            return true;
        }
        int index = 0;
        for (size_t i = 0; i < t.size(); i++) {
            if (s[index] == t[i]) {
                index++;
                if (index == s.size()) {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
