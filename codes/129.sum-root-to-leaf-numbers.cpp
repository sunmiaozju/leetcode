/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
 *
 * https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
 *
 * algorithms
 * Medium (43.65%)
 * Likes:    847
 * Dislikes: 29
 * Total Accepted:    207.2K
 * Total Submissions: 468.8K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path
 * could represent a number.
 * 
 * An example is the root-to-leaf path 1->2->3 which represents the number
 * 123.
 * 
 * Find the total sum of all root-to-leaf numbers.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * Output: 25
 * Explanation:
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * Therefore, sum = 12 + 13 = 25.
 * 
 * Example 2:
 * 
 * 
 * Input: [4,9,0,5,1]
 * ⁠   4
 * ⁠  / \
 * ⁠ 9   0
 * / \
 * 5   1
 * Output: 1026
 * Explanation:
 * The root-to-leaf path 4->9->5 represents the number 495.
 * The root-to-leaf path 4->9->1 represents the number 491.
 * The root-to-leaf path 4->0 represents the number 40.
 * Therefore, sum = 495 + 491 + 40 = 1026.
 * 
 */

// @lc code=start

#include <iostream>

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
    int sumNumbers(TreeNode* root)
    {
        int sum = 0, all_sum = 0;
        help(root, sum, all_sum);
        return all_sum;
    }
    void help(TreeNode* root, int& sum, int& all_sum)
    {
        if (!root) {
            return;
        }
        sum = sum * 10 + root->val;
        if (!root->left && !root->right) {
            all_sum += sum;
        }
        help(root->left, sum, all_sum);
        help(root->right, sum, all_sum);
        sum = (sum - root->val) / 10;
        return;
    }
};

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
    int sumNumbers(TreeNode* root)
    {
        int ans = 0, pathsum = 0;
        help(ans, pathsum, root);
        return ans;
    }
    void help(int& sum, int pathsum, TreeNode* root)
    {
        if (!root) {
            return;
        }
        pathsum = pathsum * 10 + root->val;

        if (!root->left && !root->right) {
            sum += pathsum;
            return;
        }
        help(sum, pathsum, root->left);
        help(sum, pathsum, root->right);
    }
};
// @lc code=end
