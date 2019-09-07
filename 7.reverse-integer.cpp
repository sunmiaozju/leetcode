/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.46%)
 * Likes:    2388
 * Dislikes: 3655
 * Total Accepted:    778.5K
 * Total Submissions: 3.1M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 * 
 */
#include <climits>
#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

class Solution {

public:
    // Solution(){};
    // ~Solution(){};

    int reverse(int x)
    {
        // queue<int> num;
        // num.push(x % 10);
        // while (x = x / 10) {
        //     num.push(x % 10);
        // }
        // double ans = num.front();
        // num.pop();
        // while (!num.empty()) {
        //     ans = ans * 10 + num.front();
        //     num.pop();
        // }
        // if (ans > pow(2, 31) - 1 || ans < -pow(2, 31)) {
        //     return 0;
        // }
        // return ans;

        long ans = 0;
        while (x) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans > INT_MAX || ans < -INT_MAX ? 0 : ans;
    }
};

// int main(int argc, const char** argv)
// {
//     Solution app;
//     app.reverse(-2147438648);
//     return 0;
// }
