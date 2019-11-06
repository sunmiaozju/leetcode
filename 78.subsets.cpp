/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (54.90%)
 * Likes:    2489
 * Dislikes: 60
 * Total Accepted:    436.3K
 * Total Submissions: 779.5K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vecint;
// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        // vector<vector<int>> ans;
        // ans.push_back(vector<int>());
        // vector<int> tmp;
        // for (int i = nums.size() - 1; i >= 0; i--) {
        //     int num = ans.size();
        //     for (size_t j = 0; j < num; j++) {
        //         tmp.push_back(nums[i]);
        //         tmp.insert(tmp.end(), ans[j].begin(), ans[j].end());
        //         ans.push_back(tmp);
        //         tmp = vector<int>();
        //     }
        // }
        // return ans;

        vector<vector<int>> subs;
        vector<int> sub;
        help(subs, sub, nums, 0);
        return subs;
    }
    void help(vector<vector<int>>& subs, vector<int>& sub, vector<int>& nums, int pos)
    {
        subs.push_back(sub);
        for (size_t i = pos; i < nums.size(); i++) {
            sub.push_back(nums[i]);
            help(subs, sub, nums, i + 1);
            sub.pop_back();
        }
    }
};
// int main(int argc, const char** argv)
// {
//     Solution s;
//     vector<int> nums;
//     nums.push_back(1);
//     nums.push_back(2);
//     nums.push_back(3);
//     s.subsets(nums);
//     return 0;
// }
// @lc code=end
