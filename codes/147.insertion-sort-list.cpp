/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
 *
 * https://leetcode.com/problems/insertion-sort-list/description/
 *
 * algorithms
 * Medium (38.31%)
 * Likes:    418
 * Dislikes: 477
 * Total Accepted:    162.1K
 * Total Submissions: 419.2K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list using insertion sort.
 * 
 * 
 * 
 * 
 * 
 * A graphical example of insertion sort. The partial sorted list (black)
 * initially contains only the first element in the list.
 * With each iteration one element (red) is removed from the input data and
 * inserted in-place into the sorted list
 * 
 * 
 * 
 * 
 * 
 * Algorithm of Insertion Sort:
 * 
 * 
 * Insertion sort iterates, consuming one input element each repetition, and
 * growing a sorted output list.
 * At each iteration, insertion sort removes one element from the input data,
 * finds the location it belongs within the sorted list, and inserts it
 * there.
 * It repeats until no input elements remain.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
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
    ListNode* insertionSortList(ListNode* head)
    {
        ListNode *pre = new ListNode(0), *cur = head;
        while (cur) {
            ListNode* index = pre;
            ListNode* next_tmp = cur->next;
            while (index && index->next) {
                if (cur->val <= index->next->val) {
                    ListNode* tmp = index->next;
                    index->next = cur;
                    index->next->next = tmp;
                    break;
                } else {
                    index = index->next;
                }
            }
            if (!index->next) {
                index->next = cur;
                cur->next = NULL;
            }
            cur = next_tmp;
        }
        return pre->next;
    }
};
// @lc code=end
