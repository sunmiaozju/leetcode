/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (28.44%)
 * Likes:    1956
 * Dislikes: 0
 * Total Accepted:    224.4K
 * Total Submissions: 768.2K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0){
            return "";
        }

        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

        int start = 0, length = 1;
        for(int i=s.size()-1;i>=0;i--){
            dp[i][i] = 1;
            for(int j=i+1;j<s.size();j++){
                if(s[i] == s[j]){
                    if(i + 1 == j || dp[i+1][j-1]){
                        dp[i][j] = j-i+1;
                        if(length < dp[i][j]){
                            start = i;
                            length = dp[i][j];
                        }
                    }
                }
            }
        }
        return s.substr(start, length);
    }
};
// @lc code=end

