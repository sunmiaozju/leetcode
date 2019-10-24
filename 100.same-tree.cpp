/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 *
 * https://leetcode.com/problems/same-tree/description/
 *
 * algorithms
 * Easy (50.60%)
 * Likes:    1292
 * Dislikes: 43
 * Total Accepted:    414.1K
 * Total Submissions: 817.1K
 * Testcase Example:  '[1,2,3]\n[1,2,3]'
 *
 * Given two binary trees, write a function to check if they are the same or
 * not.
 * 
 * Two binary trees are considered the same if they are structurally identical
 * and the nodes have the same value.
 * 
 * Example 1:
 * 
 * 
 * Input:     1         1
 * ⁠         / \       / \
 * ⁠        2   3     2   3
 * 
 * ⁠       [1,2,3],   [1,2,3]
 * 
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:     1         1
 * ⁠         /           \
 * ⁠        2             2
 * 
 * ⁠       [1,2],     [1,null,2]
 * 
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:     1         1
 * ⁠         / \       / \
 * ⁠        2   1     1   2
 * 
 * ⁠       [1,2,1],   [1,1,2]
 * 
 * Output: false
 * 
 * 
 */
#include <iostream>
#include <stack>

using namespace std;

// //   Definition for a binary tree node.
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
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        // if (p == q) {
        //     return true;
        // } else if (p == NULL || q == NULL) {
        //     return false;
        // }

        // stack<TreeNode*> p_stack, q_stack;
        // TreeNode *p_node, *q_node;
        // p_stack.push(p);
        // q_stack.push(q);

        // while (!p_stack.empty() && !q_stack.empty()) {
        //     p_node = p_stack.top();
        //     q_node = q_stack.top();
        //     if (p_node->val != q_node->val) {
        //         return false;
        //     }
        //     p_stack.pop();
        //     q_stack.pop();

        //     if (p_node->right && q_node->right) {
        //         p_stack.push(p_node->right);
        //         q_stack.push(q_node->right);
        //     } else if (p_node->right != q_node->right) {
        //         return false;
        //     }

        //     if (p_node->left && q_node->left) {
        //         p_stack.push(p_node->left);
        //         q_stack.push(q_node->left);
        //     } else if (p_node->left != q_node->left) {
        //         return false;
        //     }
        // }
        // return true;

        // if (p == q) {
        //     return true;
        // } else {
        //     return p && q && p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        // }

        if (!p && !q) {
            return true;
        } else if ((p && !q) || (q && !p)) {
            return false;
        }

        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
