/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (53.41%)
 * Likes:    881
 * Dislikes: 117
 * Total Accepted:    408.9K
 * Total Submissions: 759.7K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 * 
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t)
    {
        // if (s.size() != t.size()) {
        //     return false;
        // }
        // unordered_map<char, int> myMap;
        // for (size_t i = 0; i < s.size(); i++) {
        //     if (myMap.find(s[i]) == myMap.end()) {
        //         myMap[s[i]] = 1;
        //     } else {
        //         myMap[s[i]]++;
        //     }
        //     if (myMap.find(t[i]) == myMap.end()) {
        //         myMap[t[i]] = -1;
        //     } else {
        //         myMap[t[i]]--;
        //     }
        //     // std::cout << "i: " << i << " s: " << myMap[s[i]] << " " << s[i] << std::endl;
        //     // std::cout << "i: " << i << " t: " << myMap[t[i]] << " " << t[i] << std::endl;
        //     // cout << "--------" << myMap[s[i]] << "--------" << endl;
        //     if (myMap[s[i]] == 0) {
        //         myMap.erase(s[i]);
        //         // std::cout << "i: " << i << " erase  s: " << s[i] << std::endl;
        //     }
        //     if (myMap[t[i]] == 0) {
        //         myMap.erase(t[i]);
        //         // std::cout << "i: " << i << " erase  t: " << t[i] << std::endl;
        //     }
        // }
        // // cout << myMap.size() << endl;
        // return myMap.empty();

        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s == t;

        if (s.size() != t.size()) {
            return false;
        }
        int table[128] = { 0 };
        for (size_t i = 0; i < s.size(); ++i) {
            table[s[i]]++;
            table[t[i]]--;
        }
        for (size_t i = 0; i < 128; i++) {
            if (table[i]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
