/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (57.25%)
 * Likes:    2884
 * Dislikes: 91
 * Total Accepted:    493.7K
 * Total Submissions: 829.6K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> path;
        help(ans, path, nums);
        return ans;
    }

    void help(vector<vector<int>>& paths, vector<int>& path, vector<int>& nums)
    {
        if (path.size() == nums.size()) {
            paths.push_back(path);
            return;
        }

        for (size_t i = 0; i < nums.size(); i++) {
            bool isSame = false;
            for (size_t j = 0; j < path.size(); j++) {
                if (nums[i] == path[j]) {
                    isSame = true;
                }
            }
            if (!isSame) {
                path.push_back(nums[i]);
                help(paths, path, nums);
                path.pop_back();
            }
        }
    }
};
// @lc code=end
