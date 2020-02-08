/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
 *
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (51.38%)
 * Likes:    677
 * Dislikes: 57
 * Total Accepted:    76K
 * Total Submissions: 145.5K
 * Testcase Example:  '[1,null,3,2]'
 *
 * Given a binary search tree with non-negative values, find the minimum
 * absolute difference between values of any two nodes.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   /
 * ⁠  2
 * 
 * Output:
 * 1
 * 
 * Explanation:
 * The minimum absolute difference is 1, which is the difference between 2 and
 * 1 (or between 2 and 3).
 * 
 * 
 * 
 * 
 * Note: There are at least two nodes in this BST.
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
    int getMinimumDifference(TreeNode* root)
    {
        stack<TreeNode*> s;
        TreeNode* node = root;
        int pre = INT_MAX, min_num = INT_MAX;
        while (node || !s.empty()) {
            while (node) {
                s.push(node);
                node = node->left;
            }
            node = s.top();
            s.pop();
            min_num = min(min_num, abs(node->val - pre));
            pre = node->val;
            node = node->right;
        }
        return min_num;
    }
};
// @lc code=end
