/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
 *
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (40.09%)
 * Likes:    723
 * Dislikes: 281
 * Total Accepted:    72.3K
 * Total Submissions: 176.3K
 * Testcase Example:  '[1,null,2,2]'
 *
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the
 * most frequently occurred element) in the given BST.
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * For example:
 * Given BST [1,null,2,2],
 * 
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 
 * 
 * return [2].
 * 
 * Note: If a tree has more than one mode, you can return them in any order.
 * 
 * Follow up: Could you do that without using any extra space? (Assume that the
 * implicit stack space incurred due to recursion does not count).
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
    vector<int> findMode(TreeNode* root)
    {
        vector<int> ans;
        int curCount = 0, maxCount = 0, pre = INT_MAX;
        inOrder(root, pre, curCount, maxCount, ans);
        return ans;
    }
    void inOrder(TreeNode* root, int& pre, int& curCount, int& maxCount, vector<int>& ans)
    {
        if (!root) {
            return;
        }
        inOrder(root->left, pre, curCount, maxCount, ans);

        if (root->val == pre) {
            curCount++;
        } else {
            curCount = 1;
        }

        if (curCount > maxCount) {
            maxCount = curCount;
            ans = vector<int>();
            ans.push_back(root->val);
        } else if (curCount == maxCount) {
            ans.push_back(root->val);
        }

        pre = root->val;
        inOrder(root->right, pre, curCount, maxCount, ans);
    }
};
// @lc code=end
