/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 *
 * https://leetcode.com/problems/single-element-in-a-sorted-array/description/
 *
 * algorithms
 * Medium (57.44%)
 * Likes:    929
 * Dislikes: 66
 * Total Accepted:    69.4K
 * Total Submissions: 120.6K
 * Testcase Example:  '[1,1,2,3,3,4,4,8,8]'
 *
 * You are given a sorted array consisting of only integers where every element
 * appears exactly twice, except for one element which appears exactly once.
 * Find this single element that appears only once.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,1,2,3,3,4,4,8,8]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,3,7,7,10,11,11]
 * Output: 10
 * 
 * 
 * 
 * 
 * Note: Your solution should run in O(log n) time and O(1) space.
 * 
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        if (nums.size() == 1) {
            return nums[0];
        }
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid % 2 == 1 && nums[mid] == nums[mid + 1] || mid == 0 || mid % 2 == 0 && nums[mid] == nums[mid - 1]) {
                right = mid;
            } else if (mid % 2 == 1 && nums[mid] == nums[mid - 1] || mid % 2 == 0 && nums[mid] == nums[mid + 1]) {
                left = mid + 1;
            } else {
                return nums[mid];
            }
        }
        return nums[left];
    }
};
// @lc code=end
