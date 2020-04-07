/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 *
 * https://leetcode-cn.com/problems/is-subsequence/description/
 *
 * algorithms
 * Easy (47.78%)
 * Likes:    145
 * Dislikes: 0
 * Total Accepted:    32.8K
 * Total Submissions: 67.5K
 * Testcase Example:  '"abc"\n"ahbgdc"'
 *
 * 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
 * 
 * 你可以认为 s 和 t 中仅包含英文小写字母。字符串 t 可能会很长（长度 ~= 500,000），而 s 是个短字符串（长度 <=100）。
 * 
 * 
 * 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
 * 
 * 示例 1:
 * s = "abc", t = "ahbgdc"
 * 
 * 返回 true.
 * 
 * 示例 2:
 * s = "axc", t = "ahbgdc"
 * 
 * 返回 false.
 * 
 * 后续挑战 :
 * 
 * 如果有大量输入的 S，称作S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T
 * 的子序列。在这种情况下，你会怎样改变代码？
 * 
 * 致谢:
 * 
 * 特别感谢 @pbrother 添加此问题并且创建所有测试用例。
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t)
    {

        // if (s.empty()) {
        //     return true;
        // }
        // int index = 0;
        // for (size_t i = 0; i < t.size(); i++) {
        //     if (s[index] == t[i]) {
        //         index++;
        //         if (index == s.size()) {
        //             return true;
        //         }
        //     }
        // }
        // return false;

        int pre = -1, n = t.size();
        unordered_map<char, vector<int>> char2pos;
        // 建立hashmap-数组的映射，里面存储了t字符串的下标志，使用数组是因为可能t字符串里面存在了重复的数字
        for (int i = 0; i < n; ++i)
            char2pos[t[i]].push_back(i);
        // 便利s字符串，查找每一个字符串对应的下标
        // 如果发现某一个字符没有找到，那么返回false
        // 如果发现某一个字符的index顺序，没有比之前的pre大的了，说明之前的顺序肯定有错误的地方，也返回false.
        for (char c : s) {
            auto it = upper_bound(char2pos[c].begin(), char2pos[c].end(), pre);
            if (it == char2pos[c].end())
                return false;
            pre = *it;
        }
        return true;
    }
};
// @lc code=end
