/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (48.72%)
 * Likes:    611
 * Dislikes: 0
 * Total Accepted:    107.5K
 * Total Submissions: 211.5K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
 * 
 */

// @lc code=start

//   Definition for singly-linked list.

#include <bits/stdc++.h>

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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.empty()) {
            return NULL;
        }
        return help(lists, 0, lists.size() - 1);
    }

    ListNode* help(vector<ListNode*>& lists, int left, int right)
    {
        if (left == right) {
            return lists[left];
        }

        int mid = left + (right - left) / 2;

        ListNode* lnode = help(lists, left, mid);
        ListNode* rnode = help(lists, mid + 1, right);

        // 合并两个链表
        ListNode *pre = new ListNode(0), *pre_origin = pre;
        while (lnode && rnode) {
            if (lnode->val <= rnode->val) {
                pre->next = lnode;
                lnode = lnode->next;
            } else {
                pre->next = rnode;
                rnode = rnode->next;
            }
            pre = pre->next;
        }
        if (lnode) {
            pre->next = lnode;
        } else {
            pre->next = rnode;
        }
        return pre_origin->next;
    }
};
// @lc code=end
