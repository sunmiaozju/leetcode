/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 *
 * https://leetcode.com/problems/different-ways-to-add-parentheses/description/
 *
 * algorithms
 * Medium (51.47%)
 * Likes:    1212
 * Dislikes: 61
 * Total Accepted:    85.8K
 * Total Submissions: 164K
 * Testcase Example:  '"2-1-1"'
 *
 * Given a string of numbers and operators, return all possible results from
 * computing all the different possible ways to group numbers and operators.
 * The valid operators are +, - and *.
 * 
 * Example 1:
 * 
 * 
 * Input: "2-1-1"
 * Output: [0, 2]
 * Explanation: 
 * ((2-1)-1) = 0 
 * (2-(1-1)) = 2
 * 
 * Example 2:
 * 
 * 
 * Input: "2*3-4*5"
 * Output: [-34, -14, -10, -10, 10]
 * Explanation: 
 * (2*(3-(4*5))) = -34 
 * ((2*3)-(4*5)) = -14 
 * ((2*(3-4))*5) = -10 
 * (2*((3-4)*5)) = -10 
 * (((2*3)-4)*5) = 10
 * 
 */

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    unordered_map<string, vector<int>> mem;
    vector<int> diffWaysToCompute(string input)
    {
        if (mem.find(input) != mem.end()) {
            return mem[input];
        }
        vector<int> ans;
        for (size_t i = 0; i < input.size(); i++) {
            if (input[i] == '+' || input[i] == '*' || input[i] == '-') {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for (size_t j = 0; j < left.size(); j++) {
                    for (size_t k = 0; k < right.size(); k++) {
                        if (input[i] == '+') {
                            ans.push_back(left[j] + right[k]);
                        } else if (input[i] == '-') {
                            ans.push_back(left[j] - right[k]);
                        } else if (input[i] == '*') {
                            ans.push_back(left[j] * right[k]);
                        }
                    }
                }
            }
        }
        if (ans.empty()) {
            ans.push_back(stoi(input));
        }
        mem[input] = ans;
        return ans;
    }
};
// @lc code=end
