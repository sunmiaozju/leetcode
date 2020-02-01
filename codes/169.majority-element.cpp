/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (54.00%)
 * Likes:    1962
 * Dislikes: 171
 * Total Accepted:    434.4K
 * Total Submissions: 802.6K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */

#include <algorithm>
#include <climits>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums)
    {

        // unordered_map<int, int> map;
        // for (size_t i = 0; i < nums.size(); i++) {
        //     if (++map[nums[i]] > nums.size() / 2) {
        //         return nums[i];
        //     }
        // }
        // return -1;

        // sort(nums.begin(), nums.end());
        // return nums[nums.size() / 2];

        // int n = nums.size(), candidate, counter;
        // srand(unsigned(time(NULL)));
        // while (true) {
        //     candidate = nums[rand() % n], counter = 0;
        //     for (int num : nums) {
        //         if (num == candidate) {
        //             counter++;
        //         }
        //     }
        //     if (counter > n / 2) {
        //         break;
        //     }
        // }
        // return candidate;

        // int counter = 0, majority;
        // for (int num : nums) {
        //     if (!counter) {
        //         majority = num;
        //     }
        //     counter += num == majority ? 1 : -1;
        // }
        // return majority;

        // double n = nums.size();

        // unordered_map<int, int> map;
        // sort(nums.begin(), nums.end());

        // for (int i = 0; i < nums.size(); i++) {
        //     map[nums[i]]++;
        //     if (map[nums[i]] >= n / 2.0) {
        //         return nums[i];
        //     }
        // }

        // return -1;

        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};
