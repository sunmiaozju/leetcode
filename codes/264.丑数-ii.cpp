/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 *
 * https://leetcode-cn.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (49.41%)
 * Likes:    216
 * Dislikes: 0
 * Total Accepted:    16.7K
 * Total Submissions: 33.7K
 * Testcase Example:  '10'
 *
 * 编写一个程序，找出第 n 个丑数。
 * 
 * 丑数就是只包含质因数 2, 3, 5 的正整数。
 * 
 * 示例:
 * 
 * 输入: n = 10
 * 输出: 12
 * 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
 * 
 * 说明:  
 * 
 * 
 * 1 是丑数。
 * n 不超过1690。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n)
    {
        int size = n;
        vector<int> dp;
        dp.push_back(1);
        int s2 = 0, s3 = 0, s5 = 0;
        while (--n) {
            int n2 = dp[s2] * 2, n3 = dp[s3] * 3, n5 = dp[s5] * 5;
            int num = min(n2, min(n3, n5));
            if (num == n2) {
                s2++;
            }
            if (num == n3) {
                s3++;
            }
            if (num == n5) {
                s5++;
            }
            dp.push_back(num);
        }
        return dp[size - 1];
    }
};
// @lc code=end
