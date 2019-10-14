/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (38.10%)
 * Likes:    913
 * Dislikes: 262
 * Total Accepted:    233.6K
 * Total Submissions: 609.1K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "egg", t = "add"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "foo", t = "bar"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: s = "paper", t = "title"
 * Output: true
 * 
 * Note:
 * You may assume both s and t have the same length.
 * 
 */

// @lc code=start

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        // unordered_map<char, char> table;
        // unordered_map<char, char> table_1;
        // for (size_t i = 0; i < s.size(); i++) {
        //     if (table.find(s[i]) == table.end() && table_1.find(t[i]) == table_1.end()) {
        //         table[s[i]] = t[i];
        //         table_1[t[i]] = s[i];
        //     } else if (table[s[i]] != t[i] || table_1[t[i]] != s[i]) {
        //         return false;
        //     }
        // }
        // return true;

        char table_1[128] = { 0 };
        char table_2[128] = { 0 };
        for (size_t i = 0; i < s.size(); i++) {
            if (table_1[s[i]] != table_2[t[i]]) {
                return false;
            }
            table_1[s[i]] = i + 1;
            table_2[t[i]] = i + 1;
        }
        return true;
    }
};
// @lc code=end
