/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (57.82%)
 * Likes:    1961
 * Dislikes: 96
 * Total Accepted:    146.7K
 * Total Submissions: 248.2K
 * Testcase Example:  '"abc"'
 *
 * Given a string, your task is to count how many palindromic substrings in
 * this string.
 * 
 * The substrings with different start indexes or end indexes are counted as
 * different substrings even they consist of same characters.
 * 
 * Example 1:
 * 
 * 
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The input string length won't exceed 1000.
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s)
    {
        int ans = 0;
        for (double i = 0; i < s.size(); i += 0.5) {
            int left, right;
            if (i == int(i)) {
                left = right = i;
            } else {
                left = int(i);
                right = int(i) + 1;
            }
            while (left >= 0 && right < s.size()) {
                if (s[left] == s[right]) {
                    ans++;
                } else {
                    break;
                }
                left--;
                right++;
            }
        }
        return ans;
    }
};
// @lc code=end
