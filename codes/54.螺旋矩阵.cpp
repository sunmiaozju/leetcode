/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode-cn.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (38.56%)
 * Likes:    298
 * Dislikes: 0
 * Total Accepted:    40.3K
 * Total Submissions: 104.3K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 输出: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * 输出: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> ans;
        if (matrix.empty()) {
            return ans;
        }
        int i = 0, j = 0, ei = matrix.size() - 1, ej = matrix[0].size() - 1;
        while (i <= ei && j <= ej) {
            help(matrix, i, j, ei, ej, ans);
            i++;
            j++;
            ei--;
            ej--;
        }
        return ans;
    }

    void help(vector<vector<int>>& matrix, int si, int sj, int ei, int ej, vector<int>& ans)
    {
        if (si == ei) {
            for (int i = sj; i <= ej; i++) {
                ans.push_back(matrix[si][i]);
            }
            return;
        } else if (sj == ej) {
            for (int i = si; i <= ei; i++) {
                ans.push_back(matrix[i][sj]);
            }
            return;
        }
        int indexi = si, indexj = sj;
        while (true) {
            ans.push_back(matrix[indexi][indexj]);
            if (indexi == si && indexj < ej) {
                indexj++;
            } else if (indexj == ej && indexi < ei) {
                indexi++;
            } else if (indexi == ei && indexj > sj) {
                indexj--;
            } else if (indexj == sj && indexi > si) {
                indexi--;
                if (indexi == si) {
                    break;
                }
            }
        }
    }
};
// @lc code=end
