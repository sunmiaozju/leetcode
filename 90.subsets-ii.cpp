/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (43.60%)
 * Likes:    1141
 * Dislikes: 55
 * Total Accepted:    231.4K
 * Total Submissions: 523.8K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 * 
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> paths;
        vector<int> path;
        help(nums, path, paths, 0);
        return paths;
    }
    void help(vector<int>& nums, vector<int>& path, vector<vector<int>>& paths, int pos)
    {
        paths.push_back(path);
        for (int i = pos; i < nums.size(); i++) {
            if (i - 1 >= pos && nums[i] == nums[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            help(nums, path, paths, i + 1);
            path.pop_back();
        }
    }
};

// @lc code=end
