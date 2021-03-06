/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第N个数字
 *
 * https://leetcode-cn.com/problems/nth-digit/description/
 *
 * algorithms
 * Medium (34.85%)
 * Likes:    91
 * Dislikes: 0
 * Total Accepted:    6.5K
 * Total Submissions: 18.8K
 * Testcase Example:  '3'
 *
 * 在无限的整数序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...中找到第 n 个数字。
 * 
 * 注意:
 * n 是正数且在32为整形范围内 ( n < 2^31)。
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * 3
 * 
 * 输出:
 * 3
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:
 * 11
 * 
 * 输出:
 * 0
 * 
 * 说明:
 * 第11个数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是0，它是10的一部分。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findNthDigit(int n)
    {
        long len = 1, size = 9, num = 9;
        while (n > num) {
            len++;
            size = size * 10;
            num = num + size * len;
        }
        num = num - size * len + 1;

        int index = (n - num) / len;

        int start = pow(10, len - 1);
        while (index--) {
            start++;
        }
        index = (n - num) % len;

        int item = pow(10, len - 1);
        while (index--) {
            start = start % item;
            item /= 10;
        }
        return start / item;
    }
};
// @lc code=end
