/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (73.23%)
 * Likes:    818
 * Dislikes: 0
 * Total Accepted:    90.3K
 * Total Submissions: 122.5K
 * Testcase Example:  '3'
 *
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 
 * 例如，给出 n = 3，生成结果为：
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        string path;
        vector<string> ans;
        help(ans, path, n, n);
        return ans;
    }

    void help(vector<string>& ans, string& path, int left, int right)
    {
        if (left > right || left < 0 || right < 0) {
            return;
        }
        if (left == 0 && right == 0) {
            ans.push_back(path);
            return;
        }

        path.push_back('(');
        help(ans, path, left - 1, right);
        path.pop_back();

        path.push_back(')');
        help(ans, path, left, right - 1);
        path.pop_back();
    }
};
// @lc code=end
