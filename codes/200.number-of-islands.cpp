/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (42.74%)
 * Likes:    3527
 * Dislikes: 129
 * Total Accepted:    476.3K
 * Total Submissions: 1.1M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        stack<pair<int, int>> s;
        int max_num = 0;
        vector<pair<int, int>> directions = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    s.push(pair<int, int>(i, j));
                    grid[i][j] = '0';
                    while (!s.empty()) {
                        pair<int, int> item = s.top();
                        s.pop();
                        for (auto dir : directions) {
                            int r = item.first + dir.first;
                            int c = item.second + dir.second;
                            if (r < grid.size() && c < grid[0].size() && r >= 0 && c >= 0 && grid[r][c] == '1') {
                                s.push(pair<int, int>(r, c));
                                grid[r][c] = '0';
                            }
                        }
                    }
                    max_num++;
                }
            }
        }
        return max_num;
    }
};
// @lc code=end
