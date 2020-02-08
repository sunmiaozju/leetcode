/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 *
 * https://leetcode.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (60.59%)
 * Likes:    2027
 * Dislikes: 65
 * Total Accepted:    118.5K
 * Total Submissions: 191.6K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 
 * Given a list of daily temperatures T, return a list such that, for each day
 * in the input, tells you how many days you would have to wait until a warmer
 * temperature.  If there is no future day for which this is possible, put 0
 * instead.
 * 
 * For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76,
 * 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 * 
 * 
 * Note:
 * The length of temperatures will be in the range [1, 30000].
 * Each temperature will be an integer in the range [30, 100].
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T)
    {
        stack<int> s;
        vector<int> ans(T.size(), 0);
        for (int i = 0; i < T.size(); i++) {
            if (s.empty() || T[s.top()] >= T[i]) {
                s.push(i);
            } else {
                while (!s.empty() && T[s.top()] < T[i]) {
                    ans[s.top()] = i - s.top();
                    s.pop();
                }
                s.push(i);
            }
        }
        while (!s.empty()) {
            ans[s.top()] = 0;
            s.pop();
        }
        return ans;
    }
};
// @lc code=end
