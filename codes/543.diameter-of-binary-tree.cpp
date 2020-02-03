/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 *
 * https://leetcode.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (47.38%)
 * Likes:    2088
 * Dislikes: 130
 * Total Accepted:    200.6K
 * Total Submissions: 416.1K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 
 * Given a binary tree, you need to compute the length of the diameter of the
 * tree. The diameter of a binary tree is the length of the longest path
 * between any two nodes in a tree. This path may or may not pass through the
 * root.
 * 
 * 
 * 
 * Example:
 * Given a binary tree 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       2   3
 * ⁠      / \     
 * ⁠     4   5    
 * 
 * 
 * 
 * Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
 * 
 * 
 * Note:
 * The length of path between two nodes is represented by the number of edges
 * between them.
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
class Solution {
public:
    unordered_map<TreeNode*, int> map;
    int diameterOfBinaryTree(TreeNode* root)
    {
        if (!root) {
            return 0;
        }
        int length = maxDepth(root->left) + maxDepth(root->right);
        return max(length, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }

    int maxDepth(TreeNode* root)
    {
        if (!root) {
            return 0;
        }
        if (map.count(root)) {
            return map[root];
        }

        int ans = max(maxDepth(root->left), maxDepth(root->right)) + 1;
        return map[root] = ans;
    }
};
// @lc code=end
