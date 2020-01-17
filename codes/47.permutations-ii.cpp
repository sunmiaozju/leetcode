/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (42.06%)
 * Likes:    1491
 * Dislikes: 52
 * Total Accepted:    301.8K
 * Total Submissions: 690.4K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
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
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> visit(vector<bool>(nums.size(), false));
        help(ans, path, nums, visit);
        return ans;
    }

    void help(vector<vector<int>>& paths, vector<int>& path, vector<int>& nums, vector<bool>& visit)
    {
        if (path.size() == nums.size()) {
            paths.push_back(path);
            return;
        }

        for (size_t i = 0; i < nums.size(); i++) {
            if (i > 0 && !visit[i - 1] && nums[i] == nums[i - 1] || visit[i]) {
                continue;
            }
            path.push_back(nums[i]);
            visit[i] = true;
            help(paths, path, nums, visit);
            visit[i] = false;
            path.pop_back();
        }
    }
};
// @lc code=end
