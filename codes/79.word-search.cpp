/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (32.29%)
 * Likes:    2437
 * Dislikes: 130
 * Total Accepted:    355.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        if (word.size() > board.size() * board[0].size())
            return false;
        string path;
        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[0].size(); j++) {
                if (help(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
    bool help(vector<vector<char>>& board, int r, int c, string& word, int index)
    {
        bool ret = false;
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] == '*') {
            return false;
        }
        if (board[r][c] == word[index]) {
            index++;
            if (index == word.size()) {
                return true;
            }
            char tmp = board[r][c];
            board[r][c] = '*';
            ret = help(board, r + 1, c, word, index) || help(board, r - 1, c, word, index) || help(board, r, c + 1, word, index) || help(board, r, c - 1, word, index);
            index--;
            board[r][c] = tmp;
        }
        return ret;
    }
};
// @lc code=end
