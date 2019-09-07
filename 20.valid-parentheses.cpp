/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (37.10%)
 * Likes:    3262
 * Dislikes: 154
 * Total Accepted:    672.3K
 * Total Submissions: 1.8M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        if (s == "")
            return true;
        stack<char> box;
        size_t i = 0;
        for (; i < s.size(); i++) {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
                box.push(s[i]);
            } else {
                if (box.size() == 0) {
                    return false;
                } else if (s[i] == ')' && box.top() == '(') {
                    box.pop();
                } else if (s[i] == '}' && box.top() == '{') {
                    box.pop();
                } else if (s[i] == ']' && box.top() == '[') {
                    box.pop();
                } else {
                    return false;
                }
            }
        }
        return box.empty();
    }
};
