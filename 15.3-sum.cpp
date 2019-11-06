/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.71%)
 * Likes:    4807
 * Dislikes: 573
 * Total Accepted:    688.8K
 * Total Submissions: 2.7M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> ans;
        if (nums.empty()) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        int left, right;
        for (size_t i = 0; i < nums.size() - 1; i++) {
            left = i + 1;
            right = nums.size() - 1;
            while (left < right) {
                int tmp = nums[left] + nums[right] + nums[i];
                if (tmp == 0) {
                    vector<int> items = { nums[left], nums[right], nums[i] };
                    ans.push_back(items);
                    while (left < right && nums[left] == items[0]) {
                        left++;
                    }
                    while (left < right && nums[right] == items[1]) {
                        right--;
                    }
                } else if (tmp > 0) {
                    right--;
                } else if (tmp < 0) {
                    left++;
                }
            }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        return ans;
    }
};
// @lc code=end
