/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (47.96%)
 * Likes:    830
 * Dislikes: 160
 * Total Accepted:    246.8K
 * Total Submissions: 512.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
 * 
 */

//   Definition for a binary tree node.
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

#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        // 广度优先遍历
        // if (root == NULL) {
        //     return vector<vector<int>>();
        // }
        // TreeNode* node;
        // queue<TreeNode*> q;
        // q.push(root);
        // vector<vector<int>> ans;
        // while (!q.empty()) {
        //     int num = q.size();
        //     vector<int> tmp;
        //     for (size_t i = 0; i < num; i++) {
        //         node = q.front();
        //         q.pop();
        //         tmp.push_back(node->val);
        //         if (node->left) {
        //             q.push(node->left);
        //         }
        //         if (node->right) {
        //             q.push(node->right);
        //         }
        //     }
        //     ans.insert(ans.begin(), tmp);
        // }
        // return ans;

        // 递归解法
        int level = maxLength(root);
        vector<vector<int>> ans(level, vector<int>());
        levelOrder(ans, root, level - 1);
        return ans;
    }
    void levelOrder(vector<vector<int>>& ans, TreeNode* root, int level)
    {
        if (!root) {
            return;
        }
        ans[level].push_back(root->val);
        levelOrder(ans, root->left, level - 1);
        levelOrder(ans, root->right, level - 1);
    }

    int maxLength(TreeNode* root)
    {
        if (!root) {
            return 0;
        }
        return max(maxLength(root->left), maxLength(root->right)) + 1;
    }
};
