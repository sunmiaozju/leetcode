/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (51.16%)
 * Likes:    1046
 * Dislikes: 131
 * Total Accepted:    126.9K
 * Total Submissions: 241.4K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the
 * lists is not allowed.
 * 
 * 
 * 
 * Example:
 * 
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
 * 
 * 
 */

// @lc code=start

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        stack<int> sum1, sum2;
        while (l1) {
            sum1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            sum2.push(l2->val);
            l2 = l2->next;
        }

        ListNode* pre = new ListNode(0);
        int sum = 0;
        while (!sum1.empty() || !sum2.empty()) {

            if (!sum1.empty()) {
                sum += sum1.top();
                sum1.pop();
            }

            if (!sum2.empty()) {
                sum += sum2.top();
                sum2.pop();
            }

            ListNode *item = new ListNode(sum % 10), *tail = pre->next;
            pre->next = item;
            pre->next->next = tail;
            sum = sum / 10;
        }

        if (sum) {
            ListNode *item = new ListNode(sum), *tail = pre->next;
            pre->next = item;
            pre->next->next = tail;
        }

        return pre->next == NULL ? new ListNode(0) : pre->next;
    }
};
// @lc code=end
