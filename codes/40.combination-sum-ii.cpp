/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (43.33%)
 * Likes:    1269
 * Dislikes: 54
 * Total Accepted:    277.1K
 * Total Submissions: 615.1K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<bool> visit(vector<bool>(candidates.size(), false));
        vector<int> path;
        help(ans, path, candidates, target, visit);
        return ans;
    }

    void help(vector<vector<int>>& paths, vector<int>& path, vector<int>& candidates, int target, vector<bool>& visit)
    {
        int sum = 0;
        for (size_t i = 0; i < path.size(); i++) {
            sum += path[i];
            if (sum > target) {
                return;
            }
        }
        if (sum == target) {
            paths.push_back(path);
            return;
        }

        for (size_t i = 0; i < candidates.size(); i++) {
            if (i > 0 && !visit[i - 1] && candidates[i - 1] == candidates[i] || visit[i]) {
                continue;
            }
            if (!path.empty() && path[path.size() - 1] > candidates[i]) {
                continue;
            }
            visit[i] = true;
            path.push_back(candidates[i]);
            help(paths, path, candidates, target, visit);
            visit[i] = false;
            path.pop_back();
        }
    }
};
// @lc code=end
