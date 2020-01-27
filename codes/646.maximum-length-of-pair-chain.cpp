/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 *
 * https://leetcode.com/problems/maximum-length-of-pair-chain/description/
 *
 * algorithms
 * Medium (49.47%)
 * Likes:    693
 * Dislikes: 61
 * Total Accepted:    46.4K
 * Total Submissions: 92.1K
 * Testcase Example:  '[[1,2], [2,3], [3,4]]'
 *
 * 
 * You are given n pairs of numbers. In every pair, the first number is always
 * smaller than the second number.
 * 
 * 
 * 
 * Now, we define a pair (c, d) can follow another pair (a, b) if and only if b
 * < c. Chain of pairs can be formed in this fashion. 
 * 
 * 
 * 
 * Given a set of pairs, find the length longest chain which can be formed. You
 * needn't use up all the given pairs. You can select pairs in any order.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: [[1,2], [2,3], [3,4]]
 * Output: 2
 * Explanation: The longest chain is [1,2] -> [3,4]
 * 
 * 
 * 
 * Note:
 * 
 * The number of given pairs will be in the range [1, 1000].
 * 
 * 
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs)
    {
        sort(pairs.begin(), pairs.end());
        vector<int> dp(vector<int>(pairs.size(), 1));

        for (size_t i = 0; i < pairs.size(); i++) {
            int max_l = 1;
            for (size_t j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1]) {
                    max_l = max(max_l, dp[j] + 1);
                }
            }
            dp[i] = max_l;
        }

        int max_l = 0;
        for (size_t i = 0; i < dp.size(); i++) {
            max_l = max(max_l, dp[i]);
        }
        return max_l;
    }
};
// @lc code=end
