/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (37.11%)
 * Likes:    393
 * Dislikes: 0
 * Total Accepted:    58.9K
 * Total Submissions: 158.4K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：
 * 
 * 答案中不可以包含重复的四元组。
 * 
 * 示例：
 * 
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> ans;
        if (nums.size() <= 3) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size() - 4; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int second = i + 1;
            int target2 = target - nums[i];
            for (int j = second; j <= nums.size() - 3; j++) {
                if (j > second && nums[j] == nums[j - 1]) {
                    continue;
                }
                int target3 = target2 - nums[j];
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    int item = nums[left] + nums[right];
                    if (item == target3) {
                        vector<int> items = { nums[i], nums[j], nums[left], nums[right] };
                        ans.push_back(items);
                        while (left < right && nums[left] == items[2]) {
                            left++;
                        }
                        while (left < right && nums[right] == items[3]) {
                            right--;
                        }
                    } else if (item < target3) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
