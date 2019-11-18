/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (44.56%)
 * Likes:    1588
 * Dislikes: 1359
 * Total Accepted:    654.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve it without converting the integer to a string?
 * 
 */
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x)
    {
        // string s = to_string(x);
        // size_t i = 0, j = s.length() - 1;
        // for (; i < j; i++, j--) {
        //     if (s[i] != s[j]) {
        //         break;
        //     }
        // }
        // return i < j ? false : true;

        // int tmp = x;
        // if (x < 0)
        //     return false;

        // long result = 0;
        // while (x) {
        //     result = result * 10 + x % 10;
        //     x /= 10;
        // }
        // return result == tmp ? true : false;

        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }

        int ans = 0;
        while (x > ans) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }

        return (x == ans) || (x == ans / 10);
    }
};
