/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (52.49%)
 * Likes:    982
 * Dislikes: 46
 * Total Accepted:    389.9K
 * Total Submissions: 736.2K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,2,3]
 * 
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 * 
 */

// @lc code=start
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

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
    vector<int> preorderTraversal(TreeNode* root)
    {
        // vector<int> nodes;
        // help(root, nodes);
        // return nodes;

        vector<int> nodes;
        if (!root) {
            return nodes;
        }
        stack<TreeNode*> myStack;
        myStack.push(root);
        while (!myStack.empty()) {
            TreeNode* node = myStack.top();
            myStack.pop();
            nodes.push_back(node->val);
            if (node->right) {
                myStack.push(node->right);
            }
            if (node->left) {
                myStack.push(node->left);
            }
        }
        return nodes;
    }
    // void help(TreeNode* root, vector<int>& nodes)
    // {
    //     if (!root) {
    //         return;
    //     }
    //     nodes.push_back(root->val);
    //     help(root->left, nodes);
    //     help(root->right, nodes);
    //     return;
    // }
};
// @lc code=end
