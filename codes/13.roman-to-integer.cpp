/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (53.10%)
 * Likes:    1405
 * Dislikes: 2817
 * Total Accepted:    472.2K
 * Total Submissions: 889.2K
 * Testcase Example:  '"III"'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 * 
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * For example, two is written as II in Roman numeral, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 * 
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * 
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be
 * within the range from 1 to 3999.
 * 
 * Example 1:
 * 
 * 
 * Input: "III"
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: "IV"
 * Output: 4
 * 
 * Example 3:
 * 
 * 
 * Input: "IX"
 * Output: 9
 * 
 * Example 4:
 * 
 * 
 * Input: "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s)
    {
        int ans = 0;
        char prev = NULL;
        for (size_t i = 0; i < s.length(); i++) {
            switch (s[i]) {
            case 'M':
                ans += 1000;
                if (prev == 'C') {
                    ans -= 200;
                }
                break;
            case 'D':
                ans += 500;
                if (prev == 'C') {
                    ans -= 200;
                }
                break;
            case 'C':
                ans += 100;
                if (prev == 'X') {
                    ans -= 20;
                }
                prev = 'C';
                break;
            case 'L':
                ans += 50;
                if (prev == 'X') {
                    ans -= 20;
                }
                break;
            case 'X':
                ans += 10;
                if (prev == 'I') {
                    ans -= 2;
                }
                prev = 'X';
                break;
            case 'V':
                ans += 5;
                if (prev == 'I') {
                    ans -= 2;
                }
                break;
            case 'I':
                ans += 1;
                prev = 'I';
                break;
            }
        }
        return ans;
    }
};
