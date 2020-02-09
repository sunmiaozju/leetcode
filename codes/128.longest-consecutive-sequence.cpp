/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (42.61%)
 * Likes:    2561
 * Dislikes: 148
 * Total Accepted:    258.8K
 * Total Submissions: 592.2K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 * 
 * Your algorithm should run in O(n) complexity.
 * 
 * Example:
 * 
 * 
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> s;
        for (int a : nums) {
            s.insert(a);
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (s.count(nums[i])) {
                s.erase(nums[i]);
                int pre = nums[i] - 1, next = nums[i] + 1;
                while (s.count(pre) || s.count(next)) {
                    if (s.count(pre)) {
                        s.erase(pre);
                        pre--;
                    }
                    if (s.count(next)) {
                        s.erase(next);
                        next++;
                    }
                }
                ans = max(ans, next - pre - 1);
            }
        }
        return ans;
    }
};
// @lc code=end
