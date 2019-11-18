/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 *
 * https://leetcode.com/problems/partition-labels/description/
 *
 * algorithms
 * Medium (72.09%)
 * Likes:    1375
 * Dislikes: 76
 * Total Accepted:    77K
 * Total Submissions: 105.7K
 * Testcase Example:  '"ababcbacadefegdehijhklij"'
 *
 * 
 * A string S of lowercase letters is given.  We want to partition this string
 * into as many parts as possible so that each letter appears in at most one
 * part, and return a list of integers representing the size of these parts.
 * 
 * 
 * Example 1:
 * 
 * Input: S = "ababcbacadefegdehijhklij"
 * Output: [9,7,8]
 * Explanation:
 * The partition is "ababcbaca", "defegde", "hijhklij".
 * This is a partition so that each letter appears in at most one part.
 * A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it
 * splits S into less parts.
 * 
 * 
 * 
 * Note:
 * S will have length in range [1, 500].
 * S will consist of lowercase letters ('a' to 'z') only.
 * 
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string S)
    {
        // int edge = 0;
        // vector<int> ans;
        // unordered_map<char, pair<int, int>>
        //     myMap;
        // for (size_t i = 0; i < S.size(); i++) {
        //     myMap[S[i]].first++;
        // }
        // int count = 0;
        // int last = 0;
        // for (size_t i = 0; i < S.size(); i++) {
        //     if (myMap[S[i]].second++ == 0) {
        //         count++;
        //     }
        //     if (myMap[S[i]].second == myMap[S[i]].first) {
        //         count--;
        //     }

        //     if (count == 0) {
        //         ans.push_back(i + 1 - last);
        //         last = i + 1;
        //     }
        // }
        // return ans;

        unordered_map<int, int> myMap;
        for (int i = 0; i < S.size(); i++) {
            myMap[S[i]] = i;
        }
        vector<int> ans;
        int edge = 0, last = 0;
        for (int i = 0; i < S.size(); i++) {
            edge = max(edge, myMap[S[i]]);
            if (i == edge) {
                ans.push_back(i + 1 - last);
                last = i + 1;
            }
        }
        return ans;
    }
};
// @lc code=end
