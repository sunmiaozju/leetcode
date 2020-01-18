/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (50.56%)
 * Likes:    2855
 * Dislikes: 88
 * Total Accepted:    445.8K
 * Total Submissions: 847.3K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
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
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */

// @lc code=start

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> path;
        help(ans, path, candidates, target);
        return ans;
    }

    void help(vector<vector<int>>& paths, vector<int>& path, vector<int>& candidates, int target)
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
            if (!path.empty() && candidates[i] < path[path.size() - 1]) {
                continue;
            }

            path.push_back(candidates[i]);
            help(paths, path, candidates, target);
            path.pop_back();
        }
    }
};
// @lc code=end
