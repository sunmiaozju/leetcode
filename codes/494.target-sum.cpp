/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (45.74%)
 * Likes:    1886
 * Dislikes: 85
 * Total Accepted:    128.8K
 * Total Submissions: 278.7K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 
 * You are given a list of non-negative integers, a1, a2, ..., an, and a
 * target, S. Now you have 2 symbols + and -. For each integer, you should
 * choose one from + and - as its new symbol.
 * ⁠
 * 
 * Find out how many ways to assign symbols to make sum of integers equal to
 * target S.  
 * 
 * 
 * Example 1:
 * 
 * Input: nums is [1, 1, 1, 1, 1], S is 3. 
 * Output: 5
 * Explanation: 
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 * 
 * 
 * 
 * Note:
 * 
 * The length of the given array is positive and will not exceed 20. 
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
 * 
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S)
    {
        int sum = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        if (sum < S || (sum + S) % 2 == 1) {
            return 0;
        }

        int target = (sum + S) / 2;

        vector<int> dp(vector<int>(target + 1, 0));
        dp[0] = 1;
        for (int num : nums) {
            for (int i = target; i >= num; i--) {
                dp[i] = dp[i] + dp[i - num];
                // cout << dp[0] << " " << dp[1] << " " << num << " " << i << endl;
            }
        }
        // cout << "--" << endl;
        return dp[target];
    }
};

// int main(int argc, const char** argv)
// {
//     Solution s;
//     vector<int> nums;
//     for (size_t i = 0; i < 5; i++) {
//         nums.push_back(1);
//     }

//     s.findTargetSumWays(nums, 3);
//     return 0;
// }
// @lc code=end
