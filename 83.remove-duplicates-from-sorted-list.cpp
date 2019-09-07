/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (43.24%)
 * Likes:    894
 * Dislikes: 86
 * Total Accepted:    359.5K
 * Total Submissions: 830.1K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a sorted linked list, delete all duplicates such that each element
 * appear only once.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->1->2
 * Output: 1->2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->2->3->3
 * Output: 1->2->3
 * 
 * 
 */
#include <iostream>

using namespace std;
//   Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(NULL)
    {
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        int pre_num = head->val;
        head = head->next;
        while (head->next != NULL) {
            if (head->val == pre_num) {
                        }
        }
    }
};
