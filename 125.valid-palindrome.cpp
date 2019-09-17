/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (32.25%)
 * Likes:    688
 * Dislikes: 2029
 * Total Accepted:    406.3K
 * Total Submissions: 1.3M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note:Â For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s)
    {
        if (s.empty()) {
            return true;
        }
        int left = 0, right = s.size() - 1;
        // while (left < right) {
        //     while (!((s[left] <= 'z' && s[left] >= 'a')
        //         || (s[left] <= 'Z' && s[left] >= 'A')
        //         || (s[left] <= '9' && s[left] >= '0'))) {
        //         left++;
        //         if (left > s.size() - 1) {
        //             return true;
        //         }
        //     }
        //     while (!((s[right] <= 'z' && s[right] >= 'a')
        //         || (s[right] <= 'Z' && s[right] >= 'A')
        //         || (s[right] <= '9' && s[right] >= '0'))) {
        //         right--;
        //     }
        //     if (tolower(s[left++]) != tolower(s[right--])) {
        //         std::cout << s[--left] << s[++right] << std::endl;
        //         return false;
        //     }
        // }
        // return true;

        while (left < right) {
            while (!(isalnum(s[left]))) {
                left++;
                if (left > s.size() - 1) {
                    return true;
                }
            }
            while (!(isalnum(s[right]))) {
                right--;
            }
            if (tolower(s[left++]) != tolower(s[right--])) {
                std::cout << s[--left] << s[++right] << std::endl;
                return false;
            }
        }
        return true;
    }
};
