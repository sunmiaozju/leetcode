/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 *
 * https://leetcode.com/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (38.22%)
 * Likes:    834
 * Dislikes: 154
 * Total Accepted:    55.1K
 * Total Submissions: 142.2K
 * Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * Given an m x n matrix of non-negative integers representing the height of
 * each unit cell in a continent, the "Pacific ocean" touches the left and top
 * edges of the matrix and the "Atlantic ocean" touches the right and bottom
 * edges.
 * 
 * Water can only flow in four directions (up, down, left, or right) from a
 * cell to another one with height equal or lower.
 * 
 * Find the list of grid coordinates where water can flow to both the Pacific
 * and Atlantic ocean.
 * 
 * Note:
 * 
 * 
 * The order of returned grid coordinates does not matter.
 * Both m and n are less than 150.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given the following 5x5 matrix:
 * 
 * ⁠ Pacific ~   ~   ~   ~   ~ 
 * ⁠      ~  1   2   2   3  (5) *
 * ⁠      ~  3   2   3  (4) (4) *
 * ⁠      ~  2   4  (5)  3   1  *
 * ⁠      ~ (6) (7)  1   4   5  *
 * ⁠      ~ (5)  1   1   2   4  *
 * ⁠         *   *   *   *   * Atlantic
 * 
 * Return:
 * 
 * [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with
 * parentheses in above matrix).
 * 
 * 
 * 
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix)
    {
        vector<vector<int>> ans;
        if (matrix.empty()) {
            return ans;
        }
        bool left = false, right = false;
        int n_rows = matrix.size(), n_cols = matrix[0].size();
        vector<vector<bool>> P(n_rows, vector<bool>(n_cols, false));
        vector<vector<bool>> A(n_rows, vector<bool>(n_cols, false));
        for (size_t i = 0; i < n_cols; i++) {
            dfs(matrix, P, 0, i);
            dfs(matrix, A, n_rows - 1, i);
        }
        for (size_t i = 0; i < n_rows; i++) {
            dfs(matrix, A, i, n_cols - 1);
            dfs(matrix, P, i, 0);
        }
        for (int i = 0; i < n_rows; i++) {
            for (int j = 0; j < n_cols; j++) {
                if (P[i][j] && A[i][j]) {
                    ans.push_back({ i, j });
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visit, int r, int c)
    {
        if (visit[r][c]) {
            return;
        }
        visit[r][c] = true;
        vector<pair<int, int>> direction = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
        for (auto k : direction) {
            int row = r + k.first;
            int col = c + k.second;
            if (row >= 0 && col >= 0 && row < matrix.size() && col < matrix[0].size() && matrix[row][col] >= matrix[r][c]) {
                dfs(matrix, visit, row, col);
            }
        }
    }
};
// @lc code=end
