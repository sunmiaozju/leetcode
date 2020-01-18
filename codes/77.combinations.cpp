/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (49.62%)
 * Likes:    1112
 * Dislikes: 59
 * Total Accepted:    249.7K
 * Total Submissions: 484.7K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> path;
        vector<vector<int>> paths;
        help(paths, path, n, k);
        return paths;
    }

    void help(vector<vector<int>>& paths, vector<int>& path, int n, int k)
    {
        if (path.size() == k) {
            paths.push_back(path);
            return;
        }

        for (size_t i = 1; i <= n; i++) {
            if (path.size() == 0 || path[path.size() - 1] < i) {
                path.push_back(i);
                help(paths, path, n, k);
                path.pop_back();
            }
        }
    }
};
// @lc code=end
