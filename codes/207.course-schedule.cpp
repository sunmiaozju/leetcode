/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (39.14%)
 * Likes:    2776
 * Dislikes: 141
 * Total Accepted:    316.9K
 * Total Submissions: 778.8K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * Example 1:
 * 
 * 
 * Input: 2, [[1,0]] 
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * 
 * Example 2:
 * 
 * 
 * Input: 2, [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you
 * should
 * also have finished course 1. So it is impossible.
 * 
 * 
 * Note:
 * 
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> in(numCourses, 0);
        for (auto a : prerequisites) {
            graph[a[1]].push_back(a[0]);
            in[a[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < in.size(); i++) {
            if (0 == in[i]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int item = q.front();
            q.pop();
            for (auto a : graph[item]) {
                in[a]--;
                if (!in[a]) {
                    q.push(a);
                }
            }
        }

        for (auto a : in) {
            if (a != 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
