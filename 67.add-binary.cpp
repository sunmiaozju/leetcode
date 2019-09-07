/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (40.23%)
 * Likes:    1127
 * Dislikes: 214
 * Total Accepted:    333.4K
 * Total Submissions: 826.3K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 orÂ 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b)
    {
        // string& ans = a.size() > b.size() ? a : b;
        // int num = 0;
        // bool up = false;
        // int cur = ans.size() - 1;

        // while (num <= min(a.size(), b.size()) - 1) {
        //     char a_item = a[a.size() - 1 - num];
        //     char b_item = b[b.size() - 1 - num];
        //     if (a_item == '0' && b_item == '0') {
        //         ans[cur] = up ? '1' : '0';
        //         up = false;
        //     } else if (a_item == '1' && b_item == '1') {
        //         ans[cur] = up ? '1' : '0';
        //         up = true;
        //     } else {
        //         ans[cur] = up ? '0' : '1';
        //     }
        //     num++;
        //     cur--;
        // }
        // while (cur >= 0) {
        //     if (ans[cur] == '0') {
        //         ans[cur] = up ? '1' : '0';
        //         up = false;
        //     } else {
        //         ans[cur] = up ? '0' : '1';
        //     }
        //     cur--;
        // }
        // if (up) {
        //     ans.insert(ans.begin(), '1');
        // }
        // return ans;

        if (a.size() < b.size()) {
            swap(a, b);
        }

        int m = a.size() - 1, n = b.size() - 1;
        while (m >= 0) {
            if (n >= 0) {
                b[n] &= 1;
                a[m] += b[n];
            }
            if (a[m] > '1') {
                a[m] -= 2;
                if (m == 0) {
                    a = '1' + a;
                } else {
                    a[m - 1]++;
                }
            }
            m--;
            n--;
        }
        return a;
    }
};
