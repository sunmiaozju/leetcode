/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (47.14%)
 * Likes:    1075
 * Dislikes: 79
 * Total Accepted:    253.2K
 * Total Submissions: 531.9K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
 * 
 */

// @lc code=start

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//   Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x)
//         : val(x)
//         , left(NULL)
//         , right(NULL)
//     {
//     }
// };

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> ans;
        if (!root) {
            return ans;
        }
        string num = to_string(root->val);
        if (!root->left && !root->right) {
            ans.push_back(num);
            return ans;
        }

        vector<string> left, right;
        if (root->left) {
            left = binaryTreePaths(root->left);
        }
        if (root->right) {
            right = binaryTreePaths(root->right);
        }

        for (size_t i = 0; i < left.size(); i++) {
            left[i] = num + "->" + left[i];
        }
        for (size_t i = 0; i < right.size(); i++) {
            right[i] = num + "->" + right[i];
        }

        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};
// @lc code=end
