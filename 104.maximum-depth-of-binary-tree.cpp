/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 *
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (61.78%)
 * Likes:    1540
 * Dislikes: 59
 * Total Accepted:    575.2K
 * Total Submissions: 928.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its maximum depth.
 * 
 * The maximum depth is the number of nodes along the longest path from the
 * root node down to the farthest leaf node.
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
 * return its depth = 3.
 * 
 */

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

#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        //递归版本
        // if (root == NULL) {
        //     return 0;
        // }
        // return max(maxDepth(root->left), maxDepth(root->right)) + 1;

        // 非递归版本：广度优先遍历
        if (!root) {
            return 0;
        }
        queue<TreeNode*> q;
        TreeNode* node;
        q.push(root);
        int depth = 0;
        while (int num = q.size()) {
            depth++;
            for (size_t i = 0; i < num; i++) {
                node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
        return depth;
    }
};
