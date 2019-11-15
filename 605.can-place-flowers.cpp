/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 *
 * https://leetcode.com/problems/can-place-flowers/description/
 *
 * algorithms
 * Easy (31.28%)
 * Likes:    571
 * Dislikes: 297
 * Total Accepted:    76.6K
 * Total Submissions: 243.6K
 * Testcase Example:  '[1,0,0,0,1]\n1'
 *
 * Suppose you have a long flowerbed in which some of the plots are planted and
 * some are not. However, flowers cannot be planted in adjacent plots - they
 * would compete for water and both would die.
 * 
 * Given a flowerbed (represented as an array containing 0 and 1, where 0 means
 * empty and 1 means not empty), and a number n, return if n new flowers can be
 * planted in it without violating the no-adjacent-flowers rule.
 * 
 * Example 1:
 * 
 * Input: flowerbed = [1,0,0,0,1], n = 1
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: flowerbed = [1,0,0,0,1], n = 2
 * Output: False
 * 
 * 
 * 
 * Note:
 * 
 * The input array won't violate no-adjacent-flowers rule.
 * The input array size is in the range of [1, 20000].
 * n is a non-negative integer which won't exceed the input array size.
 * 
 * 
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        int count = 1, all = 0;
        for (size_t i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0) {
                count++;
            } else {
                all += (count - 1) / 2;
                count = 0;
            }
        }
        if (count) {
            all += count / 2;
        }
        return all >= n;
    }
};
// @lc code=end
