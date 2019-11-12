/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 *
 * https://leetcode.com/problems/non-overlapping-intervals/description/
 *
 * algorithms
 * Medium (41.87%)
 * Likes:    641
 * Dislikes: 26
 * Total Accepted:    50.5K
 * Total Submissions: 120.7K
 * Testcase Example:  '[[1,2]]'
 *
 * Given a collection of intervals, find the minimum number of intervals you
 * need to remove to make the rest of the intervals non-overlapping.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,2],[2,3],[3,4],[1,3]]
 * Output: 1
 * Explanation: [1,3] can be removed and the rest of intervals are
 * non-overlapping.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,2],[1,2],[1,2]]
 * Output: 2
 * Explanation: You need to remove two [1,2] to make the rest of intervals
 * non-overlapping.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [[1,2],[2,3]]
 * Output: 0
 * Explanation: You don't need to remove any of the intervals since they're
 * already non-overlapping.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * You may assume the interval's end point is always bigger than its start
 * point.
 * Intervals like [1,2] and [2,3] have borders "touching" but they don't
 * overlap each other.
 * 
 * 
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        int ans = 0;
        sort(intervals.begin(), intervals.end(), [](auto& left, auto& right) {
            if (left[0] == right[0]) {
                return left[1] <= right[1];
            } else {
                return left[0] <= right[0];
            }
        });

        for (int i = 0, next = 1; next < intervals.size(); next++) {
            if (intervals[i][1] > intervals[next][0]) {
                ans++;
                if (intervals[i][1] > intervals[next][1]) {
                    i = next;
                }
            } else {
                i = next;
            }
        }
        return ans;
    }
};

// @lc code=end
