/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 *
 * https://leetcode-cn.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (47.02%)
 * Likes:    324
 * Dislikes: 0
 * Total Accepted:    45.2K
 * Total Submissions: 91.2K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。
 * 
 * 
 * 
 * 示例 :
 * 给定二叉树
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       2   3
 * ⁠      / \     
 * ⁠     4   5    
 * 
 * 
 * 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
 * 
 * 
 * 
 * 注意：两结点之间的路径长度是以它们之间边的数目表示。
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
    int diameterOfBinaryTree(TreeNode* root)
    {
        if (!root) {
            return 0;
        }
        unordered_map<TreeNode*, int> mem;
        int left = depth(root->left, mem);
        int right = depth(root->right, mem);
        int len1 = left + right;

        int len2 = diameterOfBinaryTree(root->left);
        int len3 = diameterOfBinaryTree(root->right);

        return max(len1, max(len2, len3));
    }

    int depth(TreeNode* root, unordered_map<TreeNode*, int>& mem)
    {
        if (!root) {
            return 0;
        }
        if (mem.count(root)) {
            return mem[root];
        }
        int left = depth(root->left, mem);
        int right = depth(root->right, mem);

        mem[root] = max(left, right) + 1;

        return mem[root];
    }
};
// @lc code=end
