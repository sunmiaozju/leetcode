/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (36.46%)
 * Likes:    3286
 * Dislikes: 174
 * Total Accepted:    448.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 * 
 * 
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        vector<bool> dp(s.size() + 1, false);

        dp[0] = true;

        for (int i = 0; i <= s.size(); i++) {
            for (string str : wordDict) {
                int num = str.size();
                if (i >= num && str == s.substr(i - num, num)) {
                    dp[i] = dp[i] || dp[i - num];
                }
            }
        }

        return dp[s.size()];
    }
};
// @lc code=end
