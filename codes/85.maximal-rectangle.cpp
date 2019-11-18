/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (34.46%)
 * Likes:    1824
 * Dislikes: 54
 * Total Accepted:    140.4K
 * Total Submissions: 401.6K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * Output: 6
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
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int ans = 0;
        for (size_t i = 0; i < matrix.size(); i++) {
            if (i > 0) {
                for (size_t j = 0; j < matrix[0].size(); j++) {
                    if (matrix[i][j] == '1' && matrix[i - 1][j] > '0') {
                        matrix[i][j] = matrix[i - 1][j] + 1;
                    }
                }
            }
            ans = max(ans, help(matrix[i]));
        }
        return ans;
    }
    int help(vector<char> items)
    {
        int area = 0;
        stack<int> myStack;
        items.push_back('0');
        for (size_t i = 0; i < items.size(); i++) {
            if (myStack.empty() || items[i] >= items[myStack.top()]) {
                myStack.push(i);
            } else {
                while (!myStack.empty() && items[i] < items[myStack.top()]) {
                    int index = myStack.top();
                    myStack.pop();
                    int tmp = (items[index] - '0') * (myStack.empty() ? i : i - myStack.top() - 1);
                    area = max(area, tmp);
                };
                myStack.push(i);
            };
        }

        return area;
    }
};
// @lc code=end
