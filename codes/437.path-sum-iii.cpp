/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 *
 * https://leetcode.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Easy (43.61%)
 * Likes:    2650
 * Dislikes: 193
 * Total Accepted:    147.1K
 * Total Submissions: 329.3K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * You are given a binary tree in which each node contains an integer value.
 * 
 * Find the number of paths that sum to a given value.
 * 
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards
 * (traveling only from parent nodes to child nodes).
 * 
 * The tree has no more than 1,000 nodes and the values are in the range
 * -1,000,000 to 1,000,000.
 * 
 * Example:
 * 
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 * 
 * ⁠     10
 * ⁠    /  \
 * ⁠   5   -3
 * ⁠  / \    \
 * ⁠ 3   2   11
 * ⁠/ \   \
 * 3  -2   1
 * 
 * Return 3. The paths that sum to 8 are:
 * 
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3. -3 -> 11
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
    int pathSum(TreeNode* root, int sum)
    {
        vector<TreeNode*> out;
        int ans = 0;
        help(root, sum, 0, out, ans);
        return ans;
    }

    void help(TreeNode* node, int sum, int curSum, vector<TreeNode*>& out, int& ans)
    {
        if (!node) {
            return;
        }
        out.push_back(node);
        curSum += node->val;

        if (curSum == sum) {
            ans++;
        }
        int item = curSum;
        for (int i = 0; i < out.size() - 1; i++) {
            item = item - out[i]->val;
            if (sum == item) {
                ans++;
            }
        }

        help(node->left, sum, curSum, out, ans);
        help(node->right, sum, curSum, out, ans);

        out.pop_back();
    }
};
// @lc code=end
