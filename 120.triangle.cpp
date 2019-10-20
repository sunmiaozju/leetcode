/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (40.64%)
 * Likes:    1362
 * Dislikes: 156
 * Total Accepted:    204.3K
 * Total Submissions: 497.4K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 * 
 * For example, given the following triangle
 * 
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * Note:
 * 
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        vector<int> ans = triangle[triangle.size() - 1];
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (size_t j = 0; j <= i; j++) {
                ans[j] = triangle[i][j] + min(ans[j], ans[j + 1]);
            }
        }
        return ans[0];
    }
};
// @lc code=end
