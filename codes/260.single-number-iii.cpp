/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (58.09%)
 * Likes:    1147
 * Dislikes: 90
 * Total Accepted:    124.6K
 * Total Submissions: 209.8K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * Given an array of numbers nums, in which exactly two elements appear only
 * once and all the other elements appear exactly twice. Find the two elements
 * that appear only once.
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,1,3,2,5]
 * Output: [3,5]
 * 
 * Note:
 * 
 * 
 * The order of the result is not important. So in the above example, [5, 3] is
 * also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant space complexity?
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        int num = 0;
        for (int a : nums) {
            num = a ^ num;
        }

        int diff = num & (-num);

        int num1 = 0, num2 = 0;
        for (int num : nums) {
            if ((num & diff) == 0) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }
        vector<int> ans;
        ans.push_back(num1);
        ans.push_back(num2);
        return ans;
    }
};
// @lc code=end
