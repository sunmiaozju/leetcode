/*
 * @lc app=leetcode.cn id=1039 lang=cpp
 *
 * [1039] 多边形三角剖分的最低得分
 *
 * https://leetcode-cn.com/problems/minimum-score-triangulation-of-polygon/description/
 *
 * algorithms
 * Medium (47.16%)
 * Likes:    35
 * Dislikes: 0
 * Total Accepted:    1.7K
 * Total Submissions: 3.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定 N，想象一个凸 N 边多边形，其顶点按顺时针顺序依次标记为 A[0], A[i], ..., A[N-1]。
 * 
 * 假设您将多边形剖分为 N-2 个三角形。对于每个三角形，该三角形的值是顶点标记的乘积，三角剖分的分数是进行三角剖分后所有 N-2 个三角形的值之和。
 * 
 * 返回多边形进行三角剖分后可以得到的最低分。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[1,2,3]
 * 输出：6
 * 解释：多边形已经三角化，唯一三角形的分数为 6。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：[3,7,4,5]
 * 输出：144
 * 解释：有两种三角剖分，可能得分分别为：3*7*5 + 4*5*7 = 245，或 3*4*5 + 3*4*7 = 144。最低分数为 144。
 * 
 * 
 * 示例 3：
 * 
 * 输入：[1,3,1,4,1,5]
 * 输出：13
 * 解释：最低分数三角剖分的得分情况为 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= A.length <= 50
 * 1 <= A[i] <= 100
 * 
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int minScoreTriangulation(vector<int>& A)
    {
        int n = A.size();
        vector<vector<int>> dp(A.size(), vector<int>(A.size(), INT_MAX));

        // 如果两个点相邻，那么不会构成三角形。
        for (int i = 0; i < A.size(); i++) {
            dp[i][(i + 1) % n] = 0;
            dp[i][i] = 0;
        }

        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n; i++) {
                int j = (i + len - 1) % n;
                for (int k = (i + 1) % n; k < j; k = (k + 1) % n) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + A[i] * A[k] * A[j] + dp[k][j]);
                }
            }
        }

        return dp[0][n - 1];
    }
};
// @lc code=end
