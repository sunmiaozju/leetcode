/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 *
 * https://leetcode-cn.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (37.47%)
 * Likes:    400
 * Dislikes: 0
 * Total Accepted:    38.4K
 * Total Submissions: 102.2K
 * Testcase Example:  '[1,2,0]'
 *
 * 给定一个未排序的整数数组，找出其中没有出现的最小的正整数。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,0]
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,4,-1,1]
 * 输出: 2
 * 
 * 
 * 示例 3:
 * 
 * 输入: [7,8,9,11,12]
 * 输出: 1
 * 
 * 
 * 说明:
 * 
 * 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
 * 
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == i + 1 || nums[i] > nums.size() || nums[i] <= 0) {
                i++;
            } else {
                if (nums[i] == nums[nums[i] - 1]) {
                    i++;
                } else {
                    swap(nums[i], nums[nums[i] - 1]);
                }
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};
// @lc code=end
