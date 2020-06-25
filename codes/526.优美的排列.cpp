/*
 * @lc app=leetcode.cn id=526 lang=cpp
 *
 * [526] 优美的排列
 *
 * https://leetcode-cn.com/problems/beautiful-arrangement/description/
 *
 * algorithms
 * Medium (59.12%)
 * Likes:    67
 * Dislikes: 0
 * Total Accepted:    4.9K
 * Total Submissions: 7.9K
 * Testcase Example:  '2'
 *
 * 假设有从 1 到 N 的 N 个整数，如果从这 N 个数字中成功构造出一个数组，使得数组的第 i 位 (1 <= i <= N)
 * 满足如下两个条件中的一个，我们就称这个数组为一个优美的排列。条件：
 * 
 * 
 * 第 i 位的数字能被 i 整除
 * i 能被第 i 位上的数字整除
 * 
 * 
 * 现在给定一个整数 N，请问可以构造多少个优美的排列？
 * 
 * 示例1:
 * 
 * 
 * 输入: 2
 * 输出: 2
 * 解释: 
 * 
 * 第 1 个优美的排列是 [1, 2]:
 * ⁠ 第 1 个位置（i=1）上的数字是1，1能被 i（i=1）整除
 * ⁠ 第 2 个位置（i=2）上的数字是2，2能被 i（i=2）整除
 * 
 * 第 2 个优美的排列是 [2, 1]:
 * ⁠ 第 1 个位置（i=1）上的数字是2，2能被 i（i=1）整除
 * ⁠ 第 2 个位置（i=2）上的数字是1，i（i=2）能被 1 整除
 * 
 * 
 * 说明:
 * 
 * 
 * N 是一个正整数，并且不会超过15。
 * 
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int countArrangement(int N)
    {
        int ans = 0;
        vector<bool> visited(N + 1, false);
        help(visited, N, 1, ans);
        return ans;
    }

    void help(vector<bool>& visited, int N, int pos, int& ans)
    {
        if (pos > N) {
            ans++;
            return;
        }

        for (int i = 1; i <= N; i++) {
            if (!visited[i] && (i % pos == 0 || pos % i == 0)) {
                visited[i] = true;
                help(visited, N, pos + 1, ans);
                visited[i] = false;
            }
        }
    }
};
// @lc code=end
