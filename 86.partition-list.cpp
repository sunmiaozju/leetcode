/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (38.34%)
 * Likes:    835
 * Dislikes: 222
 * Total Accepted:    181.8K
 * Total Submissions: 469.6K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 * 
 * Example:
 * 
 * 
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
 * 
 * 
 */

// @lc code=start

#include <iostream>
#include <queue>

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
    ListNode* partition(ListNode* head, int x)
    {
        //     if (!head) {
        //         return NULL;
        //     }
        //     queue<int> q;
        //     ListNode *pre = new ListNode(0), *ans;
        //     pre->next = head;
        //     bool start = false;
        //     while (pre && pre->next) {
        //         if (pre->next->val < x) {
        //             if (!start) {
        //                 ans = pre->next;
        //                 start = true;
        //             }
        //             pre = pre->next;
        //         } else {
        //             q.push(pre->next->val);
        //             pre->next = pre->next->next;
        //         }
        //     }
        //     if (!start) {
        //         return head;
        //     }
        //     ListNode* item;
        //     int num = q.size();
        //     for (size_t i = 0; i < num; i++) {
        //         item = new ListNode(q.front());
        //         q.pop();
        //         pre->next = item;
        //         pre = pre->next;
        //     }
        //     return ans;
        // }

        ListNode *l1 = new ListNode(0), *l2 = new ListNode(0);
        ListNode *l1_pre = l1, *l2_pre = l2;
        while (head) {
            if (head->val < x) {
                l1->next = head;
                l1 = l1->next;
            } else {
                l2->next = head;
                l2 = l2->next;
            }
            head = head->next;
        }
        l2->next = NULL;
        l1->next = l2_pre->next;
        return l1_pre->next;
    }
};
// @lc code=end
