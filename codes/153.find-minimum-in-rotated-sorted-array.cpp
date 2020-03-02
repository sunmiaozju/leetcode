/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (43.54%)
 * Likes:    1347
 * Dislikes: 187
 * Total Accepted:    341.8K
 * Total Submissions: 779.6K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,4,5,1,2] 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,5,6,7,0,1,2]
 * Output: 0
 * 
 * 
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int left = 0, right = nums.size() - 1, mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] <= nums[nums.size() - 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};

class Solution {
public:
    int findMin(vector<int>& nums)
    {
        if (nums.back() > nums[0]) {
            return nums[0];
        }
        int diff = nums[0] - 0;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] - mid >= diff) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};
// @lc code=end
