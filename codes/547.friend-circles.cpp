/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Friend Circles
 *
 * https://leetcode.com/problems/friend-circles/description/
 *
 * algorithms
 * Medium (54.93%)
 * Likes:    1329
 * Dislikes: 105
 * Total Accepted:    117K
 * Total Submissions: 209.3K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * 
 * There are N students in a class. Some of them are friends, while some are
 * not. Their friendship is transitive in nature. For example, if A is a direct
 * friend of B, and B is a direct friend of C, then A is an indirect friend of
 * C. And we defined a friend circle is a group of students who are direct or
 * indirect friends.
 * 
 * 
 * 
 * Given a N*N matrix M representing the friend relationship between students
 * in the class. If M[i][j] = 1, then the ith and jth students are direct
 * friends with each other, otherwise not. And you have to output the total
 * number of friend circles among all the students.
 * 
 * 
 * Example 1:
 * 
 * Input: 
 * [[1,1,0],
 * ⁠[1,1,0],
 * ⁠[0,0,1]]
 * Output: 2
 * Explanation:The 0th and 1st students are direct friends, so they are in a
 * friend circle. The 2nd student himself is in a friend circle. So return
 * 2.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * [[1,1,0],
 * ⁠[1,1,1],
 * ⁠[0,1,1]]
 * Output: 1
 * Explanation:The 0th and 1st students are direct friends, the 1st and 2nd
 * students are direct friends, so the 0th and 2nd students are indirect
 * friends. All of them are in the same friend circle, so return 1.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * N is in range [1,200].
 * M[i][i] = 1 for all students.
 * If M[i][j] = 1, then M[j][i] = 1.
 * 
 * 
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M)
    {
        // stack<int> s;
        // int max_num = 0;
        // for (int i = 0; i < M.size(); i++) {
        //     if (M[i][i] == 1) {
        //         s.push(i);
        //         M[i][i] = 0;
        //         while (!s.empty()) {
        //             int item = s.top();
        //             s.pop();
        //             for (int j = M.size() - 1; j >= 0; j--) {
        //                 if (M[item][j] == 1 && M[j][j] == 1) {
        //                     s.push(j);
        //                     M[j][j] = 0;
        //                 }
        //             }
        //         }
        //         max_num++;
        //     }
        // }
        // return max_num;

        int n = M.size();
        vector<int> root(n);
        for (size_t i = 0; i < n; i++) {
            root[i] = i;
        }
        int res = n;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = i + 1; j < n; j++) {
                if (M[i][j] == 1) {
                    int p1 = getRoot(root, i);
                    int p2 = getRoot(root, j);
                    if (p1 != p2) {
                        root[p2] = p1;
                        res--;
                    }
                }
            }
        }
        return res;
    }
    int getRoot(vector<int>& root, int i)
    {
        while (i != root[i]) {
            i = root[root[i]];
        }
        return i;
    }
};
// @lc code=end
