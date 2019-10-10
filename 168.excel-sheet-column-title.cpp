/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 *
 * https://leetcode.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (29.51%)
 * Likes:    824
 * Dislikes: 166
 * Total Accepted:    184.4K
 * Total Submissions: 623.9K
 * Testcase Example:  '1'
 *
 * Given a positive integer, return its corresponding column title as appear in
 * an Excel sheet.
 * 
 * For example:
 * 
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * ⁠   ...
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "A"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 28
 * Output: "AB"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 701
 * Output: "ZY"
 * 
 */
#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n)
    {
        //递归解法
        // string ans;
        // if (n < 27) {
        //     char c = 'A' + n - 1;
        //     return ans + c;
        // } else {
        //     int front = n / 26;
        //     int back = n % 26;
        //     if (back == 0) {
        //         back = 26;
        //         front--;
        //     }
        //     string front_s = convertToTitle(front);
        //     string back_s = convertToTitle(back);
        //     return front_s + back_s;
        // }

        // 非递归解法
        string ans;
        while (n > 0) {
            ans = char('A' + (n - 1) % 26) + ans;
            n = (n - 1) / 26;
        }
        return ans;
    }
};
