/*
 * @lc app=leetcode id=665 lang=cpp
 *
 * [665] Non-decreasing Array
 *
 * https://leetcode.com/problems/non-decreasing-array/description/
 *
 * algorithms
 * Easy (19.49%)
 * Likes:    1293
 * Dislikes: 297
 * Total Accepted:    67.7K
 * Total Submissions: 349.8K
 * Testcase Example:  '[4,2,3]'
 *
 * 
 * Given an array with n integers, your task is to check if it could become
 * non-decreasing by modifying at most 1 element.
 * 
 * 
 * 
 * We define an array is non-decreasing if array[i]  holds for every i (1 
 * 
 * Example 1:
 * 
 * Input: [4,2,3]
 * Output: True
 * Explanation: You could modify the first 4 to 1 to get a non-decreasing
 * array.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [4,2,1]
 * Output: False
 * Explanation: You can't get a non-decreasing array by modify at most one
 * element.
 * 
 * 
 * 
 * Note:
 * The n belongs to [1, 10,000].
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool checkPossibility(vector<int>& nums)
    {
        int count = 0;
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                count++;
                if (count == 2) {
                    return false;
                }
                if (i == 1 || nums[i - 2] <= nums[i]) {
                    nums[i - 1] = nums[i];
                } else {
                    nums[i] = nums[i - 1];
                }
            }
        }
        return true;
    }
};
// @lc code=end
