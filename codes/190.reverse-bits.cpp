/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 *
 * https://leetcode.com/problems/reverse-bits/description/
 *
 * algorithms
 * Easy (32.80%)
 * Likes:    638
 * Dislikes: 224
 * Total Accepted:    199K
 * Total Submissions: 604.8K
 * Testcase Example:  '00000010100101000001111010011100'
 *
 * Reverse bits of a given 32 bits unsigned integer.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 00000010100101000001111010011100
 * Output: 00111001011110000010100101000000
 * Explanation: The input binary string 00000010100101000001111010011100
 * represents the unsigned integer 43261596, so return 964176192 which its
 * binary representation is 00111001011110000010100101000000.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 11111111111111111111111111111101
 * Output: 10111111111111111111111111111111
 * Explanation: The input binary string 11111111111111111111111111111101
 * represents the unsigned integer 4294967293, so return 3221225471 which its
 * binary representation is 10101111110010110010011101101001.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * Note that in some languages such as Java, there is no unsigned integer type.
 * In this case, both input and output will be given as signed integer type and
 * should not affect your implementation, as the internal binary representation
 * of the integer is the same whether it is signed or unsigned.
 * In Java, the compiler represents the signed integers using 2's complement
 * notation. Therefore, in Example 2 above the input represents the signed
 * integer -3 and the output represents the signed integer -1073741825.
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * If this function is called many times, how would you optimize it?
 * 
 */

// @lc code=start

#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n)
    {
        // // uint32_t ans = 0;
        // // int nums = 0;
        // // while (nums < 32) {
        // //     int item = n % 2;
        // //     ans = ans * 2 + item;
        // //     n /= 2;
        // //     nums++;
        // // }
        // // return ans;

        // int table[16] = { 0,
        //     8,
        //     4,
        //     12,
        //     2,
        //     10,
        //     6,
        //     14,
        //     1,
        //     9,
        //     5,
        //     13,
        //     3,
        //     11,
        //     7,
        //     15 };

        // uint32_t ans = 0;
        // uint32_t msk = 0x000f;
        // for (size_t i = 0; i < 8; i++) {
        //     ans = ans << 4;
        //     int num = n & msk;
        //     ans |= table[num];
        //     n = n >> 4;
        // }
        // return ans;

        uint32_t ans = 0;
        uint32_t mask = 1;
        int count = 32;
        while (count--) {
            ans = ans << 1;
            if (mask & n) {
                ans += 1;
            }
            n = n >> 1;
        }
        return ans;
    }
};
// @lc code=end
