/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (36.37%)
 * Likes:    987
 * Dislikes: 59
 * Total Accepted:    254.4K
 * Total Submissions: 696.4K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example:
 * 
 * 
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val)
    {
        // ListNode* ans = head;
        // ListNode* pre = NULL;
        // bool have_one = false;
        // while (head != NULL) {
        //     if (head->val == val) {
        //         if (pre != NULL) {
        //             pre->next = head->next;
        //         }
        //         head = head->next;
        //     } else {
        //         if (!have_one) {
        //             ans = head;
        //             have_one = true;
        //         }
        //         pre = head;
        //         head = head->next;
        //     }
        // }

        // return have_one ? ans : NULL;

        if (head == NULL) {
            return head;
        }

        ListNode* p = head;

        while (p->next != NULL) {
            if (p->next->val == val) {
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }
        if (head->val == val) {
            head = head->next;
        }
        return head;
    }
};
// @lc code=end
