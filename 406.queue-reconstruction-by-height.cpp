/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 *
 * https://leetcode.com/problems/queue-reconstruction-by-height/description/
 *
 * algorithms
 * Medium (60.87%)
 * Likes:    1904
 * Dislikes: 219
 * Total Accepted:    95.7K
 * Total Submissions: 155.4K
 * Testcase Example:  '[[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]'
 *
 * Suppose you have a random list of people standing in a queue. Each person is
 * described by a pair of integers (h, k), where h is the height of the person
 * and k is the number of people in front of this person who have a height
 * greater than or equal to h. Write an algorithm to reconstruct the queue.
 * 
 * Note:
 * The number of people is less than 1,100.
 * 
 * 
 * Example
 * 
 * 
 * Input:
 * [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 * 
 * Output:
 * [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 * 
 * 
 * 
 * 
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        // sort(people.begin(), people.end(), [](auto& a, auto& b) {
        //     return a[0] > b[0] || a[0] == b[0] && a[1] <= b[1];
        // });
        // for (size_t i = 0; i < people.size(); i++) {
        //     if (people[i][1] != i) {
        //         auto p = people[i];
        //         people.erase(people.begin() + i);
        //         people.insert(people.begin() + p[1], p);
        //     }
        // }
        // return people;
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        vector<vector<int>> res;
        for (auto a : people) {
            res.insert(res.begin() + a[1], a);
        }
        return res;
    }
};
// @lc code=end
