/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 *
 * https://leetcode.com/problems/max-area-of-island/description/
 *
 * algorithms
 * Medium (58.63%)
 * Likes:    1352
 * Dislikes: 65
 * Total Accepted:    108.6K
 * Total Submissions: 182.3K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]'
 *
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's
 * (representing land) connected 4-directionally (horizontal or vertical.) You
 * may assume all four edges of the grid are surrounded by water.
 * 
 * Find the maximum area of an island in the given 2D array. (If there is no
 * island, the maximum area is 0.)
 * 
 * Example 1:
 * 
 * 
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,1,1,0,1,0,0,0,0,0,0,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,0,1,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,1,1,0,0],
 * ⁠[0,0,0,0,0,0,0,0,0,0,1,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * 
 * Given the above grid, return 6. Note the answer is not 11, because the
 * island must be connected 4-directionally.
 * 
 * Example 2:
 * 
 * 
 * [[0,0,0,0,0,0,0,0]]
 * Given the above grid, return 0.
 * 
 * Note: The length of each dimension in the given grid does not exceed 50.
 * 
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        stack<pair<int, int>> s;
        int max_num = 0, cnt;
        vector<pair<int, int>> directions = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    s.push(pair<int, int>(i, j));
                    grid[i][j] = 0;
                    cnt = 1;
                    while (!s.empty()) {
                        pair<int, int> item = s.top();
                        s.pop();
                        for (auto dir : directions) {
                            int r = item.first + dir.first;
                            int c = item.second + dir.second;
                            if (r < grid.size() && c < grid[0].size() && r >= 0 && c >= 0 && grid[r][c] == 1) {
                                s.push(pair<int, int>(r, c));
                                grid[r][c] = 0;
                                cnt++;
                            }
                        }
                    }
                    max_num = max(max_num, cnt);
                }
            }
        }
        return max_num;
    }
};
// @lc code=end
