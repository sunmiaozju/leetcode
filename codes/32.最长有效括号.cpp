/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (29.57%)
 * Likes:    583
 * Dislikes: 0
 * Total Accepted:    49.9K
 * Total Submissions: 166.1K
 * Testcase Example:  '"(()"'
 *
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 * 
 * 示例 1:
 * 
 * 输入: "(()"
 * 输出: 2
 * 解释: 最长有效括号子串为 "()"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ")()())"
 * 输出: 4
 * 解释: 最长有效括号子串为 "()()"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        vector<int> dp(s.size(), 0);
        int ans = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push(i);
                dp[i] = 0;
            }else{
                if(st.empty()){
                    dp[i] = 0;
                    continue;
                }
                int index = st.top();
                st.pop();
                if(index == i - 1){
                    dp[i] = 2 + (index >= 1 ? dp[index - 1] : 0);
                    ans = max(ans, dp[i]);
                    continue;
                }
                int length = i - index - 1;
                if(dp[i-1] == length){
                    dp[i] = 2 + dp[i-1] + (index >= 1 ? dp[index - 1] : 0);
                    ans = max(ans, dp[i]);
                }else{
                    dp[i] = 0;
                }
            }
        }
        return ans;
        
    }
};
// @lc code=end

