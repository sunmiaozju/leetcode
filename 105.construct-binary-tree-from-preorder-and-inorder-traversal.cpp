/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (43.01%)
 * Likes:    2172
 * Dislikes: 61
 * Total Accepted:    265.8K
 * Total Submissions: 607.6K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
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
 */

// @lc code=start

#include <iostream>
#include <vector>

using namespace std;

// // Definition for a binary tree node.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return buildHelp(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* buildHelp(vector<int>& preorder, vector<int>& inorder, int left, int right, int ll, int rr)
    {
        if (left > right) {
            return NULL;
        }
        size_t i = left;
        for (; i <= right; ++i) {
            if (inorder[i] == preorder[ll]) {
                break;
            }
        }
        TreeNode* root = new TreeNode(inorder[i]);
        TreeNode* left_node = buildHelp(preorder, inorder, left, i - 1, ll + 1, ll + i - left);
        TreeNode* right_node = buildHelp(preorder, inorder, i + 1, right, rr - right + i + 1, rr);
        root->left = left_node;
        root->right = right_node;
        return root;
    }
};

// int main(int argc, const char** argv)
// {
//     Solution s;
//     vector<int> v1, v2;
//     v1.push_back(3);
//     v1.push_back(9);
//     v1.push_back(20);
//     v1.push_back(15);
//     v1.push_back(7);

//     v2.push_back(9);
//     v2.push_back(3);
//     v2.push_back(15);
//     v2.push_back(20);
//     v2.push_back(7);

//     s.buildTree(v1, v2);
//     return 0;
// }
// @lc code=end
