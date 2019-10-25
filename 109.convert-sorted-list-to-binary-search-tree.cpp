/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (42.36%)
 * Likes:    1289
 * Dislikes: 74
 * Total Accepted:    198.2K
 * Total Submissions: 460.5K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted linked list: [-10,-3,0,5,9],
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

// @lc code=start
#include <iostream>

using namespace std;

// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode(int x)
//         : val(x)
//         , next(NULL)
//     {
//     }
// };

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
    TreeNode* sortedListToBST(ListNode* head)
    {

        // ListNode* cur = head;
        // int count = 0;
        // while (cur) {
        //     cur = cur->next;
        //     count++;
        // }
        // return help(head, 0, count - 1);

        // 快慢指针
        if (!head) {
            return NULL;
        }
        if (!head->next) {
            TreeNode* ans = new TreeNode(head->val);
            return ans;
        }
        ListNode *slow = head, *fast = head, *pre;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        TreeNode* root = new TreeNode(slow->val);
        root->right = sortedListToBST(slow->next);
        root->left = sortedListToBST(head);
        return root;
    }
    // TreeNode* help(ListNode* head, int ll, int rr)
    // {
    //     if (rr < ll) {
    //         return NULL;
    //     }
    //     int mid = ll + (rr - ll) / 2;
    //     ListNode* cur = head;
    //     int count = ll;
    //     while (cur) {
    //         if (count == mid) {
    //             break;
    //         }
    //         cur = cur->next;
    //         count++;
    //     }
    //     TreeNode* root = new TreeNode(cur->val);
    //     root->left = help(head, ll, count - 1);
    //     root->right = help(cur->next, count + 1, rr);
    //     return root;
    // }
};

;
// @lc code=end
