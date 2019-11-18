/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.82%)
 * Likes:    6677
 * Dislikes: 392
 * Total Accepted:    1.1M
 * Total Submissions: 4M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        // unordered_map<char, int> myMap;
        // int ans = -1;
        // for (size_t i = 0; i < s.size(); i++) {
        //     if (myMap.find(s[i]) != myMap.end()) {
        //         ans = max(ans, int(myMap.size()));
        //         i = myMap[s[i]];
        //         myMap.clear();
        //     } else {
        //         myMap[s[i]] = i;
        //     }
        // }
        // return max(ans, int(myMap.size()));
        // unordered_map<char, int> myMap;
        // int slow = 0;
        // int ans = 0;
        // int i = 0;
        // for (; i < s.size(); ++i) {
        //     if (myMap.find(s[i]) != myMap.end() && myMap[s[i]] >= slow && myMap[s[i]] < i) {
        //         ans = max(ans, i - slow);
        //         slow = myMap[s[i]] + 1;
        //     }
        //     myMap[s[i]] = i;
        // }
        // return max(ans, i - slow);

        vector<int> v(128, -1);
        int start = -1, ans = 0, i = 0;
        for (; i < s.size(); i++) {
            if (v[s[i]] > start) {
                ans = max(ans, i - start - 1);
                start = v[s[i]];
            }
            v[s[i]] = i;
        }
        return max(ans, i - start - 1);
    }
};
// @lc code=end
