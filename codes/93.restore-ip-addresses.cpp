/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (32.37%)
 * Likes:    826
 * Dislikes: 353
 * Total Accepted:    156.4K
 * Total Submissions: 478.1K
 * Testcase Example:  '"25525511135"'
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 * 
 * Example:
 * 
 * 
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 * 
 * 
 */

// @lc code=start

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ans;
        string path;
        int index = 0;
        help(ans, path, s, index, 0);
        return ans;
    }
    void help(vector<string>& paths, string& path, string& s, int& index, int level)
    {
        if (level == 4) {
            if (path.size() == s.size() + 4) {
                path.pop_back();
                paths.push_back(path);
                path.push_back('.');
            }
            return;
        }
        for (int i = 1; i <= 3; i++) {
            string tmp = s.substr(index, i);
            if (atoi(tmp.c_str()) > 255 || i != tmp.size() || tmp.size() > 1 && tmp[0] == '0') {
                return;
            }
            path = path + s.substr(index, i) + ".";
            index += i;
            help(paths, path, s, index, level + 1);
            index -= i;
            path = path.substr(0, path.size() - 1 - i);
        }
    }
};

// @lc code=end
