/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (52.92%)
 * Likes:    819
 * Dislikes: 45
 * Total Accepted:    145.8K
 * Total Submissions: 269.1K
 * Testcase Example:  '3\n7'
 *
 * 
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 * 
 * Note:
 * 
 * 
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> path;
        int path_sum = 0;
        help(ans, path, k, n, path_sum);
        return ans;
    }

    void help(vector<vector<int>>& paths, vector<int>& path, int k, int n, int& path_sum)
    {
        if (path_sum > n) {
            return;
        }

        if (path.size() == k) {
            if (path_sum == n) {
                paths.push_back(path);
            }
            return;
        }

        for (size_t i = 1; i <= 9; i++) {
            if (!path.empty() && path[path.size() - 1] >= i) {
                continue;
            }
            path.push_back(i);
            path_sum += i;
            help(paths, path, k, n, path_sum);
            path_sum -= i;
            path.pop_back();
        }
    }
};
// @lc code=end
