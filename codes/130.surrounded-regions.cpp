/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (23.90%)
 * Likes:    1023
 * Dislikes: 513
 * Total Accepted:    171.9K
 * Total Submissions: 699.3K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 * 
 * Example:
 * 
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * After running your function, the board should be:
 * 
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * Explanation:
 * 
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on
 * the border of the board are not flipped to 'X'. Any 'O' that is not on the
 * border and it is not connected to an 'O' on the border will be flipped to
 * 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 * 
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board)
    {
        if (board.size() < 3)
            return;
        int r = 0, c = 0, n_rows = board.size(), n_cols = board[0].size();
        while (true) {
            if (board[r][c] == 'O') {
                dfs(board, r, c);
            }
            if (c == 0 && r == 1) {
                break;
            }
            if (r == 0 && c < n_cols - 1) {
                c++;
            } else if (c == n_cols - 1 && r < n_rows - 1) {
                r++;
            } else if (r == n_rows - 1 && c > 0) {
                c--;
            } else if (r > 1 && c == 0) {
                r--;
            }
        }
        for (size_t i = 0; i < n_rows; i++) {
            for (size_t j = 0; j < n_cols; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    void dfs(vector<vector<char>>& board, int r, int c)
    {
        vector<pair<int, int>> direction = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
        stack<pair<int, int>> s;
        s.push(pair<int, int>(r, c));
        board[r][c] = 'T';
        while (!s.empty()) {
            auto item = s.top();
            s.pop();
            for (auto k : direction) {
                int row = item.first + k.first;
                int col = item.second + k.second;
                if (row < board.size() && row >= 0 && col < board[0].size() && col >= 0 && board[row][col] == 'O') {
                    s.push(pair<int, int>(row, col));
                    board[row][col] = 'T';
                }
            }
        }
    }
};
// @lc code=end
