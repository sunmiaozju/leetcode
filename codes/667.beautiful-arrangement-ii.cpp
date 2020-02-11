/*
 * @lc app=leetcode id=667 lang=cpp
 *
 * [667] Beautiful Arrangement II
 *
 * https://leetcode.com/problems/beautiful-arrangement-ii/description/
 *
 * algorithms
 * Medium (52.51%)
 * Likes:    274
 * Dislikes: 570
 * Total Accepted:    21.4K
 * Total Submissions: 40.1K
 * Testcase Example:  '3\n2'
 *
 * 
 * Given two integers n and k, you need to construct a list which contains n
 * different positive integers ranging from 1 to n and obeys the following
 * requirement: 
 * 
 * Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 -
 * a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.
 * 
 * 
 * 
 * If there are multiple answers, print any of them.
 * 
 * 
 * Example 1:
 * 
 * Input: n = 3, k = 1
 * Output: [1, 2, 3]
 * Explanation: The [1, 2, 3] has three different positive integers ranging
 * from 1 to 3, and the [1, 1] has exactly 1 distinct integer: 1.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: n = 3, k = 2
 * Output: [1, 3, 2]
 * Explanation: The [1, 3, 2] has three different positive integers ranging
 * from 1 to 3, and the [2, 1] has exactly 2 distinct integers: 1 and 2.
 * 
 * 
 * 
 * Note:
 * 
 * The n and k are in the range 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> constructArray(int n, int k)
    {
        vector<int> ans;
        int left = 1, right = 1 + k;
        while (left < right) {
            ans.push_back(left);
            ans.push_back(right);
            left++;
            right--;
        }
        if (left == right) {
            ans.push_back(left);
        }
        int num = k + 2;
        while (num <= n) {
            ans.push_back(num);
            num++;
        }
        return ans;
    }
};
// @lc code=end
