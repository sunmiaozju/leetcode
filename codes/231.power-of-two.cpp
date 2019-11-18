/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 *
 * https://leetcode.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (42.33%)
 * Likes:    525
 * Dislikes: 140
 * Total Accepted:    251.5K
 * Total Submissions: 592.8K
 * Testcase Example:  '1'
 *
 * Given an integer, write a function to determine if it is a power of two.
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: true 
 * Explanation: 2^0 = 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 16
 * Output: true
 * Explanation: 2^4 = 16
 * 
 * Example 3:
 * 
 * 
 * Input: 218
 * Output: false
 * 
 */

// @lc code=start

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n)
    {
        // double ans = n;
        // while (ans >= 1.0) {
        //     if (ans == 1.0) {
        //         return true;
        //     }
        //     ans = ans / 2.0;
        // }
        // return false;

        return n > 0 && !(n & n - 1);
    }
};
// @lc code=end
