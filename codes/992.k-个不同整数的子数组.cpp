/*
 * @lc app=leetcode.cn id=992 lang=cpp
 *
 * [992] K 个不同整数的子数组
 *
 * https://leetcode-cn.com/problems/subarrays-with-k-different-integers/description/
 *
 * algorithms
 * Hard (24.74%)
 * Likes:    49
 * Dislikes: 0
 * Total Accepted:    2.5K
 * Total Submissions: 9.8K
 * Testcase Example:  '[1,2,1,2,3]\n2'
 *
 * 给定一个正整数数组 A，如果 A 的某个子数组中不同整数的个数恰好为 K，则称 A 的这个连续、不一定独立的子数组为好子数组。
 * 
 * （例如，[1,2,3,1,2] 中有 3 个不同的整数：1，2，以及 3。）
 * 
 * 返回 A 中好子数组的数目。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输出：A = [1,2,1,2,3], K = 2
 * 输入：7
 * 解释：恰好由 2 个不同整数组成的子数组：[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2],
 * [1,2,1,2].
 * 
 * 
 * 示例 2：
 * 
 * 输入：A = [1,2,1,3,4], K = 3
 * 输出：3
 * 解释：恰好由 3 个不同整数组成的子数组：[1,2,1,3], [2,1,3], [1,3,4].
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 20000
 * 1 <= A[i] <= A.length
 * 1 <= K <= A.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K)
    {
        int left = 0, right = 0;
        int mem[A.size() + 1] = { 0 };
        int ans = 0, cnt = 0;
        for (int i = 0; i < A.size(); i++) {
            if (mem[A[i]]++ == 0) {
                cnt++;
            }
            while (cnt > K) {
                if (--mem[A[left++]] == 0) {
                    cnt--;
                }
            }
            if (cnt == K) {
                for (int j = left; j <= i; j++) {
                    ans++;
                    if (--mem[A[j]] == 0) {
                        for (int k = j; k >= left; k--) {
                            mem[A[k]]++;
                        }
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
