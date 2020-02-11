/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 *
 * https://leetcode.com/problems/degree-of-an-array/description/
 *
 * algorithms
 * Easy (51.30%)
 * Likes:    700
 * Dislikes: 639
 * Total Accepted:    70.1K
 * Total Submissions: 133K
 * Testcase Example:  '[1,2,2,3,1]'
 *
 * Given a non-empty array of non-negative integers nums, the degree of this
 * array is defined as the maximum frequency of any one of its elements.
 * Your task is to find the smallest possible length of a (contiguous) subarray
 * of nums, that has the same degree as nums.
 * 
 * Example 1:
 * 
 * Input: [1, 2, 2, 3, 1]
 * Output: 2
 * Explanation: 
 * The input array has a degree of 2 because both elements 1 and 2 appear
 * twice.
 * Of the subarrays that have the same degree:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * The shortest length is 2. So return 2.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1,2,2,3,1,4,2]
 * Output: 6
 * 
 * 
 * 
 * Note:
 * nums.length will be between 1 and 50,000.
 * nums[i] will be an integer between 0 and 49,999.
 * 
 */

// @lc code=start
class Solution {
public:
    int findShortestSubArray(vector<int>& nums)
    {
        unordered_map<int, int> m;
        unordered_map<int, pair<int, int>> pos;
        int degree = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (!m.count(nums[i])) {
                pos[nums[i]] = { i, i };
            } else {
                pos[nums[i]].second = i;
            }
            m[nums[i]]++;
            degree = max(degree, m[nums[i]]);
        }
        int ans = INT_MAX;
        for (auto a : m) {
            if (a.second == degree) {
                ans = min(ans, pos[a.first].second - pos[a.first].first + 1);
            }
        }
        return ans;
    }
};
// @lc code=end
