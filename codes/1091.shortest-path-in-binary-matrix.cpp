/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 *
 * https://leetcode.com/problems/shortest-path-in-binary-matrix/description/
 *
 * algorithms
 * Medium (36.31%)
 * Likes:    168
 * Dislikes: 28
 * Total Accepted:    13.1K
 * Total Submissions: 35.8K
 * Testcase Example:  '[[0,1],[1,0]]'
 *
 * In an N by N square grid, each cell is either empty (0) or blocked (1).
 * 
 * A clear path from top-left to bottom-right has length k if and only if it is
 * composed of cells C_1, C_2, ..., C_k such that:
 * 
 * 
 * Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are
 * different and share an edge or corner)
 * C_1 is at location (0, 0) (ie. has value grid[0][0])
 * C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
 * If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] ==
 * 0).
 * 
 * 
 * Return the length of the shortest such clear path from top-left to
 * bottom-right.  If such a path does not exist, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[0,1],[1,0]]
 * 
 * 
 * Output: 2
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[0,0,0],[1,1,0],[1,1,0]]
 * 
 * 
 * Output: 4
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= grid.length == grid[0].length <= 100
 * grid[r][c] is 0 or 1
 * 
 * 
 */
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        // int col = 0, row = 0, size = grid.size(), r, c, n;
        // if (grid[row][col] == 1 || grid[size - 1][size - 1] == 1)
        //     return -1;
        // vector<vector<int>> visit(size, vector<int>(size, 0));
        // vector<pair<int, int>> direction = { { 1, 0 }, { 1, 1 }, { 0, 1 }, { -1, -1 }, { -1, 0 }, { 0, -1 }, { 1, -1 }, { -1, 1 } };
        // queue<int> q;
        // q.push(row * size + col);
        // visit[row][col] = 1;
        // while (!q.empty()) {
        //     int num = q.front();
        //     q.pop();
        //     row = num / size;
        //     col = num % size;
        //     grid[row][col] = 1;
        //     for (auto item : direction) {
        //         r = row + item.first;
        //         c = col + item.second;
        //         n = r * size + c;
        //         if (r >= 0 && c >= 0 && r < size && c < size && grid[r][c] == 0 && (visit[r][c] == 0 || visit[row][col] + 1 < visit[r][c])) {
        //             q.push(n);
        //             visit[r][c] = visit[row][col] + 1;
        //         }
        //     }
        // }
        // return visit[size - 1][size - 1] == 0 ? -1 : visit[size - 1][size - 1];

        // int col = 0, row = 0, size = grid.size(), r, c, n;
        // if (grid[row][col] == 1 || grid[size - 1][size - 1] == 1)
        //     return -1;
        // vector<pair<int, int>> direction = { { 1, 0 }, { 1, 1 }, { 0, 1 }, { -1, -1 }, { -1, 0 }, { 0, -1 }, { 1, -1 }, { -1, 1 } };
        // queue<int> q;
        // q.push(row * size + col);
        // grid[row][col] = 1;
        // while (!q.empty()) {
        //     int num = q.front();
        //     q.pop();
        //     row = num / size;
        //     col = num % size;
        //     for (auto item : direction) {
        //         r = row + item.first;
        //         c = col + item.second;
        //         n = r * size + c;
        //         if (r >= 0 && c >= 0 && r < size && c < size && (grid[r][c] == 0 || grid[row][col] + 1 < grid[r][c])) {
        //             q.push(n);
        //             grid[r][c] = grid[row][col] + 1;
        //         }
        //     }
        // }
        // return grid[size - 1][size - 1] == 0 ? -1 : grid[size - 1][size - 1];

        int col = 0, row = 0, size = grid.size(), r, c, n, len = 0;
        if (grid[row][col] == 1 || grid[size - 1][size - 1] == 1)
            return -1;
        vector<pair<int, int>> direction = { { 1, 0 }, { 1, 1 }, { 0, 1 }, { -1, -1 }, { -1, 0 }, { 0, -1 }, { 1, -1 }, { -1, 1 } };
        queue<int> q;
        q.push(row * size + col);
        grid[row][col] = 1;
        while (!q.empty()) {
            int nums = q.size();
            len++;
            while (nums--) {
                int num = q.front();
                q.pop();
                row = num / size;
                col = num % size;
                if (row == size - 1 && col == size - 1) {
                    return len;
                }
                for (auto item : direction) {
                    r = row + item.first;
                    c = col + item.second;
                    n = r * size + c;
                    if (r >= 0 && c >= 0 && r < size && c < size && (grid[r][c] == 0 || grid[row][col] + 1 < grid[r][c])) {
                        q.push(n);
                        grid[r][c] = grid[row][col] + 1;
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end
