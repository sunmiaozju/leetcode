/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (56.44%)
 * Likes:    3459
 * Dislikes: 297
 * Total Accepted:    374.4K
 * Total Submissions: 642.5K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an array nums of n integers where n > 1,  return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * 
 * 
 * Note: Please solve it without division and in O(n).
 * 
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does
 * not count as extra space for the purpose of space complexity analysis.)
 * 
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> ans(nums.size(), 1);

        for (int i = 1; i < ans.size(); i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int right = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans[i] = ans[i] * right;
            right *= nums[i];
        }

        return ans;
    }
};
// @lc code=end
