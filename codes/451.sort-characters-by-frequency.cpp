/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 *
 * https://leetcode.com/problems/sort-characters-by-frequency/description/
 *
 * algorithms
 * Medium (57.19%)
 * Likes:    887
 * Dislikes: 81
 * Total Accepted:    115.1K
 * Total Submissions: 199.2K
 * Testcase Example:  '"tree"'
 *
 * Given a string, sort it in decreasing order based on the frequency of
 * characters.0
 * 
 * Example 1:
 * 
 * Input:
 * "tree"
 * 
 * Output:
 * "eert"
 * 
 * Explanation:
 * 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
 * answer.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * "cccaaa"
 * 
 * Output:
 * "cccaaa"
 * 
 * Explanation:
 * Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 * Note that "cacaca" is incorrect, as the same characters must be together.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input:
 * "Aabb"
 * 
 * Output:
 * "bbAa"
 * 
 * Explanation:
 * "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string frequencySort(string s)
    {
        string ans;
        unordered_map<char, int> myMap;
        for (auto item : s) {
            myMap[item]++;
        }
        vector<string> bucket(s.size() + 1);
        for (auto it = myMap.begin(); it != myMap.end(); it++) {
            bucket[it->second].push_back(it->first);
        }
        for (int i = bucket.size() - 1; i >= 0; i--) {
            for (size_t j = 0; j < bucket[i].size(); j++) {
                for (size_t k = 0; k < i; k++) {
                    ans.push_back(bucket[i][j]);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
