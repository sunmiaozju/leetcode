/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (35.95%)
 * Likes:    1519
 * Dislikes: 106
 * Total Accepted:    220.2K
 * Total Submissions: 606.5K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 * 
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
 * 
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
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        // ListNode *pre = new ListNode(0), *cur;
        // pre->next = head;
        // int count = 1;
        // while (true) {
        //     if (count < m) {
        //         pre = pre->next;
        //     } else if (count == m) {
        //         cur = pre->next;
        //     } else if (count > m && count <= n) {
        //         ListNode *tmp = pre->next, *tmp2 = cur->next->next;
        //         pre->next = cur->next;
        //         pre->next->next = tmp;
        //         cur->next = tmp2;
        //     } else if (count > n) {
        //         return m > 1 ? head : pre->next;
        //     }
        //     count++;
        // }
        // return NULL;

        ListNode *pre = new ListNode(0), *cur;
        pre->next = head;
        ListNode* ans = pre;
        for (size_t i = 0; i < m - 1; i++) {
            pre = pre->next;
        }
        cur = pre->next;
        for (size_t i = 0; i < n - m; i++) {
            ListNode* tmp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = tmp;
        }
        return ans->next;
    }
};
// @lc code=end
