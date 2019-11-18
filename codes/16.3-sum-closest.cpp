/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.75%)
 * Likes:    1390
 * Dislikes: 100
 * Total Accepted:    389.3K
 * Total Submissions: 851.3K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int min_dis = INT_MAX;
        for (size_t i = 1; i < nums.size() - 1; i++) {
            int left = i - 1;
            int right = i + 1;

            while (true) {
                int dis = abs(nums[left] + nums[right] + nums[i] - target);
                if (dis < min_dis) {
                    ans = nums[left] + nums[right] + nums[i];
                    min_dis = dis;
                }

                if (nums[left] + nums[right] + nums[i] > target) {
                    if (left == 0) {
                        break;
                    } else {
                        left--;
                    }
                } else if (nums[left] + nums[right] + nums[i] < target) {
                    if (right == nums.size() - 1) {
                        break;
                    } else {
                        right++;
                    }
                } else {
                    return target;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
