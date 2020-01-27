/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (41.37%)
 * Likes:    3525
 * Dislikes: 80
 * Total Accepted:    302.4K
 * Total Submissions: 722.9K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 * 
 * Example:
 * 
 * 
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4 
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4. 
 * 
 * Note: 
 * 
 * 
 * There may be more than one LIS combination, it is only necessary for you to
 * return the length.
 * Your algorithm should run in O(n^2) complexity.
 * 
 * 
 * Follow up: Could you improve it to O(n log n) time complexity?
 * 
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        if (nums.empty()) {
            return 0;
        }
        vector<int> dp(vector<int>(nums.size(), 1));
        for (size_t i = 1; i < nums.size(); i++) {
            int max_l = 1;
            for (size_t j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    max_l = max(max_l, dp[j] + 1);
                }
            }
            dp[i] = max_l;
        }

        int max_l = 0;
        for (size_t i = 0; i < dp.size(); i++) {
            max_l = max(max_l, dp[i]);
        }

        return max_l;
    }
};
// @lc code=end
