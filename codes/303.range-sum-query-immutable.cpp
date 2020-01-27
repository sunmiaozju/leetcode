/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 *
 * https://leetcode.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (39.58%)
 * Likes:    666
 * Dislikes: 918
 * Total Accepted:    171.2K
 * Total Submissions: 413.1K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 * 
 * Example:
 * 
 * Given nums = [-2, 0, 3, -5, 2, -1]
 * 
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * 
 * 
 * 
 * Note:
 * 
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 * 
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class NumArray {
public:
    // vector<int> data_nums;
    // NumArray(vector<int>& nums)
    // {
    //     data_nums.resize(nums.size());
    //     for (size_t i = 0; i < nums.size(); i++) {
    //         data_nums[i] = nums[i];
    //     }
    // }

    // int sumRange(int i, int j)
    // {
    //     int sum = 0;
    //     for (size_t index = i; index <= j; index++) {
    //         sum += data_nums[index];
    //     }
    //     return sum;
    // }

    vector<int> data_nums;
    NumArray(vector<int>& nums)
    {
        if (nums.empty()) {
            return;
        }

        data_nums.resize(nums.size() + 1);
        data_nums[0] = 0;
        for (size_t i = 1; i <= nums.size(); i++) {
            data_nums[i] = data_nums[i - 1] + nums[i - 1];
        }
    }

    int sumRange(int i, int j)
    {
        return data_nums[j + 1] - data_nums[i];
    }
};
// 0 -2 -2 1 -4 -2 -3
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end
