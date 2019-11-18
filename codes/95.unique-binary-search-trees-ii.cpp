/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (36.90%)
 * Likes:    1587
 * Dislikes: 130
 * Total Accepted:    159.1K
 * Total Submissions: 424.1K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
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
typedef vector<TreeNode*> v_treenode;
typedef vector<v_treenode> vv_treenode;

class Solution {
public:
    vector<TreeNode*> generateTrees(int n)
    {
        if (!n) {
            return {};
        }
        vector<vv_treenode> mem(n + 1, vector<v_treenode>(n + 1));
        return help(1, n, mem);
    }
    vector<TreeNode*> help(int left, int right, vector<vv_treenode>& mem)
    {
        vector<TreeNode*> ans;
        if (left > right) {
            ans.push_back(NULL);
            return ans;
        }
        if (!mem[left][right].empty()) {
            return mem[left][right];
        }
        for (size_t i = left; i <= right; i++) {
            vector<TreeNode*> leftnodes = help(left, i - 1, mem);
            vector<TreeNode*> rightnodes = help(i + 1, right, mem);
            for (size_t j = 0; j < leftnodes.size(); j++) {
                for (size_t k = 0; k < rightnodes.size(); k++) {
                    TreeNode* midnode = new TreeNode(i);
                    midnode->left = leftnodes[j];
                    midnode->right = rightnodes[k];
                    ans.push_back(midnode);
                }
            }
        }
        mem[left][right] = ans;
        return ans;
    }
};
// int main(int argc, char const* argv[])
// {
//     Solution s;
//     s.generateTrees(3);
//     return 0;
// }

// @lc code=end
