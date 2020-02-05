/*
 * @lc app=leetcode id=671 lang=cpp
 *
 * [671] Second Minimum Node In a Binary Tree
 *
 * https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/
 *
 * algorithms
 * Easy (43.11%)
 * Likes:    485
 * Dislikes: 726
 * Total Accepted:    64.5K
 * Total Submissions: 150.1K
 * Testcase Example:  '[2,2,5,null,null,5,7]'
 *
 * Given a non-empty special binary tree consisting of nodes with the
 * non-negative value, where each node in this tree has exactly two or zero
 * sub-node. If the node has two sub-nodes, then this node's value is the
 * smaller value among its two sub-nodes. More formally, the property root.val
 * = min(root.left.val, root.right.val) always holds.
 * 
 * Given such a binary tree, you need to output the second minimum value in the
 * set made of all the nodes' value in the whole tree.
 * 
 * If no such second minimum value exists, output -1 instead.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * ⁠   2
 * ⁠  / \
 * ⁠ 2   5
 * ⁠    / \
 * ⁠   5   7
 * 
 * Output: 5
 * Explanation: The smallest value is 2, the second smallest value is 5.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * ⁠   2
 * ⁠  / \
 * ⁠ 2   2
 * 
 * Output: -1
 * Explanation: The smallest value is 2, but there isn't any second smallest
 * value.
 * 
 * 
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
    int findSecondMinimumValue(TreeNode* root)
    {
        int first = root->val;
        unsigned long second = INT_MAX + 1, origin = INT_MAX + 1;
        help(root, first, second);
        return (second == first || second == origin) ? -1 : second;
    }

    void help(TreeNode* root, int first, unsigned long& second)
    {
        if (!root) {
            return;
        }
        if (root->val != first && root->val < second) {
            second = root->val;
        }
        help(root->left, first, second);
        help(root->right, first, second);
    }
};
// @lc code=end
