/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (41.35%)
 * Likes:    2354
 * Dislikes: 65
 * Total Accepted:    259.1K
 * Total Submissions: 612.4K
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n5'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * 
 * 
 * Example:
 * 
 * Consider the following matrix:
 * 
 * 
 * [
 * ⁠ [1,   4,  7, 11, 15],
 * ⁠ [2,   5,  8, 12, 19],
 * ⁠ [3,   6,  9, 16, 22],
 * ⁠ [10, 13, 14, 17, 24],
 * ⁠ [18, 21, 23, 26, 30]
 * ]
 * 
 * 
 * Given target = 5, return true.
 * 
 * Given target = 20, return false.
 * 
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        // if(matrix.size() == 0){
        //     return false;
        // }
        // return help(matrix, target, 0, 0, matrix.size()-1, matrix[0].size()-1);

        if (matrix.empty() || matrix[0].empty())
            return false;
        if (target < matrix[0][0] || target > matrix.back().back())
            return false;
        int x = matrix.size() - 1, y = 0;
        while (true) {
            if (matrix[x][y] > target)
                --x;
            else if (matrix[x][y] < target)
                ++y;
            else
                return true;
            if (x < 0 || y >= matrix[0].size())
                break;
        }
        return false;
    }
    // bool help(vector<vector<int>> & matrix, int target, int s0, int s1, int e0, int e1){
    //     if(s0 > e0 || s1 > e1){
    //         return false;
    //     }
    //     int row = s0, col = s1;
    //     bool ans = false;
    //     if(target == matrix[row][col]){
    //         return true;
    //     }else if(target < matrix[row][col]){
    //         return false;
    //     }else{
    //         if(s0 + 1 <= e0 && s1 + 1 <= e1){
    //             ans = ans || help(matrix, target, s0+1, s1+1, e0, e1);
    //             ans = ans || help(matrix, target, s0, s1+1, s0, e1);
    //             ans = ans || help(matrix, target, s0+1, s1, e0, s1);
    //         }else if(s0 == e0){
    //             ans = ans || help(matrix, target, s0, s1+1, s0, e1);
    //         }else if(s1 == e1){
    //             ans = ans || help(matrix, target, s0+1, s1, e0, s1);
    //         }
    //     }
    //     return ans;
    // }
};
// @lc code=end
