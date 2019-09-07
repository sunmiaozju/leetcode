/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (34.02%)
 * Likes:    1565
 * Dislikes: 1431
 * Total Accepted:    525.7K
 * Total Submissions: 1.5M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {

public:
    // Solution() {}
    // ~Solution() {}
    string longestCommonPrefix(vector<string>& strs)
    {
        // if (strs.size() == 0) {
        //     return "";
        // }

        // string ans;
        // int j = 0;
        // int min = INT_MAX;

        // for (size_t i = 0; i < strs.size(); i++) {
        //     if (min > strs[i].size()) {
        //         min = strs[i].size();
        //     }
        // }

        // while (j < min) {
        //     size_t i = 0;
        //     char item = strs[i][j];

        //     for (; i < strs.size(); i++) {
        //         if (strs[i][j] != item) {
        //             return ans;
        //         }
        //     }
        //     ans.push_back(item);
        //     j++;
        // }

        // return ans;

        if (strs.size() == 0) {
            return "";
        }
        int length = strs.size();
        sort(strs.begin(), strs.end());
        int min_num = min(strs[0].size(), strs[length - 1].size());
        size_t i = 0;
        for (; i < min_num; i++) {
            if (strs[0][i] != strs[length - 1][i]) {
                break;
            }
        }
        return strs[0].substr(0, i);
    }
};

// int main(int argc, const char** argv)
// {
//     Solution ss;
//     vector<string> vec;
//     vec.push_back("flower");
//     vec.push_back("flowe");
//     vec.push_back("flow");

//     ss.longestCommonPrefix(vec);
//     return 0;
// }
