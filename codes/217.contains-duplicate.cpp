/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (53.23%)
 * Likes:    492
 * Dislikes: 578
 * Total Accepted:    402.5K
 * Total Submissions: 750.8K
 * Testcase Example:  '[1,2,3,1]'
 *
 * Given an array of integers, find if the array contains any duplicates.
 * 
 * Your function should return true if any value appears at least twice in the
 * array, and it should return false if every element is distinct.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4]
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 * 
 */
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        // unordered_map<int, int> map;
        // for (size_t i = 0; i < nums.size(); i++) {
        //     if (map.find(nums[i]) == map.end()) {
        //         map[nums[i]] = 0;
        //     } else {
        //         return true;
        //     }
        // }
        // return false;

        set<int> mySet;
        for (size_t i = 0; i < nums.size(); i++) {
            if (mySet.find(nums[i]) == mySet.end()) {
                mySet.insert(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
