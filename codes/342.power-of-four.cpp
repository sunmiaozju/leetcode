/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 *
 * https://leetcode.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (40.69%)
 * Likes:    402
 * Dislikes: 175
 * Total Accepted:    134.7K
 * Total Submissions: 327.6K
 * Testcase Example:  '16'
 *
 * Given an integer (signed 32 bits), write a function to check whether it is a
 * power of 4.
 * 
 * Example 1:
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
 * Input: 5
 * Output: false
 * 
 * 
 * Follow up: Could you solve it without loops/recursion?
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int num)
    {
        if (num <= 0) {
            return false;
        }
        if ((num & (num - 1)) != 0) {
            return false;
        }
        int cnt = 0, item = 0;
        while ((num & 1) == 0) {
            num = num >> 1;
            cnt++;
        }
        return cnt % 2 == 0;
    }
};
// @lc code=end
