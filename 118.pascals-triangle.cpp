/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (47.79%)
 * Likes:    842
 * Dislikes: 84
 * Total Accepted:    286.3K
 * Total Submissions: 598K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> v_int;

class Solution {
public:
    vector<v_int> generate(int numRows)
    {

        // vector<vector<int>> ans;
        // if (numRows == 0) {
        //     return ans;
        // }
        // vector<int> items_prev;
        // items_prev.push_back(1);
        // ans.push_back(items_prev);

        // for (size_t i = 2; i <= numRows; i++) {
        //     vector<int> items;
        //     items.push_back(1);
        //     for (size_t j = 1; j < i - 1; j++) {
        //         items.push_back(items_prev[j - 1] + items_prev[j]);
        //     }
        //     items.push_back(1);
        //     ans.push_back(items);
        //     items_prev = items;
        // }
        // return ans;

        vector<int> items;
        vector<v_int> ans;
        for (int i = 0; i < numRows; i++) {
            items.push_back(1);
            for (int j = i - 1; j > 0; j--) {
                items[j] = items[j - 1] + items[j];
            }
            ans.push_back(items);
        }
        return ans;
    }
};

// int main(int argc, const char** argv)
// {
//     Solution s;
//     s.generate(5);
//     return 0;
// }
