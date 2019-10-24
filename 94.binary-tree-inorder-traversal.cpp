/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (58.33%)
 * Likes:    2067
 * Dislikes: 92
 * Total Accepted:    550.5K
 * Total Submissions: 932.6K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 * 
 */

// @lc code=start

#include <iostream>
#include <stack>
#include <vector>

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
    vector<int> inorderTraversal(TreeNode* root)
    {
        // 递归
        // vector<int> nodes;
        // inorder(root, nodes);
        // return nodes;

        // 迭代
        vector<int> nodes;
        stack<TreeNode*> myStack;
        while (root || !myStack.empty()) {
            while (root) {
                myStack.push(root);
                root = root->left;
            }
            root = myStack.top();
            myStack.pop();
            nodes.push_back(root->val);
            root = root->right;
        }
        return nodes;
    }
    // void inorder(TreeNode* root, vector<int>& nodes)
    // {
    //     if (!root) {
    //         return;
    //     }
    //     inorder(root->left, nodes);
    //     nodes.push_back(root->val);
    //     inorder(root->right, nodes);
    // }
};
// @lc code=end
