/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode-cn.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (43.68%)
 * Likes:    241
 * Dislikes: 0
 * Total Accepted:    29K
 * Total Submissions: 66K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
 * 个数字。滑动窗口每次只向右移动一位。
 * 
 * 返回滑动窗口中的最大值。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
 * 输出: [3,3,5,5,6,7] 
 * 解释: 
 * 
 * ⁠ 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * 
 * 提示：
 * 
 * 你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。
 * 
 * 
 * 
 * 进阶：
 * 
 * 你能在线性时间复杂度内解决此题吗？
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        if (nums.empty()) {
            return {};
        }
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; i++) {
            q.push(pair<int, int>(nums[i], i));
        }
        int right = k - 1;
        vector<int> ans;
        while (true) {
            while (!q.empty() && q.top().second < right - k + 1) {
                q.pop();
            }
            ans.push_back(q.top().first);
            right++;
            if (right == nums.size()) {
                break;
            }
            q.push(pair<int, int>(nums[right], right));
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k)
//     {
//         vector<int> res;
//         multiset<int> st;
//         for (int i = 0; i < nums.size(); ++i) {
//             if (i >= k)
//                 st.erase(st.find(nums[i - k]));
//             st.insert(nums[i]);
//             if (i >= k - 1)
//                 res.push_back(*st.rbegin());
//         }
//         return res;
//     }
// };
// @lc code=end
