/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 *
 * https://leetcode-cn.com/problems/counting-bits/description/
 *
 * algorithms
 * Medium (74.53%)
 * Likes:    277
 * Dislikes: 0
 * Total Accepted:    33.5K
 * Total Submissions: 44.7K
 * Testcase Example:  '2'
 *
 * 给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。
 * 
 * 示例 1:
 * 
 * 输入: 2
 * 输出: [0,1,1]
 * 
 * 示例 2:
 * 
 * 输入: 5
 * 输出: [0,1,1,2,1,2]
 * 
 * 进阶:
 * 
 * 
 * 给出时间复杂度为O(n*sizeof(integer))的解答非常容易。但你可以在线性时间O(n)内用一趟扫描做到吗？
 * 要求算法的空间复杂度为O(n)。
 * 你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的 __builtin_popcount）来执行此操作。
 * 
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> countBits(int num)
    {
        if (num == 0) {
            return { 0 };
        } else if (num == 1) {
            return { 0, 1 };
        }

        vector<int> ans;
        ans.push_back(0);

        int left = 0, right = 1;
        int l_num = pow(2, left), r_num = pow(2, right);
        int len = r_num - l_num;
        for (int i = 1; i <= num; i++) {
            if (l_num <= i && i < r_num) {
                ans.push_back(ans[i - len] + 1);
            } else {
                left++;
                right++;
                l_num = pow(2, left);
                r_num = pow(2, right);
                len = r_num - l_num;
                i--;
            }
        }
        return ans;
    }
};
// @lc code=end
