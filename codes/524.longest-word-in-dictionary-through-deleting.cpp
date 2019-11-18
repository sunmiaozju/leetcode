/*
 * @lc app=leetcode id=524 lang=cpp
 *
 * [524] Longest Word in Dictionary through Deleting
 *
 * https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/
 *
 * algorithms
 * Medium (46.59%)
 * Likes:    401
 * Dislikes: 197
 * Total Accepted:    52.8K
 * Total Submissions: 112.4K
 * Testcase Example:  '"abpcplea"\n["ale","apple","monkey","plea"]'
 *
 * 
 * Given a string and a string dictionary, find the longest string in the
 * dictionary that can be formed by deleting some characters of the given
 * string. If there are more than one possible results, return the longest word
 * with the smallest lexicographical order. If there is no possible result,
 * return the empty string.
 * 
 * Example 1:
 * 
 * Input:
 * s = "abpcplea", d = ["ale","apple","monkey","plea"]
 * 
 * Output: 
 * "apple"
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * s = "abpcplea", d = ["a","b","c"]
 * 
 * Output: 
 * "a"
 * 
 * 
 * 
 * Note:
 * 
 * All the strings in the input will only contain lower-case letters.
 * The size of the dictionary won't exceed 1,000.
 * The length of all the strings in the input won't exceed 1,000.
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
    string findLongestWord(string s, vector<string>& d)
    {
        string ans;
        for (size_t i = 0; i < d.size(); i++) {
            if (ans.size() > d[i].size() || (ans.size() == d[i].size() && ans <= d[i])) {
                continue;
            }
            int left = 0, right = 0;
            while (right < d[i].size() && left < s.size()) {
                if (s[left] == d[i][right]) {
                    right++;
                }
                left++;
            }
            if (right == d[i].size()) {
                ans = d[i];
            }
        }
        return ans;
    }
};
// @lc code=end
