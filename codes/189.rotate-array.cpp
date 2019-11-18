/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 *
 * https://leetcode.com/problems/rotate-array/description/
 *
 * algorithms
 * Easy (31.35%)
 * Likes:    1617
 * Dislikes: 654
 * Total Accepted:    343.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * Given an array, rotate the array to the right by k steps, where k is
 * non-negative.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,4,5,6,7] and k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-1,-100,3,99] and k = 2
 * Output: [3,99,-1,-100]
 * Explanation: 
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 * 
 * 
 * Note:
 * 
 * 
 * Try to come up as many solutions as you can, there are at least 3 different
 * ways to solve this problem.
 * Could you do it in-place with O(1) extra space?
 * 
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        // 1
        vector<int> tmp;
        int size = nums.size();
        k = k % size;
        for (size_t i = 0; i < k; i++) {
            tmp.push_back(nums[size - k + i]);
        }
        for (int i = size - 1 - k; i >= 0; i--) {
            // cout << i << endl;
            nums[i + k] = nums[i];
        }
        for (size_t i = 0; i < k; i++) {
            nums[i] = tmp[i];
        }

        // 2
        // int size = nums.size();
        // for (size_t i = 0; i < k; i++) {
        //     nums.insert(nums.begin(), nums[size - 1]);
        //     nums.resize(size);
        // }

        // 3
        // vector<int> ans;
        // int size = nums.size();
        // ans.resize(size);
        // for (size_t i = 0; i < size; i++) {
        //     ans[(i + k) % size] = nums[i];
        // }
        // nums = ans;

        // 4 reverse
        // k = k % nums.size();
        // if (k) {
        //     reverse(nums.begin(), nums.end());
        //     reverse(nums.begin(), nums.begin() + k);
        //     reverse(nums.begin() + k, nums.end());
        // }
    }
};

// int main(int argc, const char** argv)
// {
//     Solution s;
//     vector<int> nums;
//     nums.push_back(1);
//     nums.push_back(2);
//     nums.push_back(3);
//     nums.push_back(4);
//     nums.push_back(5);
//     nums.push_back(6);
//     nums.push_back(7);
//     s.rotate(nums, 3);
//     return 0;
// }
