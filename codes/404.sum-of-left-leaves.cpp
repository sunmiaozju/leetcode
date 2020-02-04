/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
 *
 * https://leetcode.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (49.62%)
 * Likes:    872
 * Dislikes: 99
 * Total Accepted:    153K
 * Total Submissions: 305.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Find the sum of all left leaves in a given binary tree.
 * 
 * Example:
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * There are two left leaves in the binary tree, with values 9 and 15
 * respectively. Return 24.
 * 
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
    int sumOfLeftLeaves(TreeNode* root)
    {
        if (!root) {
            return 0;
        }
        int sum = 0;
        if (root->left) {
            if (!root->left->left && !root->left->right) {
                sum += root->left->val;
            }
            sum += sumOfLeftLeaves(root->left);
        }
        if (root->right) {
            sum += sumOfLeftLeaves(root->right);
        }

        return sum;
    }
};
// @lc code=end
