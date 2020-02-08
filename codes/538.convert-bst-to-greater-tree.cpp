/*
 * @lc app=leetcode id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
 *
 * https://leetcode.com/problems/convert-bst-to-greater-tree/description/
 *
 * algorithms
 * Easy (52.22%)
 * Likes:    1626
 * Dislikes: 105
 * Total Accepted:    103.7K
 * Total Submissions: 194.1K
 * Testcase Example:  '[5,2,13]'
 *
 * Given a Binary Search Tree (BST), convert it to a Greater Tree such that
 * every key of the original BST is changed to the original key plus sum of all
 * keys greater than the original key in BST.
 * 
 * 
 * Example:
 * 
 * Input: The root of a Binary Search Tree like this:
 * ⁠             5
 * ⁠           /   \
 * ⁠          2     13
 * 
 * Output: The root of a Greater Tree like this:
 * ⁠            18
 * ⁠           /   \
 * ⁠         20     13
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
    TreeNode* convertBST(TreeNode* root)
    {
        stack<TreeNode*> s;
        TreeNode* node = root;
        int pre = 0;
        while (node || !s.empty()) {
            while (node) {
                s.push(node);
                node = node->right;
            }
            node = s.top();
            s.pop();
            node->val = node->val + pre;
            pre = node->val;
            node = node->left;
        }
        return root;
    }
};
// @lc code=end
