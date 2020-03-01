/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (48.47%)
 * Likes:    880
 * Dislikes: 0
 * Total Accepted:    56.7K
 * Total Submissions: 116K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢
 * Marcos 贡献此图。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出: 6
 * 
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height)
    {
        int maxh = INT_MIN, maxindex = -1;
        ;
        for (int i = 0; i < height.size(); i++) {
            if (maxh < height[i]) {
                maxh = height[i];
                maxindex = i;
            }
        }

        int ans = 0, left = 0, right = height.size() - 1;
        int cur = 0;
        while (cur < maxindex) {
            if (height[cur] < height[left]) {
                ans += height[left] - height[cur];
            } else {
                left = cur;
            }
            cur++;
        }

        cur = height.size() - 1;
        while (cur > maxindex) {
            if (height[cur] < height[right]) {
                ans += height[right] - height[cur];
            } else {
                right = cur;
            }
            cur--;
        }

        return ans;
    }
};

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int left = 0, right = height.size()-1;
//         int ans = 0;
//         int l = 0, r = height.size()-1;
//         while(l < r){
//             if(height[left] <= height[right]){
//                 l++;
//                 while(l < right){
//                     if(height[l] < height[left]){
//                         ans += height[left] - height[l];
//                         l++;
//                     }else{
//                         left = l;
//                         break;
//                     }
//                 }
//             }else{
//                 r--;;
//                 while(r > left){
//                     if(height[r] < height[right]){
//                         ans += height[right] - height[r];
//                         r--;
//                     }else{
//                         right = r;
//                         break;
//                     }

//                 }
//             }
//         }
//         return ans;
//     }
// };
// @lc code=end
