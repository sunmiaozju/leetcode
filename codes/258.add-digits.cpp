/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 *
 * https://leetcode.com/problems/add-digits/description/
 *
 * algorithms
 * Easy (54.71%)
 * Likes:    526
 * Dislikes: 860
 * Total Accepted:    255K
 * Total Submissions: 464.3K
 * Testcase Example:  '38'
 *
 * Given a non-negative integer num, repeatedly add all its digits until the
 * result has only one digit.
 * 
 * Example:
 * 
 * 
 * Input: 38
 * Output: 2 
 * Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2. 
 * Since 2 has only one digit, return it.
 * 
 * 
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int addDigits(int num)
    {
        // if (num / 10 == 0) {
        //     return num;
        // }
        // int ans = 0;
        // while (num) {
        //     ans += num % 10;
        //     num /= 10;
        // }
        // return addDigits(ans);
        if (num % 9 == 0 && num != 0) {
            return 9;
        }
        return num % 9;
    }
};
// @lc code=end
