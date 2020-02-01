/*
 * @lc app=leetcode id=462 lang=cpp
 *
 * [462] Minimum Moves to Equal Array Elements II
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/
 *
 * algorithms
 * Medium (52.73%)
 * Likes:    427
 * Dislikes: 39
 * Total Accepted:    41K
 * Total Submissions: 77.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty integer array, find the minimum number of moves required
 * to make all array elements equal, where a move is incrementing a selected
 * element by 1 or decrementing a selected element by 1.
 * 
 * You may assume the array's length is at most 10,000.
 * 
 * Example:
 * 
 * Input:
 * [1,2,3]
 * 
 * Output:
 * 2
 * 
 * Explanation:
 * Only two moves are needed (remember each move increments or decrements one
 * element):
 * 
 * [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 * 
 * 
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minMoves2(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        long ans = 0;
        while (i < j) {
            ans = ans + nums[j--] - nums[i++];
        }
        return ans;
    }
};
// @lc code=end
