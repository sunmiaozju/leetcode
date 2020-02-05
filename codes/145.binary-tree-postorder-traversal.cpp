/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (50.10%)
 * Likes:    1333
 * Dislikes: 69
 * Total Accepted:    324.7K
 * Total Submissions: 623.7K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [3,2,1]
 * 
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> postorderTraversal(TreeNode* root)
    {
        if (!root) {
            return vector<int>();
        }
        stack<TreeNode*> s;
        s.push(root);
        vector<int> ans;
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            ans.push_back(node->val);

            if (node->left) {
                s.push(node->left);
            }
            if (node->right) {
                s.push(node->right);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
