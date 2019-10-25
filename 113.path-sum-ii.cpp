/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (42.08%)
 * Likes:    1126
 * Dislikes: 42
 * Total Accepted:    265.1K
 * Total Submissions: 620.8K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \    / \
 * 7    2  5   1
 * 
 * 
 * Return:
 * 
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
 * 
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x)
//         : val(x)
//         , left(NULL)
//         , right(NULL)
//     {
//     }
// };

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum)
    {
        // vector<vector<int>> ans;
        // if (!root) {
        //     return ans;
        // }
        // if (!root->left && !root->right && root->val == sum) {
        //     ans.push_back(vector<int>(1, root->val));
        //     return ans;
        // }

        // vector<vector<int>> left = pathSum(root->left, sum - root->val);
        // vector<vector<int>> right = pathSum(root->right, sum - root->val);
        // if (left.size()) {
        //     for (size_t i = 0; i < left.size(); i++) {
        //         left[i].insert(left[i].begin(), root->val);
        //     }
        //     ans.insert(ans.end(), left.begin(), left.end());
        // }
        // if (right.size()) {
        //     for (size_t i = 0; i < right.size(); i++) {
        //         right[i].insert(right[i].begin(), root->val);
        //     }
        //     ans.insert(ans.end(), right.begin(), right.end());
        // }
        // vector<int> path;
        // return ans;

        vector<vector<int>> paths;
        vector<int> path;
        help(root, sum, paths, path);
        return paths;
    }
    void help(TreeNode* root, int sum, vector<vector<int>>& paths, vector<int>& path)
    {
        if (!root) {
            return;
        }
        path.push_back(root->val);
        if (!root->left && !root->right && root->val == sum) {
            paths.push_back(path);
        }
        help(root->left, sum - root->val, paths, path);
        help(root->right, sum - root->val, paths, path);
        path.pop_back();
    }
};
// @lc code=end
