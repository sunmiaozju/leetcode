/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode-cn.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (35.35%)
 * Likes:    348
 * Dislikes: 0
 * Total Accepted:    24.8K
 * Total Submissions: 69.7K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。
 * 
 * 示例：
 * 
 * 输入: S = "ADOBECODEBANC", T = "ABC"
 * 输出: "BANC"
 * 
 * 说明：
 * 
 * 
 * 如果 S 中不存这样的子串，则返回空字符串 ""。
 * 如果 S 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t)
    {
        int mem[128] = { 0 };
        for (auto a : t) {
            mem[a]++;
        }

        int cnt = 0, left = 0;
        int minlen = INT_MAX;
        string ans;
        for (int i = 0; i < s.size(); i++) {
            mem[s[i]]--;
            if (mem[s[i]] >= 0) {
                cnt++;
                if (cnt == t.size()) {
                    while (true) {
                        mem[s[left]]++;
                        if (mem[s[left]] > 0) {
                            cnt--;
                            if (minlen > i - left + 1) {
                                minlen = i - left + 1;
                                ans = s.substr(left, minlen);
                            }
                        }
                        left++;
                        if (cnt < t.size()) {
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
