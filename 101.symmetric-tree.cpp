/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (44.19%)
 * Likes:    2604
 * Dislikes: 57
 * Total Accepted:    455.4K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3] is not:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 * 
 */
#include <iostream>
#include <stack>

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
    bool isSymmetric(TreeNode* root)
    {
        // if (!root) {
        //     return true;
        // }
        // TreeNode *l_node, *r_node;
        // stack<TreeNode*> l_stack, r_stack;
        // l_stack.push(root);
        // r_stack.push(root);
        // while (!l_stack.empty() && !r_stack.empty() && l_stack.top() != root->right && r_stack.top() != root->left) {
        //     l_node = l_stack.top();
        //     r_node = r_stack.top();
        //     if (l_node->val != r_node->val) {
        //         return false;
        //     }
        //     l_stack.pop();
        //     r_stack.pop();
        //     if (l_node->right && r_node->left) {
        //         l_stack.push(l_node->right);
        //         r_stack.push(r_node->left);
        //     } else if (l_node->right != r_node->left) {
        //         return false;
        //     }

        //     if (l_node->left && r_node->right) {
        //         l_stack.push(l_node->left);
        //         r_stack.push(r_node->right);
        //     } else if (l_node->left != r_node->right) {
        //         return false;
        //     }
        // }
        // return true;
        if (root == NULL) {
            return true;
        }
        return isSymmetricTree(root->left, root->right);
    }
    bool isSymmetricTree(TreeNode* left, TreeNode* right)
    {
        if (left == right) {
            return true;
        } else if (right == NULL || left == NULL) {
            return false;
        } else if (left->val == right->val) {
            return isSymmetricTree(left->left, right->right) && isSymmetricTree(left->right, right->left);
        } else {
            return false;
        }
    }
};
