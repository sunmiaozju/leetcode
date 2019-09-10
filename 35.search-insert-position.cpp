/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (41.12%)
 * Likes:    1488
 * Dislikes: 195
 * Total Accepted:    443.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 * 
 * You may assume no duplicates in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5,6], 5
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,3,5,6], 2
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,3,5,6], 7
 * Output: 4
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: [1,3,5,6], 0
 * Output: 0
 * 
 * 
 */
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        // if (nums[0] > target) {
        //     return 0;
        // } else if (nums[nums.size() - 1] < target) {
        //     return nums.size();
        // }

        // for (size_t i = 0; i < nums.size(); i++) {
        //     if (nums[i] >= target) {
        //         return i;
        //     }
        // }
        // return 0;
        int front = 0, back = nums.size();
        while (front < back) {
            int mid = front + ((back - front) >> 1);

            if (target <= nums[mid]) {
                back = mid;
            } else {
                front = mid + 1;
            }
        }
        return back;
    }
};

// int main(int argc, const char** argv)
// {
//     Solution ss;
//     vector<int> nums;
//     nums.push_back(1);
//     nums.push_back(3);
//     nums.push_back(5);
//     nums.push_back(6);

//     ss.searchInsert(nums, 7);
//     return 0;
// }
