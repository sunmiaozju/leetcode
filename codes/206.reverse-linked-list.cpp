/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (56.67%)
 * Likes:    2905
 * Dislikes: 73
 * Total Accepted:    707.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Reverse a singly linked list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * 
 * 
 * Follow up:
 * 
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
 * 
 */

// @lc code=start
#include <iostream>

using namespace std;

//   Definition for singly-linked list.
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
    ListNode* reverseList(ListNode* head)
    {
        // ListNode pre(0);
        // ListNode* cur = head;
        // while (cur != NULL) {
        //     ListNode* tmp = pre.next;
        //     pre.next = cur;
        //     ListNode* tmp_cur_next = cur->next;
        //     cur->next = tmp;
        //     cur = tmp_cur_next;
        // }
        // return pre.next;

        // ListNode pre(0), *cur = head;
        // pre.next = head;
        // while (cur && cur->next) {
        //     ListNode* tmp = pre.next;
        //     pre.next = cur->next;
        //     cur->next = cur->next->next;
        //     pre.next->next = tmp;
        // }
        // return pre.next;

        // if (head == NULL || head->next == NULL) {
        //     return head;
        // }
        // ListNode* ans = reverseList(head->next);
        // head->next->next = head;
        // head->next = NULL;
        // return ans;

        // 迭代循环
        // ListNode *pre = new ListNode(0), *cur = head, *tmp;
        // while (cur != NULL) {
        //     tmp = pre->next;
        //     pre->next = cur;
        //     cur = cur->next;
        //     pre->next->next = tmp;
        // }
        // return pre->next;

        // 递归
        if (!head || !head->next) {
            return head;
        }
        ListNode* item = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return item;
    }
};
// @lc code=end
