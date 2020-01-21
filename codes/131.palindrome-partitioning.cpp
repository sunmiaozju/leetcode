/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (42.56%)
 * Likes:    1337
 * Dislikes: 52
 * Total Accepted:    197K
 * Total Submissions: 445.3K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * Return all possible palindrome partitioning of s.
 * 
 * Example:
 * 
 * 
 * Input: "aab"
 * Output:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
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
    typedef vector<string> v_str;

    vector<v_str> partition(string s)
    {
        vector<v_str> ans;
        vector<string> path;
        help(ans, path, s, 0);
        return ans;
    }

    void help(vector<v_str>& paths, vector<string>& path, string& s, int start_index)
    {

        if (start_index == s.size()) {
            paths.push_back(path);
            return;
        }

        for (size_t length = 1; start_index + length <= s.size(); length++) {
            if (isPalindrome(s.substr(start_index, length))) {
                path.push_back(s.substr(start_index, length));
                help(paths, path, s, start_index + length);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s)
    {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
};

// int main(int argc, const char** argv)
// {
//     Solution s;
//     string ss("aab");
//     s.partition(ss);
//     return 0;
// }
// @lc code=end
