/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (40.92%)
 * Likes:    1066
 * Dislikes: 23
 * Total Accepted:    174.4K
 * Total Submissions: 420.2K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 */

// @lc code=start

#include <iostream>
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        return buildHelp(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    TreeNode* buildHelp(vector<int>& inorder, vector<int>& postorder, int in_ll, int in_rr, int post_ll, int post_rr)
    {
        if (in_ll > in_rr) {
            return NULL;
        }
        int i = in_ll;
        for (; i <= in_rr; i++) {
            if (inorder[i] == postorder[post_rr]) {
                break;
            }
        }
        TreeNode* root = new TreeNode(inorder[i]);
        root->left = buildHelp(inorder, postorder, in_ll, i - 1, post_ll, post_ll - in_ll + i - 1);
        root->right = buildHelp(inorder, postorder, i + 1, in_rr, post_rr - 1 - in_rr + i + 1, post_rr - 1);
        return root;
    }
};
// @lc code=end
