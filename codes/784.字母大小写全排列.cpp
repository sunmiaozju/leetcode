/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 *
 * https://leetcode-cn.com/problems/letter-case-permutation/description/
 *
 * algorithms
 * Easy (62.45%)
 * Likes:    143
 * Dislikes: 0
 * Total Accepted:    14.2K
 * Total Submissions: 22.6K
 * Testcase Example:  '"a1b2"'
 *
 * 给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。
 * 
 * 
 * 示例:
 * 输入: S = "a1b2"
 * 输出: ["a1b2", "a1B2", "A1b2", "A1B2"]
 * 
 * 输入: S = "3z4"
 * 输出: ["3z4", "3Z4"]
 * 
 * 输入: S = "12345"
 * 输出: ["12345"]
 * 
 * 
 * 注意：
 * 
 * 
 * S 的长度不超过12。
 * S 仅由数字和字母组成。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCasePermutation(string S)
    {
        vector<string> ans;
        ans.push_back(S);
        for (int i = 0; i < S.size(); i++) {
            if (S[i] >= '0' && S[i] <= '9') {
                continue;
            }
            int size = ans.size();
            for (int j = 0; j < size; j++) {
                ans.push_back(ans[j]);
                if (ans.back()[i] >= 'a' && ans.back()[i] <= 'z') {
                    ans.back()[i] -= 'a' - 'A';
                } else {
                    ans.back()[i] += 'a' - 'A';
                }
            }
        }
        return ans;
    }
};

// @lc code=end
