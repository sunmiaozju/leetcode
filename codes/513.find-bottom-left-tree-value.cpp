/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
 *
 * https://leetcode.com/problems/find-bottom-left-tree-value/description/
 *
 * algorithms
 * Medium (59.26%)
 * Likes:    700
 * Dislikes: 118
 * Total Accepted:    89.8K
 * Total Submissions: 149.2K
 * Testcase Example:  '[2,1,3]'
 *
 * 
 * Given a binary tree, find the leftmost value in the last row of the tree. 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 
 * Output:
 * 1
 * 
 * 
 * 
 * ⁠ Example 2: 
 * 
 * Input:
 * 
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * ⁠    /   / \
 * ⁠   4   5   6
 * ⁠      /
 * ⁠     7
 * 
 * Output:
 * 7
 * 
 * 
 * 
 * Note:
 * You may assume the tree (i.e., the given root node) is not NULL.
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
    int findBottomLeftValue(TreeNode* root)
    {
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            bool isFirst = true;
            while (size--) {
                TreeNode* item = q.front();
                q.pop();
                if (isFirst) {
                    ans.push_back(item->val);
                    isFirst = false;
                }
                if (item->left) {
                    q.push(item->left);
                }
                if (item->right) {
                    q.push(item->right);
                }
            }
        }
        return ans.back();
    }
};
// @lc code=end
