/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 *
 * https://leetcode.com/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Easy (32.62%)
 * Likes:    389
 * Dislikes: 259
 * Total Accepted:    52.8K
 * Total Submissions: 162.3K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer c, your task is to decide whether there're two
 * integers a and b such that a^2 + b^2 = c.
 * 
 * Example 1:
 * 
 * 
 * Input: 5
 * Output: True
 * Explanation: 1 * 1 + 2 * 2 = 5
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 3
 * Output: False
 * 
 * 
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c)
    {
        int left = 0, right = int(sqrt(c));
        while (left <= right) {
            long num = right * right;
            num += left * left;
            if (num == c) {
                return true;
            } else if (num < c) {
                left++;
            } else {
                right--;
            }
        }
        return false;
    }
};
// @lc code=end
