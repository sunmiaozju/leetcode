/*
 * @lc app=leetcode id=628 lang=cpp
 *
 * [628] Maximum Product of Three Numbers
 *
 * https://leetcode.com/problems/maximum-product-of-three-numbers/description/
 *
 * algorithms
 * Easy (46.54%)
 * Likes:    878
 * Dislikes: 312
 * Total Accepted:    94.5K
 * Total Submissions: 201.9K
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array, find three numbers whose product is maximum and
 * output the maximum product.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: 6
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4]
 * Output: 24
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The length of the given array will be in range [3,10^4] and all elements are
 * in the range [-1000, 1000].
 * Multiplication of any three numbers in the input won't exceed the range of
 * 32-bit signed integer.
 * 
 * 
 * 
 * 
 */

#include <algorithm>
#include <vector>

using namespace std;

using namespace std;

// @lc code=start
class Solution {
public:
    int maximumProduct(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int max1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
        int max2 = nums[0] * nums[1] * nums[n - 1];
        return max(max1, max2);
    }
};
// @lc code=end
