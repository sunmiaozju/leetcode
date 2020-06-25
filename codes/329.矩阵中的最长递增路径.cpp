/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 *
 * https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/description/
 *
 * algorithms
 * Hard (39.69%)
 * Likes:    157
 * Dislikes: 0
 * Total Accepted:    12.4K
 * Total Submissions: 30.7K
 * Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'
 *
 * 给定一个整数矩阵，找出最长递增路径的长度。
 * 
 * 对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。
 * 
 * 示例 1:
 * 
 * 输入: nums = 
 * [
 * ⁠ [9,9,4],
 * ⁠ [6,6,8],
 * ⁠ [2,1,1]
 * ] 
 * 输出: 4 
 * 解释: 最长递增路径为 [1, 2, 6, 9]。
 * 
 * 示例 2:
 * 
 * 输入: nums = 
 * [
 * ⁠ [3,4,5],
 * ⁠ [3,2,6],
 * ⁠ [2,2,1]
 * ] 
 * 输出: 4 
 * 解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
 * 
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        if (matrix.size() == 0) {
            return 0;
        }
        int ans = 1;
        vector<vector<int>> dirs = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                ans = max(ans, dfs(matrix, dp, dirs, i, j));
            }
        }

        return ans;
    }

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, vector<vector<int>>& dirs, int i, int j)
    {
        if (dp[i][j]) {
            return dp[i][j];
        }
        dp[i][j] = 1;
        for (auto& a : dirs) {
            int x = i + a[0];
            int y = j + a[1];
            if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[x][y] > matrix[i][j]) {
                dp[i][j] = max(dp[i][j], 1 + dfs(matrix, dp, dirs, x, y));
            }
        }
        return dp[i][j];
    }
};
// @lc code=end
