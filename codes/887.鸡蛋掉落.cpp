/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 *
 * https://leetcode-cn.com/problems/super-egg-drop/description/
 *
 * algorithms
 * Hard (20.68%)
 * Likes:    350了发帖
 * Dislikes: 0
 * Total Accepted:    20.9K
 * Total Submissions: 73.8K
 * Testcase Example:  '1\n2'
 *
 * 你将获得 K 个鸡蛋，并可以使用一栋从 1 到 N  共有 N 层楼的建筑。
 * 
 * 每个蛋的功能都是一样的，如果一个蛋碎了，你就不能再把它掉下去。
 * 
 * 你知道存在楼层 F ，满足 0 <= F <= N 任何从高于 F 的楼层落下的鸡蛋都会碎，从 F 楼层或比它低的楼层落下的鸡蛋都不会破。
 * 
 * 每次移动，你可以取一个鸡蛋（如果你有完整的鸡蛋）并把它从任一楼层 X 扔下（满足 1 <= X <= N）。
 * 
 * 你的目标是确切地知道 F 的值是多少。
 * 
 * 无论 F 的初始值如何，你确定 F 的值的最小移动次数是多少？
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：K = 1, N = 2
 * 输出：2
 * 解释：
 * 鸡蛋从 1 楼掉落。如果它碎了，我们肯定知道 F = 0 。
 * 否则，鸡蛋从 2 楼掉落。如果它碎了，我们肯定知道 F = 1 。
 * 如果它没碎，那么我们肯定知道 F = 2 。
 * 因此，在最坏的情况下我们需要移动 2 次以确定 F 是多少。
 * 
 * 
 * 示例 2：
 * 
 * 输入：K = 2, N = 6
 * 输出：3
 * 
 * 
 * 示例 3：
 * 
 * 输入：K = 3, N = 14
 * 输出：4
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= K <= 100
 * 1 <= N <= 10000
 * 
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int superEggDrop(int K, int N)
    {
        vector<vector<int>> dp(K + 1, vector<int>(N + 1, INT_MAX));

        // 0个鸡蛋全部为0
        for (int i = 0; i <= N; i++) {
            dp[0][i] = 0;
        }

        // 楼层为0全部为0
        for (int i = 0; i <= K; i++) {
            dp[i][0] = 0;
        }

        // 1个鸡蛋特殊处理
        for (int i = 1; i <= N; i++) {
            dp[1][i] = i;
        }

        // 1层楼的情况
        for (int i = 1; i <= K; i++) {
            dp[i][1] = 1;
        }

        for (int i = 2; i <= K; i++) {
            for (int j = 2; j <= N; j++) {
                int left = 1;
                int right = j;
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (dp[i - 1][mid - 1] <= dp[i][j - mid]) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                int index = left - 1;
                dp[i][j] = max(dp[i - 1][index - 1], dp[i][j - index]) + 1;
            }
        }
        return dp[K][N];
    }
};
// @lc code=end
