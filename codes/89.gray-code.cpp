/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 *
 * https://leetcode.com/problems/gray-code/description/
 *
 * algorithms
 * Medium (46.66%)
 * Likes:    460
 * Dislikes: 1321
 * Total Accepted:    145.4K
 * Total Submissions: 309.2K
 * Testcase Example:  '2'
 *
 * The gray code is a binary numeral system where two successive values differ
 * in only one bit.
 * 
 * Given a non-negative integer n representing the total number of bits in the
 * code, print the sequence of gray code. A gray code sequence must begin with
 * 0.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: [0,1,3,2]
 * Explanation:
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * 
 * For a given n, a gray code sequence may not be uniquely defined.
 * For example, [0,2,3,1] is also a valid gray code sequence.
 * 
 * 00 - 0
 * 10 - 2
 * 11 - 3
 * 01 - 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 0
 * Output: [0]
 * Explanation: We define the gray code sequence to begin with 0.
 * A gray code sequence of n has size = 2^n, which for n = 0 the size is 2^0 =
 * 1.
 * Therefore, for n = 0 the gray code sequence is [0].
 * 
 * 
 */

// @lc code=start

#include <bitset>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n)
    {
        vector<int> nodes(pow(2, n), 0);
        if (n == 0) {
            return nodes;
        }
        vector<int> tmp = grayCode(n - 1);
        for (size_t i = 0; i < nodes.size() / 2; i++) {
            nodes[i] = tmp[i];
        }
        for (size_t i = nodes.size() / 2; i < nodes.size(); i++) {
            nodes[i] = pow(2, n - 1) + tmp[2 * tmp.size() - 1 - i];
        }
        return nodes;
    }
};
// @lc code=end
