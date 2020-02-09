/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (55.08%)
 * Likes:    2442
 * Dislikes: 88
 * Total Accepted:    542.8K
 * Total Submissions: 980.3K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        // int left = 0, right;
        // while (left < nums.size()) {
        //     if (nums[left]) {
        //         left++;
        //     } else {
        //         right = left + 1;
        //         while (right < nums.size()) {
        //             if (nums[right]) {
        //                 swap(nums[left], nums[right]);
        //                 break;
        //             } else {
        //                 right++;
        //             }
        //         }
        //         if (right >= nums.size()) {
        //             return;
        //         }
        //     }
        // }
        // return;

        int left = 0, right = 0;
        for (int num : nums) {
            if (num != 0) {
                right++;
            } else {
                break;
            }
        }
        while (right < nums.size()) {
            if (nums[left] == 0 && nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
                right++;
            } else {
                if (nums[left] != 0) {
                    left++;
                }
                if (nums[right] == 0) {
                    right++;
                }
            }
        }
        return;
    }
};
// @lc code=end
