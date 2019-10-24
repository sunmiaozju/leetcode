/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (52.28%)
 * Likes:    1383
 * Dislikes: 146
 * Total Accepted:    294.1K
 * Total Submissions: 560K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */

#include <iostream>
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
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        // if (nums.empty()) {
        //     return NULL;
        // }
        // return sortBST(nums, 0, nums.size());
        return helpers(nums, 0, nums.size() - 1);
    }
    TreeNode* helpers(vector<int>& nums, int ll, int rr)
    {
        if (ll > rr) {
            return NULL;
        }
        int mid = ll + (rr - ll) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helpers(nums, ll, mid - 1);
        root->right = helpers(nums, mid + 1, rr);
        return root;
    }

    // TreeNode* sortBST(vector<int>& nums, int left, int right)
    // {
    //     int index = left + ((right - left) >> 1);
    //     TreeNode* root_node = new TreeNode(nums[index]);
    //     if (left < index) {
    //         root_node->left = sortBST(nums, left, index);
    //     }
    //     if (index + 1 < right) {
    //         root_node->right = sortBST(nums, index + 1, right);
    //     }
    //     return root_node;
    // }
};

// int main(int argc, const char** argv)
// {
//     Solution s;
//     vector<int> nums;
//     nums.push_back(-10);
//     nums.push_back(-3);
//     nums.push_back(0);
//     nums.push_back(5);
//     // nums.push_back(9);
//     TreeNode* ans;
//     ans = s.sortedArrayToBST(nums);
//     return 0;
// }
