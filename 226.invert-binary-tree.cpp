/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 *
 * https://leetcode.com/problems/invert-binary-tree/description/
 *
 * algorithms
 * Easy (59.51%)
 * Likes:    2097
 * Dislikes: 35
 * Total Accepted:    371.1K
 * Total Submissions: 618.8K
 * Testcase Example:  '[4,2,7,1,3,6,9]'
 *
 * Invert a binary tree.
 * 
 * Example:
 * 
 * Input:
 * 
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 2     7
 * ⁠/ \   / \
 * 1   3 6   9
 * 
 * Output:
 * 
 * 
 * ⁠    4
 * ⁠  /   \
 * ⁠ 7     2
 * ⁠/ \   / \
 * 9   6 3   1
 * 
 * Trivia:
 * This problem was inspired by this original tweet by Max Howell:
 * 
 * Google: 90% of our engineers use the software you wrote (Homebrew), but you
 * can’t invert a binary tree on a whiteboard so f*** off.
 * 
 */

// @lc code=start

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
    TreeNode* invertTree(TreeNode* root)
    {
        // if (root == NULL) {
        //     return NULL;
        // }
        // queue<TreeNode*> q;
        // q.push(root);
        // while (!q.empty()) {
        //     int num = q.size();
        //     for (size_t i = 0; i < num; i++) {
        //         TreeNode* node = q.front();
        //         swap(node->left, node->right);
        //         q.pop();
        //         if (node->left) {
        //             q.push(node->left);
        //         }
        //         if (node->right) {
        //             q.push(node->right);
        //         }
        //     }
        // }
        // return root;

        if (root) {
            invertTree(root->left);
            invertTree(root->right);
            swap(root->left, root->right);
        }

        return root;
    }
};
// @lc code=end
