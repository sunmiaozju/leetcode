/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 *
 * https://leetcode-cn.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (41.20%)
 * Likes:    198
 * Dislikes: 0
 * Total Accepted:    28.6K
 * Total Submissions: 69.1K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。
 * 
 * 示例: 
 * 
 * 输入: s = 7, nums = [2,3,1,2,4,3]
 * 输出: 2
 * 解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。
 * 
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {

        int left = 0, right = 0;
        int sum = 0;
        int ans = INT_MAX;
        while (right < nums.size()) {
            sum += nums[right];
            if (sum >= s) {
                while (sum >= s) {
                    ans = min(ans, right - left + 1);
                    sum -= nums[left];
                    left++;
                }
            }
            right++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
// @lc code=end
