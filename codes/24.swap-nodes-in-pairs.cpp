/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (46.20%)
 * Likes:    1711
 * Dislikes: 152
 * Total Accepted:    401.9K
 * Total Submissions: 837.4K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
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
    ListNode* swapPairs(ListNode* head)
    {
        ListNode *pre = new ListNode(0), *origin = pre;
        pre->next = head;
        while (pre->next && pre->next->next) {
            ListNode *first = pre->next, *tail = pre->next->next->next;
            pre->next = pre->next->next;
            pre->next->next = first;
            pre->next->next->next = tail;
            pre = first;
        }
        return origin->next;
    }
};
// @lc code=end
