/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        // vector<int> ans;
        // for (size_t i = 0; i < nums.size() - 1; i++) {
        //     for (size_t j = i + 1; j < nums.size(); j++)
        //         if (nums[i] + nums[j] == target) {
        //             // cout << nums[i] << " + " << nums[j] << " = " << target << endl
        //             //      << "[i, j]" << std::endl;

        //             ans.push_back(i);
        //             ans.push_back(j);
        //             break;
        //         }
        // }
        // return ans;
        unordered_map<int, int> map;
        vector<int> ans;

        for (size_t i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end()) {
                ans.push_back(map[target - nums[i]]);
                ans.push_back(i);
                break;
            }
            map[nums[i]] = i;
        }
        return ans;
    }
};
