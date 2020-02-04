/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
 *
 * https://leetcode.com/problems/longest-univalue-path/description/
 *
 * algorithms
 * Easy (34.45%)
 * Likes:    1316
 * Dislikes: 352
 * Total Accepted:    76.7K
 * Total Submissions: 218.8K
 * Testcase Example:  '[5,4,5,1,1,5]'
 *
 * Given a binary tree, find the length of the longest path where each node in
 * the path has the same value. This path may or may not pass through the
 * root.
 * 
 * The length of path between two nodes is represented by the number of edges
 * between them.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         1   1   5
 * 
 * 
 * Output: 2
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * 
 * 
 * ⁠             1
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         4   4   5
 * 
 * 
 * Output: 2
 * 
 * 
 * 
 * Note: The given binary tree has not more than 10000 nodes. The height of the
 * tree is not more than 1000.
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
    int longestUnivaluePath(TreeNode* root)
    {
        int ans = 0;
        help(root, ans);

        return ans;
    }

    int help(TreeNode* node, int& ans)
    {
        if (!node) {
            return 0;
        }
        int l = help(node->left, ans);
        int r = help(node->right, ans);
        if (node->left && node->val == node->left->val) {
            l = l + 1;
        } else {
            l = 0;
        }

        if (node->right && node->val == node->right->val) {
            r = r + 1;
        } else {
            r = 0;
        }

        ans = max(l + r, ans);

        return max(l, r);
    }
};
// @lc code=end
