/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 *
 * https://leetcode.com/problems/base-7/description/
 *
 * algorithms
 * Easy (45.18%)
 * Likes:    188
 * Dislikes: 137
 * Total Accepted:    49.2K
 * Total Submissions: 107.9K
 * Testcase Example:  '100'
 *
 * Given an integer, return its base 7 string representation.
 * 
 * Example 1:
 * 
 * Input: 100
 * Output: "202"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: -7
 * Output: "-10"
 * 
 * 
 * 
 * Note:
 * The input will be in range of [-1e7, 1e7].
 * 
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    string convertToBase7(int num)
    {
        if (num == 0) {
            return "0";
        }
        string ans = "";
        int item;
        if (num < 0) {
            item = -num;
        } else {
            item = num;
        }

        while (item) {
            ans = to_string(item % 7) + ans;
            item = item / 7;
        }
        return num >= 0 ? ans : ("-" + ans);
    }
};
// @lc code=end
