/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (41.51%)
 * Likes:    874
 * Dislikes: 6775
 * Total Accepted:    308.5K
 * Total Submissions: 743.1K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the n^th term of the
 * count-and-say sequence.
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "1211"
 * 
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n)
    {
        string pre = "";
        string ans = "1";
        for (size_t i = 1; i < n; i++) {
            pre = ans;
            ans = "";
            char item = pre[0];
            int count = 0;
            for (size_t j = 0; j < pre.size(); j++) {
                if (pre[j] == item) {
                    count++;
                } else {
                    ans.push_back('0' + count);
                    ans.push_back(item);
                    count = 1;
                    item = pre[j];
                }
            }
            ans.push_back('0' + count);
            ans.push_back(item);
        }
        int kk;
        return ans;
    }
};

// int main(int argc, const char** argv)
// {
//     Solution ss;
//     cout << ss.countAndSay(5) << endl;
//     return 0;
// }
