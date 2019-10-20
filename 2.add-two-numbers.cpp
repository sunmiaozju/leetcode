/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (31.75%)
 * Likes:    6165
 * Dislikes: 1600
 * Total Accepted:    1.1M
 * Total Submissions: 3.3M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */

// @lc code=start

#include <iostream>

using namespace std;

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode(int x)
//         : val(x)
//         , next(NULL)
//     {
//     }
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if (!l1 && !l2) {
            return NULL;
        } else if (!l1) {
            return l2;
        } else if (!l2) {
            return l1;
        }
        int sum = l1->val + l2->val;
        ListNode* ans = new ListNode(sum % 10);
        ans->next = addTwoNumbers(l1->next, l2->next);
        if (sum > 9) {
            ans->next = addTwoNumbers(ans->next, new ListNode(1));
        }
        return ans;
    }
};
// @lc code=end
