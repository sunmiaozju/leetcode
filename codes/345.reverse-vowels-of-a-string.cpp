/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (42.12%)
 * Likes:    466
 * Dislikes: 856
 * Total Accepted:    179.4K
 * Total Submissions: 423.1K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 * 
 * Example 1:
 * 
 * 
 * Input: "hello"
 * Output: "holle"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "leetcode"
 * Output: "leotcede"
 * 
 * 
 * Note:
 * The vowels does not include the letter "y".
 * 
 * 
 * 
 */
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    string reverseVowels(string s)
    {
        // if (s.size() < 2) {
        //     return s;
        // }
        // int left = 0, right = s.size() - 1;
        // string item = "aeiouAEIOU";
        // unordered_set<char> table;
        // for (size_t i = 0; i < item.length(); i++) {
        //     table.insert(item[i]);
        // }

        // while (true) {
        //     while (left < right && table.find(s[left]) == table.end()) {
        //         left++;
        //     }
        //     while (left < right && table.find(s[right]) == table.end()) {
        //         right--;
        //     }
        //     if (left < right) {
        //         swap(s[left++], s[right--]);
        //     } else {
        //         break;
        //     }
        // }
        // return s;

        int left = 0, right = s.size() - 1;
        while (left < right) {
            left = s.find_first_of("aeiouAEIOU", left);
            right = s.find_last_of("aeiouAEIOU", right);
            if (left < right) {
                swap(s[left++], s[right--]);
            }
        }
        return s;
    }
};
// @lc code=end
