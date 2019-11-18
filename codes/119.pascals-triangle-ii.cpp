/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (45.08%)
 * Likes:    545
 * Dislikes: 178
 * Total Accepted:    224.5K
 * Total Submissions: 497.2K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the k^th index row of the
 * Pascal's triangle.
 * 
 * Note that the row index starts from 0.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * 
 * Follow up:
 * 
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans;
        for (int i = 0; i < rowIndex + 1; i++) {
            ans.push_back(1);
            for (int j = i - 1; j > 0; j--) {
                ans[j] = ans[j] + ans[j - 1];
            }
        }
        return ans;
    }
};
