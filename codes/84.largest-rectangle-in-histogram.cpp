/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (32.15%)
 * Likes:    2411
 * Dislikes: 62
 * Total Accepted:    201.8K
 * Total Submissions: 620.9K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [2,1,5,6,2,3]
 * Output: 10
 * 
 * 
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        stack<int> myStack;
        int ans = 0;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            if (myStack.empty() || heights[myStack.top()] <= heights[i]) {
                myStack.push(i);
            } else {
                while (!myStack.empty() && heights[myStack.top()] > heights[i]) {
                    int index = myStack.top();
                    myStack.pop();
                    int area = heights[index] * (myStack.empty() ? i : i - myStack.top() - 1);
                    cout << i << " " << i - myStack.top() - 1 << " " << index << endl;
                    ans = std::max(ans, area);
                }
                myStack.push(i);
            }
        }
        return ans;
    }
};
// @lc code=end
