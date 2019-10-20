/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (34.01%)
 * Likes:    1067
 * Dislikes: 88
 * Total Accepted:    204.8K
 * Total Submissions: 596.1K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->1->2->3
 * Output: 2->3
 * 
 * 
 */

// @lc code=start

#include <iostream>
#include <unordered_map>

using namespace std;

// //   Definition for singly-linked list.
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
    ListNode* deleteDuplicates(ListNode* head)
    {
        // 对于非排序链表可以使用
        // if (head == NULL) {
        //     return NULL;
        // }
        // unordered_map<int, int> myMap;
        // ListNode* cur = head;

        // myMap[cur->val] = 1;
        // while (cur && cur->next) {
        //     if (myMap.find(cur->next->val) == myMap.end()) {
        //         myMap[cur->next->val] = 1;
        //         cur = cur->next;
        //     } else {
        //         myMap[cur->next->val] = 2;
        //         cur->next = cur->next->next;
        //     }
        // }
        // while (head && myMap[head->val] == 2) {
        //     head = head->next;
        // }
        // cur = head;
        // while (cur && cur->next) {
        //     if (myMap[cur->next->val] == 2) {
        //         cur->next = cur->next->next;
        //     } else {
        //         cur = cur->next;
        //     }
        // }
        // return head;
        if (!head) {
            return NULL;
        }
        bool del = false, start = true;
        ListNode *pre = new ListNode(0), *ans;
        pre->next = head;

        while (pre->next && pre->next->next) {
            if (pre->next->val == pre->next->next->val) {
                del = true;
                pre->next->next = pre->next->next->next;
            } else if (del && pre->next->val != pre->next->next->val) {
                pre->next = pre->next->next;
                del = false;
            } else if (pre->next->val != pre->next->next->val) {
                if (start) {
                    ans = pre->next;
                    start = false;
                }
                pre = pre->next;
            }
        }
        if (del) {
            pre->next = pre->next->next;
        }

        return start ? pre->next : ans;
    }
};
// @lc code=end
