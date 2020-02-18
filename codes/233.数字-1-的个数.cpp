/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 *
 * https://leetcode-cn.com/problems/number-of-digit-one/description/
 *
 * algorithms
 * Hard (32.34%)
 * Likes:    94
 * Dislikes: 0
 * Total Accepted:    4.9K
 * Total Submissions: 15.2K
 * Testcase Example:  '13'
 *
 * 给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。
 * 
 * 示例:
 * 
 * 输入: 13
 * 输出: 6 
 * 解释: 数字 1 出现在以下数字中: 1, 10, 11, 12, 13 。
 * 
 */

// @lc code=start
class Solution {
public:
    int countDigitOne(int n)
    {
        int origin = n;
        int ans = 0;
        long a = 0, b = 1;
        while (n) {
            int item = n % 10;
            if (item > 1) {
                ans += item * a + b;
            } else if (item == 1) {
                ans += item * a + origin % b + 1;
            }

            a = a * 10 + b;
            b = b * 10;

            n = n / 10;
        }
        return ans;
    }
};
// @lc code=end
