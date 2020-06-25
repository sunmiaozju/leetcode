/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 *
 * https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (39.21%)
 * Likes:    395
 * Dislikes: 0
 * Total Accepted:    34.7K
 * Total Submissions: 86.7K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个非空二叉树，返回其最大路径和。
 * 
 * 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * 输出: 6
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-10,9,20,null,null,15,7]
 * 
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * 输出: 42
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxPathSum(TreeNode* root)
    {
        int ret = INT_MIN;
        help(root, ret);
        return ret;
    }

    int help(TreeNode* root, int& ret)
    {
        if (!root) {
            return 0;
        }

        int left = max(help(root->left, ret), 0);
        int right = max(help(root->right, ret), 0);

        ret = max(ret, left + right + root->val);

        return max(left, right) + root->val;
    }
};
// @lc code=end
