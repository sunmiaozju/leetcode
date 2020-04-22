/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 *
 * https://leetcode-cn.com/problems/min-cost-climbing-stairs/description/
 *
 * algorithms
 * Easy (46.59%)
 * Likes:    258
 * Dislikes: 0
 * Total Accepted:    27.6K
 * Total Submissions: 58.1K
 * Testcase Example:  '[0,0,0,0]'
 *
 * 数组的每个索引做为一个阶梯，第 i个阶梯对应着一个非负数的体力花费值 cost[i](索引从0开始)。
 * 
 * 每当你爬上一个阶梯你都要花费对应的体力花费值，然后你可以选择继续爬一个阶梯或者爬两个阶梯。
 * 
 * 您需要找到达到楼层顶部的最低花费。在开始时，你可以选择从索引为 0 或 1 的元素作为初始阶梯。
 * 
 * 示例 1:
 * 
 * 
 * 输入: cost = [10, 15, 20]
 * 输出: 15
 * 解释: 最低花费是从cost[1]开始，然后走两步即可到阶梯顶，一共花费15。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
 * 输出: 6
 * 解释: 最低花费方式是从cost[0]开始，逐个经过那些1，跳过cost[3]，一共花费6。
 * 
 * 
 * 注意：
 * 
 * 
 * cost 的长度将会在 [2, 1000]。
 * 每一个 cost[i] 将会是一个Integer类型，范围为 [0, 999]。
 * 
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        vector<int> dp(cost.size(), 0);
        if (cost.size() == 0 || cost.size() == 1) {
            return 0;
        } else if (cost.size() == 2) {
            return min(cost[0], cost[1]);
        }

        int pre_pre = cost[0];
        int pre = cost[1];
        int num = 0;

        for (int i = 2; i < cost.size(); i++) {
            num = min(pre_pre, pre) + cost[i];
            pre_pre = pre;
            pre = num;
        }

        return min(pre_pre, pre);
    }
};
// @lc code=end
