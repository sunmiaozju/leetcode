/*
 * @lc app=leetcode.cn id=576 lang=cpp
 *
 * [576] 出界的路径数
 *
 * https://leetcode-cn.com/problems/out-of-boundary-paths/description/
 *
 * algorithms
 * Medium (35.33%)
 * Likes:    51
 * Dislikes: 0
 * Total Accepted:    3.2K
 * Total Submissions: 9K
 * Testcase Example:  '2\n2\n2\n0\n0'
 *
 * 给定一个 m × n 的网格和一个球。球的起始坐标为 (i,j)
 * ，你可以将球移到相邻的单元格内，或者往上、下、左、右四个方向上移动使球穿过网格边界。但是，你最多可以移动 N
 * 次。找出可以将球移出边界的路径数量。答案可能非常大，返回 结果 mod 10^9 + 7 的值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入: m = 2, n = 2, N = 2, i = 0, j = 0
 * 输出: 6
 * 解释:
 * 
 * 
 * 
 * 示例 2：
 * 
 * 输入: m = 1, n = 3, N = 3, i = 0, j = 1
 * 输出: 12
 * 解释:
 * 
 * 
 * 
 * 
 * 
 * 说明:
 * 
 * 
 * 球一旦出界，就不能再被移动回网格内。
 * 网格的长度和高度在 [1,50] 的范围内。
 * N 在 [0,50] 的范围内。
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> dirs = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

    int findPaths(int m, int n, int N, int i, int j)
    {
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(N + 1, 0)));
        return help(m, n, N, i, j, dp);
    }

    int help(int m, int n, int N, int i, int j, vector<vector<vector<int>>>& dp)
    {
        // 如果次数用完了，那么直接返回0.
        // 计算当前位置到达所有边界的最小的步数， 如果大于N，那是怎么也出不去的的，直接返回0
        if (N == 0 || min(min(i + 1, m - i), min(j + 1, n - j)) > N) {
            return 0;
        }

        if (dp[i][j][N]) {
            return dp[i][j][N];
        }

        int mod = 1e9 + 7;
        int ans = 0;

        for (auto& a : dirs) {
            int x = i + a[0];
            int y = j + a[1];
            if (x >= 0 && x < m && y >= 0 && y < n) {
                ans = (ans + help(m, n, N - 1, x, y, dp)) % mod;
            } else {
                ans = (ans + 1) % mod;
            }
        }
        dp[i][j][N] = ans;
        return ans;
    }
};
// @lc code=end
