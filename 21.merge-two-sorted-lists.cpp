/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (48.53%)
 * Likes:    2546
 * Dislikes: 367
 * Total Accepted:    659K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <list>
#include <string>

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

class Solution {
public:
    // Solution(){};
    // ~Solution(){};

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        //     ListNode* ans = new ListNode(0);
        //     ListNode* front = ans;
        //     while (true) {
        //         if (l1 != NULL && l2 != NULL) {
        //             if (l1->val <= l2->val) {
        //                 ans->val = l1->val;
        //                 ans->next = l1;
        //                 l1 = l1->next;
        //             } else {
        //                 ans->val = l2->val;
        //                 ans->next = l2;
        //                 l2 = l2->next;
        //             }
        //             ans = ans->next;
        //         } else if (l1 != NULL) {
        //             ans->val = l1->val;
        //             ans->next = l1->next;
        //             break;
        //         } else if (l2 != NULL) {
        //             ans->val = l2->val;
        //             ans->next = l2->next;
        //             break;
        //         } else {
        //             return NULL;
        //         }
        //     }
        //     return front;

        ListNode front(0);
        ListNode* cur = &front;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        return front.next;
    }
};

// int main(int argc, const char** argv)
// {
//     Solution ss;
//     ListNode a1(1), a2(2), a3(3);
//     ListNode b1(1), b2(2), b3(3);

//     a1.next = &a2;
//     a2.next = &a3;
//     b1.next = &b2;
//     b2.next = &b3;

//     ss.mergeTwoLists(&a1, &b1);
//     return 0;
// }
