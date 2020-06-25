/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 *
 * https://leetcode-cn.com/problems/ones-and-zeroes/description/
 *
 * algorithms
 * Medium (49.63%)
 * Likes:    146
 * Dislikes: 0
 * Total Accepted:    8K
 * Total Submissions: 15.3K
 * Testcase Example:  '["10","0001","111001","1","0"]\n5\n3'
 *
 * 在计算机界中，我们总是追求用有限的资源获取最大的收益。
 * 
 * 现在，假设你分别支配着 m 个 0 和 n 个 1。另外，还有一个仅包含 0 和 1 字符串的数组。
 * 
 * 你的任务是使用给定的 m 个 0 和 n 个 1 ，找到能拼出存在于数组中的字符串的最大数量。每个 0 和 1 至多被使用一次。
 * 
 * 注意:
 * 
 * 
 * 给定 0 和 1 的数量都不会超过 100。
 * 给定字符串数组的长度不会超过 600。
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
 * 输出: 4
 * 
 * 解释: 总共 4 个字符串可以通过 5 个 0 和 3 个 1 拼出，即 "10","0001","1","0" 。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: Array = {"10", "0", "1"}, m = 1, n = 1
 * 输出: 2
 * 
 * 解释: 你可以拼出 "10"，但之后就没有剩余数字了。更好的选择是拼出 "0" 和 "1" 。
 * 
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        for (int i = 0; i < strs.size(); i++) {
            int ones = 0, zeros = 0;
            for (auto& a : strs[i]) {
                if (a == '1') {
                    ones++;
                } else {
                    zeros++;
                }
            }

            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    if (i == 0) {
                        if (j >= zeros && k >= ones) {
                            dp[i][j][k] = 1;
                        }
                    } else {
                        dp[i][j][k] = dp[i - 1][j][k];
                        if (j >= zeros && k >= ones) {
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - zeros][k - ones] + 1);
                        }
                    }
                }
            }
        }

        return dp[strs.size() - 1][m][n];
    }
};
// @lc code=end
