/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (32.74%)
 * Likes:    1007
 * Dislikes: 1452
 * Total Accepted:    478.8K
 * Total Submissions: 1.5M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle)
    {
        int hay = 0, need = 0;
        bool status = false;
        while (hay < haystack.size() && need < needle.size()) {
            if (haystack[hay] != needle[need]) {
                hay = status ? hay - need + 1 : hay + 1;
                need = 0;
                status = false;
            } else {
                status = true;
                hay++;
                need++;
            }
        }
        return need == needle.size() ? hay - needle.size() : -1;
    }
};
