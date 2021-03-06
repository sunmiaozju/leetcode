/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 *
 * https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
 *
 * algorithms
 * Medium (47.19%)
 * Likes:    617
 * Dislikes: 29
 * Total Accepted:    47.5K
 * Total Submissions: 99.9K
 * Testcase Example:  '[[10,16],[2,8],[1,6],[7,12]]'
 *
 * There are a number of spherical balloons spread in two-dimensional space.
 * For each balloon, provided input is the start and end coordinates of the
 * horizontal diameter. Since it's horizontal, y-coordinates don't matter and
 * hence the x-coordinates of start and end of the diameter suffice. Start is
 * always smaller than end. There will be at most 10^4 balloons.
 * 
 * An arrow can be shot up exactly vertically from different points along the
 * x-axis. A balloon with xstart and xend bursts by an arrow shot at x if
 * xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be
 * shot. An arrow once shot keeps travelling up infinitely. The problem is to
 * find the minimum number of arrows that must be shot to burst all balloons.
 * 
 * Example:
 * 
 * 
 * Input:
 * [[10,16], [2,8], [1,6], [7,12]]
 * 
 * Output:
 * 2
 * 
 * Explanation:
 * One way is to shoot one arrow for example at x = 6 (bursting the balloons
 * [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two
 * balloons).
 * 
 * 
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        if (points.empty())
            return 0;

        sort(points.begin(), points.end(), [](auto& a, auto& b) {
            if (a[0] == b[0]) {
                return a[1] <= b[1];
            } else {
                return a[0] <= b[0];
            }
        });
        int ans = 0;

        for (size_t i = 0, next = 1; next < points.size(); next++) {
            if (points[i][1] < points[next][0]) {
                ans++;
                i = next;
            } else {
                points[i][1] = min(points[next][1], points[i][1]);
            }
        }
        return ans + 1;
    }
};
// @lc code=end
