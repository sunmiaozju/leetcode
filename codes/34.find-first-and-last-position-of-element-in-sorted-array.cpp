/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (34.16%)
 * Likes:    2201
 * Dislikes: 103
 * Total Accepted:    377K
 * Total Submissions: 1.1M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        // 使用一个二分查找加局部遍历
        // vector<int> ans;
        // ans.push_back(-1);
        // ans.push_back(-1);
        // if (nums.empty()) {
        //     return ans;
        // }
        // int left = 0, right = nums.size() - 1, mid;
        // while (left < right) {
        //     mid = left + (right - left) / 2;
        //     if (nums[mid] < target) {
        //         left = mid + 1;
        //     } else {
        //         right = mid;
        //     }
        // }

        // if (nums[left] == target) {
        //     ans[0] = left++;
        // } else {
        //     return ans;
        // }

        // while (left < nums.size() && nums[left] == target) {
        //     left++;
        // }
        // ans[1] = left - 1;
        // return ans;

        // 使用两个二分查找
        // vector<int> ans;
        // ans.push_back(-1);
        // ans.push_back(-1);
        // if (nums.empty()) {
        //     return ans;
        // }
        // int left = 0, right = nums.size() - 1, mid;
        // while (left < right) {
        //     mid = left + (right - left) / 2;
        //     if (nums[mid] < target) {
        //         left = mid + 1;
        //     } else {
        //         right = mid;
        //     }
        // }

        // if (nums[left] == target) {
        //     ans[0] = left++;
        // } else {
        //     return ans;
        // }

        // left = 0;
        // right = nums.size() - 1;
        // while (left < right) {
        //     mid = left + (right - left) / 2;
        //     if (nums[mid] <= target) {
        //         left = mid + 1;
        //     } else {
        //         right = mid;
        //     }
        // }
        // ans[1] = nums[left] == target ? left : left - 1;
        // return ans;

        // 使用一个二分查找，找到一个之后将target+1
        if (nums.size() == 0) {
            return { -1, -1 };
        }
        int first = help(nums, 0, nums.size() - 1, target);
        if (nums[first] != target) {
            return { -1, -1 };
        } else {
            int last = help(nums, first, nums.size() - 1, target + 1);
            return { first, nums[last] == target ? last : max(last - 1, first) };
        }
    }
    int help(vector<int>& nums, int left, int right, int target)
    {
        int mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
// @lc code=end
