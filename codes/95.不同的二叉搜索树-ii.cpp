/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (61.26%)
 * Likes:    342
 * Dislikes: 0
 * Total Accepted:    26.1K
 * Total Submissions: 41.9K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * 解释:
 * 以上的输出对应以下 5 种不同结构的二叉搜索树：
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<TreeNode*> generateTrees(int n)
    {
        if (n == 0) {
            return {};
        }
        vector<vector<vector<TreeNode*>>> mem(n + 1, vector<vector<TreeNode*>>(n + 1, vector<TreeNode*>()));
        return help(1, n, mem);
    }

    vector<TreeNode*> help(int left, int right, vector<vector<vector<TreeNode*>>>& mem)
    {
        if (left > right) {
            return { NULL };
        }

        if (mem[left][right] != vector<TreeNode*>()) {
            return mem[left][right];
        }

        vector<TreeNode*> ans;

        for (int i = left; i <= right; i++) {
            auto ll = help(left, i - 1, mem);
            auto rr = help(i + 1, right, mem);
            for (auto a : ll) {
                for (auto b : rr) {
                    TreeNode* node = new TreeNode(i);
                    node->left = a;
                    node->right = b;
                    ans.push_back(node);
                }
            }
        }
        mem[left][right] = ans;
        return ans;
    }
};
// @lc code=end
