/*
 * @lc app=leetcode.cn id=730 lang=cpp
 *
 * [730] 统计不同回文子字符串
 *
 * https://leetcode-cn.com/problems/count-different-palindromic-subsequences/description/
 *
 * algorithms
 * Hard (45.24%)
 * Likes:    43
 * Dislikes: 0
 * Total Accepted:    954
 * Total Submissions: 2K
 * Testcase Example:  '"bccb"'
 *
 * 给定一个字符串 S，找出 S 中不同的非空回文子序列个数，并返回该数字与 10^9 + 7 的模。
 * 
 * 通过从 S 中删除 0 个或多个字符来获得子字符序列。
 * 
 * 如果一个字符序列与它反转后的字符序列一致，那么它是回文字符序列。
 * 
 * 如果对于某个  i，A_i != B_i，那么 A_1, A_2, ... 和 B_1, B_2, ... 这两个字符序列是不同的。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：
 * S = 'bccb'
 * 输出：6
 * 解释：
 * 6 个不同的非空回文子字符序列分别为：'b', 'c', 'bb', 'cc', 'bcb', 'bccb'。
 * 注意：'bcb' 虽然出现两次但仅计数一次。
 * 
 * 
 * 示例 2：
 * 
 * 输入：
 * S = 'abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba'
 * 输出：104860361
 * 解释：
 * 共有 3104860382 个不同的非空回文子字符序列，对 10^9 + 7 取模为 104860361。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 字符串 S 的长度将在[1, 1000]范围内。
 * 每个字符 S[i] 将会是集合 {'a', 'b', 'c', 'd'} 中的某一个。
 * 
 * 
 * 
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int countPalindromicSubsequences(string S)
    {
        int mod = 1e9 + 7;
        vector<vector<int>> dp(S.size(), vector<int>(S.size(), 0));
        for (int i = 0; i < S.size(); i++) {
            dp[i][i] = 1;
        }
        // 这里注意遍历的方式，确保当前遍历所需要依赖的情况都已经被处理过了
        //   b c c b
        // b 1 2 3 6
        // c 0 1 2 3
        // c 0 0 1 2
        // b 0 0 0 1
        // 我们就是从下三角的底部开始逐个向上遍历，因为需要依赖的情况都是当前情况的左边，下边和左下边。
        for (int i = S.size() - 2; i >= 0; i--) {
            for (int j = i + 1; j < S.size(); j++) {
                if (S[i] == S[j]) {
                    int left = i + 1, right = j - 1;
                    while (S[left] != S[i]) {
                        left++;
                    }
                    while (S[right] != S[i]) {
                        right--;
                    }
                    if (left > right) {
                        dp[i][j] = dp[i + 1][j - 1] * 2 + 2;
                    } else if (left == right) {
                        dp[i][j] = dp[i + 1][j - 1] * 2 + 1;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1] * 2 - dp[left + 1][right - 1];
                    }
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                }
                dp[i][j] = dp[i][j] < 0 ? dp[i][j] + mod : dp[i][j] % mod;
            }
        }
        return dp[0][S.size() - 1];
    }
};
// @lc code=end
