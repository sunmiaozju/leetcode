/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (48.62%)
 * Likes:    755
 * Dislikes: 73
 * Total Accepted:    123.5K
 * Total Submissions: 250K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string which consists of lowercase or uppercase letters, find the
 * length of the longest palindromes that can be built with those letters.
 * 
 * This is case sensitive, for example "Aa" is not considered a palindrome
 * here.
 * 
 * Note:
 * Assume the length of given string will not exceed 1,010.
 * 
 * 
 * Example: 
 * 
 * Input:
 * "abccccdd"
 * 
 * Output:
 * 7
 * 
 * Explanation:
 * One longest palindrome that can be built is "dccaccd", whose length is 7.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> map;
        for (char a : s) {
            map[a]++;
        }
        int ans = 0;
        int oddmax = 0;
        bool hasOdd = false;
        auto i = map.begin();
        while (i != map.end()) {
            ans += i->second;
            if (i->second % 2 == 1) {
                ans -= 1;
                hasOdd = true;
            }
            i++;
        }
        return ans + hasOdd;
    }
};
// @lc code=end
