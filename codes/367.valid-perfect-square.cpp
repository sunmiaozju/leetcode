/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (40.36%)
 * Likes:    590
 * Dislikes: 133
 * Total Accepted:    140.7K
 * Total Submissions: 344.8K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 * 
 * Note: Do not use any built-in library function such as sqrt.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: 16
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 14
 * Output: false
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num)
    {
        if (num <= 1) {
            return true;
        }
        for (long i = 1; i <= num / 2; i++) {
            if (i * i > num) {
                break;
            }
            if (i * i == num) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
