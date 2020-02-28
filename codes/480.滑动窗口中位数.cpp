/*
 * @lc app=leetcode.cn id=480 lang=cpp
 *
 * [480] 滑动窗口中位数
 *
 * https://leetcode-cn.com/problems/sliding-window-median/description/
 *
 * algorithms
 * Hard (32.47%)
 * Likes:    47
 * Dislikes: 0
 * Total Accepted:    2.5K
 * Total Submissions: 7.6K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 中位数是有序序列最中间的那个数。如果序列的大小是偶数，则没有最中间的数；此时中位数是最中间的两个数的平均数。
 * 
 * 例如：
 * 
 * [2,3,4]，中位数是 3
 * 
 * [2,3]，中位数是 (2 + 3) / 2 = 2.5
 * 
 * 给出一个数组 nums，有一个大小为 k 的窗口从最左端滑动到最右端。窗口中有 k 个数，每次窗口向右移动 1
 * 位。你的任务是找出每次窗口移动后得到的新窗口中元素的中位数，并输出由它们组成的数组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给出 nums = [1,3,-1,-3,5,3,6,7]，以及 k = 3。
 * 
 * 窗口位置                      中位数
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       1
 * ⁠1 [3  -1  -3] 5  3  6  7       -1
 * ⁠1  3 [-1  -3  5] 3  6  7       -1
 * ⁠1  3  -1 [-3  5  3] 6  7       3
 * ⁠1  3  -1  -3 [5  3  6] 7       5
 * ⁠1  3  -1  -3  5 [3  6  7]      6
 * 
 * 
 * 因此，返回该滑动窗口的中位数数组 [1,-1,-1,3,5,6]。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 你可以假设 k 始终有效，即：k 始终小于输入的非空数组的元素个数。
 * 与真实值误差在 10 ^ -5 以内的答案将被视作正确答案。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k)
    {
        multiset<int> small, large;

        vector<double> ans;

        for (int i = 0;; i++) {
            if (i >= k) {
                double mid;
                if (small.size() == large.size()) {
                    mid = calmid(*(--small.end()), *large.begin());
                } else {
                    mid = *(--small.end());
                }
                ans.push_back(mid);

                if (i == nums.size()) {
                    return ans;
                }

                if (small.count(nums[i - k])) {
                    small.erase(small.find(nums[i - k]));
                } else if (large.count(nums[i - k])) {
                    large.erase(large.find(nums[i - k]));
                }
            }

            if (small.empty()) {
                small.insert(nums[i]);
                continue;
            } else if (large.empty()) {
                if (nums[i] <= *(--small.end())) {
                    small.insert(nums[i]);
                } else {
                    large.insert(nums[i]);
                }
            } else if (nums[i] <= calmid(*(--small.end()), *large.begin())) {
                small.insert(nums[i]);
            } else {
                large.insert(nums[i]);
            }

            while (small.size() >= large.size() + 2) {
                large.insert(*(--small.end()));
                small.erase(--small.end());
            }

            while (large.size() >= small.size() + 1) {
                small.insert(*large.begin());
                large.erase(large.begin());
            }
        }
        return ans;
    }
    double calmid(int a, int b)
    {
        if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
            return a + (b - a) / 2.0;
        } else {
            return (a + b) / 2.0;
        }
    }
};
// @lc code=end
