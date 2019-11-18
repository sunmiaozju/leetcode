/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (36.94%)
 * Likes:    2016
 * Dislikes: 288
 * Total Accepted:    308.2K
 * Total Submissions: 828.4K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 * 
 */

#include <iostream>
#include <stack>

using namespace std;

// @lc code=start
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
    bool isPalindrome(ListNode* head)
    {
        // stack<ListNode*> s;
        // ListNode* cur = head;
        // int num = 0;
        // while (cur) {
        //     num++;
        //     cur = cur->next;
        // }
        // cur = head;
        // int count = 0;

        // while (cur) {
        //     if (count < num / 2) {
        //         s.push(cur);
        //     } else if (count == num / 2 && num % 2 == 1) {
        //         cur = cur->next;
        //         count++;
        //         continue;
        //     } else if (count >= num / 2) {
        //         if (cur->val == s.top()->val) {
        //             s.pop();
        //         } else {
        //             return false;
        //         }
        //     }
        //     count++;
        //     cur = cur->next;
        // }
        // return true;

        ListNode *fast = head, *slow = head, *rev = NULL;
        while (fast && fast->next) {
            fast = fast->next->next;
            ListNode* tmp = slow->next;
            slow->next = rev;
            rev = slow;
            slow = tmp;
        }
        if (fast) {
            slow = slow->next;
        }
        while (rev && slow) {
            if (slow->val != rev->val) {
                return false;
            }
            rev = rev->next;
            slow = slow->next;
        }
        return true;
    }
};
// @lc code=end
