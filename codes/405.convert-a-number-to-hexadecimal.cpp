/*
 * @lc app=leetcode id=405 lang=cpp
 *
 * [405] Convert a Number to Hexadecimal
 *
 * https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/
 *
 * algorithms
 * Easy (42.43%)
 * Likes:    356
 * Dislikes: 92
 * Total Accepted:    57.7K
 * Total Submissions: 134K
 * Testcase Example:  '26'
 *
 * 
 * Given an integer, write an algorithm to convert it to hexadecimal. For
 * negative integer, two’s complement method is used.
 * 
 * 
 * Note:
 * 
 * All letters in hexadecimal (a-f) must be in lowercase.
 * The hexadecimal string must not contain extra leading 0s. If the number is
 * zero, it is represented by a single zero character '0'; otherwise, the first
 * character in the hexadecimal string will not be the zero character.
 * The given number is guaranteed to fit within the range of a 32-bit signed
 * integer.
 * You must not use any method provided by the library which converts/formats
 * the number to hex directly.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 26
 * 
 * Output:
 * "1a"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * -1
 * 
 * Output:
 * "ffffffff"
 * 
 * 
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    string toHex(int num)
    {

        string ans;

        vector<string> map = { "a", "b", "c", "d", "e", "f" };

        for (int i = 0; num && i < 8; i++) {
            int item = num & 0x0f;
            if (item >= 10) {
                ans = map[item - 10] + ans;
            } else {
                ans = to_string(item) + ans;
            }
            num = num >> 4;
        }
        return ans.empty() ? "0" : ans;
    }
};
// @lc code=end
