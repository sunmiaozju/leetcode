/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (40.21%)
 * Likes:    297
 * Dislikes: 0
 * Total Accepted:    55.8K
 * Total Submissions: 138.1K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 
 * 示例 1:
 * 
 * 输入: [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> ans;
        if (intervals.empty()) {
            return ans;
        }
        sort(intervals.begin(), intervals.end());
        int left = 0, right = 1;
        while (right < intervals.size()) {
            if (intervals[left][1] >= intervals[right][0]) {
                intervals[left][1] = max(intervals[left][1], intervals[right][1]);
                right++;
            } else {
                ans.push_back(intervals[left]);
                left = right;
                right = left + 1;
            }
        }
        ans.push_back(intervals[left]);
        return ans;
    }
};
// @lc code=end
