/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 *
 * https://leetcode.com/problems/single-number/description/
 *
 * algorithms
 * Easy (61.37%)
 * Likes:    2850
 * Dislikes: 106
 * Total Accepted:    527.7K
 * Total Submissions: 858.9K
 * Testcase Example:  '[2,2,1]'
 *
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,1]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,1,2,1,2]
 * Output: 4
 * 
 * 
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        // unordered_map<int, int> map;
        // for (size_t i = 0; i < nums.size(); i++) {
        //     unordered_map<int, int>::const_iterator iter;
        //     if ((iter = map.find(nums[i])) == map.end()) {
        //         map[nums[i]] = i;
        //     } else {
        //         map.erase(iter);
        //     }
        // }
        // return map.begin()->first;

        int ans = nums[0];
        for (size_t i = 1; i < nums.size(); i++) {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};
