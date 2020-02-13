/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 *
 * https://leetcode.com/problems/counting-bits/description/
 *
 * algorithms
 * Medium (65.59%)
 * Likes:    1943
 * Dislikes: 130
 * Total Accepted:    217.3K
 * Total Submissions: 325.9K
 * Testcase Example:  '2'
 *
 * Given a non negative integer number num. For every numbers i in the range 0
 * ≤ i ≤ num calculate the number of 1's in their binary representation and
 * return them as an array.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: [0,1,1]
 * 
 * Example 2:
 * 
 * 
 * Input: 5
 * Output: [0,1,1,2,1,2]
 * 
 * 
 * Follow up:
 * 
 * 
 * It is very easy to come up with a solution with run time
 * O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a
 * single pass?
 * Space complexity should be O(n).
 * Can you do it like a boss? Do it without using any builtin function like
 * __builtin_popcount in c++ or in any other language.
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int num)
    {
        if (num == 0) {
            return { 0 };
        }
        if (num == 1) {
            return { 0, 1 };
        }
        vector<int> ans = { 0, 1 };

        int k = 1, i = 2;
        while (i <= num) {
            for (i = pow(2, k); i < pow(2, k + 1); i++) {
                if (i > num) {
                    break;
                }
                int len = (pow(2, k + 1) - pow(2, k)) / 2;
                if (i < len + pow(2, k)) {
                    ans.push_back(ans[i - len]);
                } else {
                    ans.push_back(ans[i - len] + 1);
                }
            }
            k++;
        }
        return ans;
    }
};
// @lc code=end
