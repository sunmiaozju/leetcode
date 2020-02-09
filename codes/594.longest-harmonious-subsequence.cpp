/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
 *
 * https://leetcode.com/problems/longest-harmonious-subsequence/description/
 *
 * algorithms
 * Easy (44.49%)
 * Likes:    517
 * Dislikes: 72
 * Total Accepted:    46.5K
 * Total Submissions: 102.8K
 * Testcase Example:  '[1,3,2,2,5,2,3,7]'
 *
 * We define a harmounious array as an array where the difference between its
 * maximum value and its minimum value is exactly 1.
 * 
 * Now, given an integer array, you need to find the length of its longest
 * harmonious subsequence among all its possible subsequences.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,2,2,5,2,3,7]
 * Output: 5
 * Explanation: The longest harmonious subsequence is [3,2,2,2,3].
 * 
 * 
 * 
 * 
 * Note: The length of the input array will not exceed 20,000.
 * 
 */

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        int ans = 0;

        for (auto i = map.begin(); i != map.end(); i++) {
            if (map.count(i->first + 1)) {
                ans = max(ans, i->second + map[i->first + 1]);
            }
        }

        return ans;
    }
};
// @lc code=end
