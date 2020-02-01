/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (44.45%)
 * Likes:    628
 * Dislikes: 205
 * Total Accepted:    136.9K
 * Total Submissions: 299.2K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2)
    {
        if (num1.size() < num2.size()) {
            swap(num1, num2);
        }
        int index1 = num1.size() - 1, index2 = num2.size() - 1;
        int up = 0;
        while (index2 >= 0) {
            int item = num1[index1] - '0' + num2[index2] - '0' + up;
            if (item >= 10) {
                num1[index1] = item % 10 + '0';
                up = item / 10;
            } else {
                num1[index1] = item + '0';
                up = 0;
            }
            index1--;
            index2--;
        }

        if (up) {
            while (index1 >= 0) {
                int item = num1[index1] - '0' + up;
                if (item >= 10) {
                    num1[index1] = item % 10 + '0';
                    up = item / 10;
                } else {
                    num1[index1] = item + '0';
                    up = 0;
                }
                index1--;
            }
        }

        return up ? to_string(up) + num1 : num1;
    }
};
// @lc code=end
