/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (35.84%)
 * Likes:    849
 * Dislikes: 468
 * Total Accepted:    324.1K
 * Total Submissions: 903.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * return its minimum depth = 2.
 * 
 */

#include <iostream>
#include <queue>

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
    int minDepth(TreeNode* root)
    {
        // 层次遍历
        // if (root == NULL) {
        //     return 0;
        // }
        // int height = 0;
        // queue<TreeNode*> q;
        // q.push(root);
        // while (!q.empty()) {
        //     int num = q.size();
        //     height++;
        //     for (size_t i = 0; i < num; i++) {
        //         TreeNode* node = q.front();
        //         q.pop();
        //         if (node->left == NULL && node->right == NULL) {
        //             return height;
        //         }
        //         if (node->left) {
        //             q.push(node->left);
        //         }
        //         if (node->right) {
        //             q.push(node->right);
        //         }
        //     }
        // }
        // return height;

        // 递归解法
        if (root == NULL) {
            return 0;
        }
        int L = minDepth(root->left), R = minDepth(root->right);
        return 1 + (min(L, R) ? min(L, R) : max(R, L));
    }
};
