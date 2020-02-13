/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (50.80%)
 * Likes:    996
 * Dislikes: 1861
 * Total Accepted:    165K
 * Total Submissions: 325.6K
 * Testcase Example:  '1\n2'
 *
 * Calculate the sum of two integers a and b, but you are not allowed to use
 * the operator + and -.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: a = 1, b = 2
 * Output: 3
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: a = -2, b = 3
 * Output: 1
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b)
    {
        if (b == 0) {
            return a;
        }
        int sum = a ^ b;
        int up = (a & b & 0x7fffffff) << 1;
        return getSum(sum, up);
    }
};
// @lc code=end
