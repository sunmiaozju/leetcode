/*
 * @lc app=leetcode id=766 lang=cpp
 *
 * [766] Toeplitz Matrix
 *
 * https://leetcode.com/problems/toeplitz-matrix/description/
 *
 * algorithms
 * Easy (62.41%)
 * Likes:    806
 * Dislikes: 73
 * Total Accepted:    80.4K
 * Total Submissions: 126.8K
 * Testcase Example:  '[[1,2,3,4],[5,1,2,3],[9,5,1,2]]'
 *
 * A matrix is Toeplitz if every diagonal from top-left to bottom-right has the
 * same element.
 * 
 * Now given an M x N matrix, return True if and only if the matrix is
 * Toeplitz.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * matrix = [
 * [1,2,3,4],
 * [5,1,2,3],
 * [9,5,1,2]
 * ]
 * Output: True
 * Explanation:
 * In the above grid, the diagonals are:
 * "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
 * In each diagonal all elements are the same, so the answer is True.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * matrix = [
 * [1,2],
 * [2,2]
 * ]
 * Output: False
 * Explanation:
 * The diagonal "[1, 2]" has different elements.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * matrix will be a 2D array of integers.
 * matrix will have a number of rows and columns in range [1, 20].
 * matrix[i][j] will be integers in range [0, 99].
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * What if the matrix is stored on disk, and the memory is limited such that
 * you can only load at most one row of the matrix into the memory at once?
 * What if the matrix is so large that you can only load up a partial row into
 * the memory at once?
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix)
    {
        int i = matrix.size() - 1, j = 0;

        while (j != matrix[0].size()) {
            int pre = matrix[i][j];
            int origin_i = i, origin_j = j;
            while (i < matrix.size() && j < matrix[0].size()) {
                if (matrix[i][j] != pre) {
                    return false;
                }
                pre = matrix[i][j];
                i++;
                j++;
            }

            i = origin_i;
            j = origin_j;
            if (i == 0) {
                j++;
            } else {
                i--;
            }
        }
        return true;
    }
};
// @lc code=end
