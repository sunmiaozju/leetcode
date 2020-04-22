/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子序列
 *
 * https://leetcode-cn.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (37.06%)
 * Likes:    449
 * Dislikes: 0
 * Total Accepted:    44.3K
 * Total Submissions: 117.4K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字）。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> mx(nums.size(), 0);
        vector<int> mn(nums.size(), 0);
        mx[0] = nums[0];
        mn[0] = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            mx[i] = max(nums[i], max(nums[i] * mx[i - 1], nums[i] * mn[i - 1]));
            mn[i] = min(nums[i], min(nums[i] * mx[i - 1], nums[i] * mn[i - 1]));
            ans = max(ans, mx[i]);
        }
        return ans;
    }
};
// @lc code=end
