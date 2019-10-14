/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 *
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (35.94%)
 * Likes:    590
 * Dislikes: 725
 * Total Accepted:    221.1K
 * Total Submissions: 611.8K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * Given an array of integers and an integer k, find out whether there are two
 * distinct indices i and j in the array such that nums[i] = nums[j] and the
 * absolute difference between i and j is at most k.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
 * 
 * 
 * 
 * 
 * 
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        // unordered_map<int, int> map;
        // for (size_t i = 0; i < nums.size(); i++) {
        //     auto it = map.find(nums[i]);
        //     if (it != map.end()) {
        //         if (i - it->second <= k) {
        //             return true;
        //         } else {
        //             map[nums[i]] = i;
        //         }
        //     } else {
        //         map[nums[i]] = i;
        //     }
        // }
        // return false;

        unordered_set<int> mySet;
        for (size_t i = 0; i < nums.size(); i++) {
            if (i > k) {
                mySet.erase(nums[i - k - 1]);
            }
            if (mySet.find(nums[i]) != mySet.end()) {
                return true;
            } else {
                mySet.insert(nums[i]);
            }
        }
        return false;
    }
};
// @lc code=end
