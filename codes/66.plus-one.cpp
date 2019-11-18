/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (41.60%)
 * Likes:    968
 * Dislikes: 1713
 * Total Accepted:    436.1K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        // int cur = digits.size() - 1;

        // if (digits.size() == 1) {
        //     digits[0]++;
        // } else {
        //     digits[cur]++;
        // }

        // while (cur > 0) {
        //     if (digits[cur] == 10) {
        //         digits[cur] = 0;
        //         digits[cur - 1]++;
        //     } else {
        //         return digits;
        //     }
        //     cur--;
        // }
        // if (digits[0] == 10) {
        //     digits[0] = 0;
        //     digits.insert(digits.begin(), 1);
        // }

        // return digits;

        int cur = digits.size() - 1;

        while (cur >= 0) {
            digits[cur]++;
            if (digits[cur] == 10) {
                digits[cur] = 0;
            } else {
                return digits;
            }
            cur--;
        }
        if (digits[0] == 0) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
