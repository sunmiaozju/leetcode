/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 *
 * https://leetcode.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Easy (37.58%)
 * Likes:    549
 * Dislikes: 786
 * Total Accepted:    170.7K
 * Total Submissions: 453.8K
 * Testcase Example:  '3'
 *
 * Given an integer n, return the number of trailing zeroes in n!.
 * 
 * Example 1:
 * 
 * 
 * Input: 3
 * Output: 0
 * Explanation: 3! = 6, no trailing zero.
 * 
 * Example 2:
 * 
 * 
 * Input: 5
 * Output: 1
 * Explanation: 5! = 120, one trailing zero.
 * 
 * Note: Your solution should be in logarithmic time complexity.
 * 
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n)
    {
        // return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);

        int ans = 0;

        for (long i = 5; n / i; i *= 5) {
            ans = ans + n / i;
        }
        return ans;
    }
};
