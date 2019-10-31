/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (47.02%)
 * Likes:    954
 * Dislikes: 269
 * Total Accepted:    179.5K
 * Total Submissions: 381.1K
 * Testcase Example:  '[2,2,3,2]'
 *
 * Given a non-empty array of integers, every element appears three times
 * except for one, which appears exactly once. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,3,2]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,1,0,1,0,1,99]
 * Output: 99
 * 
 */

#include <iostream>
// #include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    Solution() {}
    ~Solution() {}

    int singleNumber(vector<int>& nums)
    {
        // unordered_map<int, int> map;
        // for (size_t i = 0; i < nums.size(); i++) {
        //     unordered_map<int, int>::const_iterator iter;
        //     if ((iter = map.find(nums[i])) == map.end()) {
        //         map[nums[i]] = 1;
        //     } else {
        //         map[nums[i]]++;
        //     }
        // }
        // for (auto i = map.begin(); i != map.end(); i++) {
        //     if (i->second == 1) {
        //         return i->first;
        //     }
        // }
        // return -1;

        //         int ones = 0, twos = 0;
        // for (size_t i = 0; i < nums.size(); i++) {
        //     ones = (ones ^ nums[i]) & ~twos;
        //     twos = (twos ^ nums[i]) & ~ones;
        // }
        // return ones;

        int ones = 0, twos = 0, threes = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            ones = (ones ^ nums[i]) & ~twos & ~threes;
            twos = (twos ^ nums[i]) & ~ones & ~threes;
            threes = (threes ^ nums[i]) & ~ones & ~twos;
        }
        return ones;
    }
    // }
};

int main(int argc, char** argv)
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(2);
    Solution s;
    int num = s.singleNumber(nums);
    std::cout << num << std::endl;

    return 0;
}
