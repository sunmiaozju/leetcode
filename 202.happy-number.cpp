/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (46.45%)
 * Likes:    1065
 * Dislikes: 276
 * Total Accepted:    273.7K
 * Total Submissions: 584.2K
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 * 
 * Example: 
 * 
 * 
 * Input: 19
 * Output: true
 * Explanation: 
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 */

// @lc code=start

#include <algorithm>
#include <cmath>>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;
double time11 = 0;

class Solution {
public:
    int trans(int n)
    {
        int num = 0;
        while (n) {
            num += pow(n % 10, 2);
            n /= 10;
        }
        return num;
    }
    bool isHappy(int n)
    {
        // int table[1000];
        // memset(table, 0, sizeof(table));
        // n = trans(n);
        // while (!table[n]) {
        //     if (n == 1) {
        //         return true;
        //     }
        //     table[n] = true;
        //     n = trans(n);
        // }
        // return false;

        int slow = n, fast = n;
        while (slow != 1 && fast != 1) {
            slow = trans(slow);
            fast = trans(fast);
            fast = trans(fast);
            if (fast == slow && fast != 1) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
