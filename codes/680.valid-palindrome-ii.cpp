/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 *
 * https://leetcode.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (34.84%)
 * Likes:    980
 * Dislikes: 68
 * Total Accepted:    102.5K
 * Total Submissions: 290.8K
 * Testcase Example:  '"aba"'
 *
 * 
 * Given a non-empty string s, you may delete at most one character.  Judge
 * whether you can make it a palindrome.
 * 
 * 
 * Example 1:
 * 
 * Input: "aba"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "abca"
 * Output: True
 * Explanation: You could delete the character 'c'.
 * 
 * 
 * 
 * Note:
 * 
 * The string will only contain lowercase characters a-z.
 * The maximum length of the string is 50000.
 * 
 * 
 */
#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool validPalindrome(string s)
    {
        int left = 0, right = s.length() - 1;
        bool r1 = false, r2 = false;
        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                if (s[left] == s[right - 1]) {
                    r1 = help(s.substr(left, right - left));
                    if (r1) {
                        return true;
                    }
                }
                if (s[left + 1] == s[right]) {
                    r2 = help(s.substr(left + 1, right - left));
                    if (r2) {
                        return true;
                    }
                }
                return false;
            }
        }
        return true;
    }
    bool help(string s)
    {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
