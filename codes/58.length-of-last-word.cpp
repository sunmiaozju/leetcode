/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.29%)
 * Likes:    428
 * Dislikes: 1773
 * Total Accepted:    293K
 * Total Submissions: 907.4K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 * 
 * 
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s)
    {
        // int put_into_consider_size = s.size();
        // int j = s.size() - 1;
        // while (j >= 0 && s[j--] == ' ') {
        //     put_into_consider_size--;
        // }

        // int num = 0;
        // for (size_t i = 0; i < put_into_consider_size; i++) {
        //     if (s[i] != ' ') {
        //         num++;
        //     } else {
        //         num = 0;
        //     }
        // }
        // return num;

        int sum = 0, tail = s.size() - 1;
        while (tail >= 0 && s[tail] == ' ') {
            tail--;
        }
        while (tail >= 0 && s[tail] != ' ') {
            tail--;
            sum++;
        }
        return sum;
    }
};
