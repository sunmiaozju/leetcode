/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 *
 * https://leetcode-cn.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (77.20%)
 * Likes:    112
 * Dislikes: 0
 * Total Accepted:    20.8K
 * Total Submissions: 26.6K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回 n 皇后不同的解决方案的数量。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: 2
 * 解释: 4 皇后问题存在如下两个不同的解法。
 * [
 * [".Q..",  // 解法 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // 解法 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int totalNQueens(int n)
    {
        vector<string> queens(n, string(n, '.'));
        int res = 0;
        place(0, queens, res);
        return res;
    }

    void place(int row, vector<string>& queens, int& res)
    {
        if (row == queens.size()) {
            res++;
            return;
        }

        for (int i = 0; i < queens.size(); i++) {
            if (isValid(row, i, queens)) {
                queens[row][i] = 'Q';
                place(row + 1, queens, res);
                queens[row][i] = '.';
            }
        }
    }

    bool isValid(int row, int col, vector<string>& queens)
    {
        for (int i = 0; i < row; i++) {
            if (queens[i][col] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (queens[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < queens.size(); i--, j++) {
            if (queens[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
