/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (33.15%)
 * Likes:    1245
 * Dislikes: 3756
 * Total Accepted:    377.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 */

#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows)
    {
        // if (numRows == 1) {
        //     return s;
        // }
        // string buf[numRows];
        // string ans;
        // int index = 0;
        // bool turn = false;
        // for (size_t i = 0; i < s.length(); i++) {
        //     buf[index].push_back(s[i]);
        //     index = turn ? index + 1 : index - 1;
        //     if (index == numRows) {
        //         turn = !turn;
        //         index = numRows - 2;
        //     } else if (index == -1) {
        //         turn = !turn;
        //         index = 1;
        //     }
        // }
        // for (size_t i = 0; i < numRows; ++i) {
        //     ans += buf[i];
        // }
        // return ans;

        if (numRows == 1) {
            return s;
        }
        string ans = "";
        int cycle = 2 * numRows - 2;
        for (size_t i = 0; i < numRows; i++) {
            for (size_t j = i; j < s.length(); j += cycle) {
                ans.push_back(s[j]);
                int secondj = j + cycle - 2 * (j % cycle);
                if (i != 0 && i != numRows - 1 && secondj < s.length()) {
                    ans.push_back(s[secondj]);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
