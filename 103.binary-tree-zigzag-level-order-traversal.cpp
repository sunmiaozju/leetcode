/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (43.12%)
 * Likes:    1271
 * Dislikes: 72
 * Total Accepted:    264.5K
 * Total Submissions: 605.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
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
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
 * 
 * 
 */

// @lc code=start

#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

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

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        // vector<vector<int>> ans;
        // if (!root) {
        //     return ans;
        // }
        // stack<TreeNode*> s1, s2;
        // s1.push(root);
        // bool turn = true;
        // while (!s1.empty()) {
        //     int num = s1.size();
        //     vector<int> nodes;
        //     turn = !turn;
        //     for (size_t i = 0; i < num; i++) {
        //         TreeNode* node = s1.top();
        //         s1.pop();
        //         nodes.push_back(node->val);
        //         if (turn) {
        //             if (node->right) {
        //                 s2.push(node->right);
        //             }
        //             if (node->left) {
        //                 s2.push(node->left);
        //             }
        //         } else {
        //             if (node->left) {
        //                 s2.push(node->left);
        //             }
        //             if (node->right) {
        //                 s2.push(node->right);
        //             }
        //         }
        //     }
        //     ans.push_back(nodes);
        //     swap(s1, s2);
        // }
        // return ans;

        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool turn = false;
        while (!q.empty()) {
            int num = q.size();
            vector<int> nodes(num);
            turn = !turn;
            for (size_t i = 0; i < num; i++) {
                TreeNode* node = q.front();
                q.pop();
                int index = turn ? i : num - i - 1;
                nodes[index] = node->val;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            ans.push_back(nodes);
        }
        return ans;
    }
};
// @lc code=end
