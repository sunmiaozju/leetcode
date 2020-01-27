/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 *
 * https://leetcode.com/problems/longest-common-subsequence/description/
 *
 * algorithms
 * Medium (57.48%)
 * Likes:    503
 * Dislikes: 11
 * Total Accepted:    31.5K
 * Total Submissions: 54.8K
 * Testcase Example:  '"abcde"\n"ace"'
 *
 * Given two strings text1 and text2, return the length of their longest common
 * subsequence.
 * 
 * A subsequence of a string is a new string generated from the original string
 * with some characters(can be none) deleted without changing the relative
 * order of the remaining characters. (eg, "ace" is a subsequence of "abcde"
 * while "aec" is not). A common subsequence of two strings is a subsequence
 * that is common to both strings.
 * 
 * 
 * 
 * If there is no common subsequence, return 0.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: text1 = "abcde", text2 = "ace" 
 * Output: 3  
 * Explanation: The longest common subsequence is "ace" and its length is 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: text1 = "abc", text2 = "abc"
 * Output: 3
 * Explanation: The longest common subsequence is "abc" and its length is 3.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: text1 = "abc", text2 = "def"
 * Output: 0
 * Explanation: There is no such common subsequence, so the result is 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= text1.length <= 1000
 * 1 <= text2.length <= 1000
 * The input strings consist of lowercase English characters only.
 * 
 * 
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> dp(vector<vector<int>>(text1.size() + 1, vector<int>(text2.size() + 1, 0)));

        for (size_t index1 = 1; index1 <= text1.size(); index1++)
            for (size_t index2 = 1; index2 <= text2.size(); index2++) {
                if (text1[index1 - 1] == text2[index2 - 1]) {
                    dp[index1][index2] = dp[index1 - 1][index2 - 1] + 1;
                } else {
                    dp[index1][index2] = max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
                }
            }

        return dp[text1.size()][text2.size()];
    }
};
// @lc code=end
