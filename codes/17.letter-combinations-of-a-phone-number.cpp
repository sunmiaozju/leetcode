/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (42.89%)
 * Likes:    2739
 * Dislikes: 345
 * Total Accepted:    468.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty()) {
            return vector<string>();
        }
        vector<string> ans;
        vector<string> table{ "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        help(ans, digits, "", 0, table);
        return ans;
    }
    void help(vector<string>& ans, string& digits, string str, int level, vector<string>& table)
    {
        if (level == digits.length()) {
            ans.push_back(str);
            return;
        }
        string s = table[digits[level] - '0'];
        for (size_t i = 0; i < s.size(); i++) {
            help(ans, digits, str + s[i], level + 1, table);
        }
    }
};
// @lc code=end
