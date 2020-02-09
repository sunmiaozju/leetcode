/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
 *
 * https://leetcode.com/problems/split-linked-list-in-parts/description/
 *
 * algorithms
 * Medium (49.66%)
 * Likes:    487
 * Dislikes: 97
 * Total Accepted:    38.7K
 * Total Submissions: 76.5K
 * Testcase Example:  '[1,2,3,4]\n5'
 *
 * Given a (singly) linked list with head node root, write a function to split
 * the linked list into k consecutive linked list "parts".
 * 
 * The length of each part should be as equal as possible: no two parts should
 * have a size differing by more than 1.  This may lead to some parts being
 * null.
 * 
 * The parts should be in order of occurrence in the input list, and parts
 * occurring earlier should always have a size greater than or equal parts
 * occurring later.
 * 
 * Return a List of ListNode's representing the linked list parts that are
 * formed.
 * 
 * 
 * Examples
 * 1->2->3->4, k = 5 // 5 equal parts
 * [ [1], 
 * [2],
 * [3],
 * [4],
 * null ]
 * 
 * Example 1:
 * 
 * Input: 
 * root = [1, 2, 3], k = 5
 * Output: [[1],[2],[3],[],[]]
 * Explanation:
 * The input and each element of the output are ListNodes, not arrays.
 * For example, the input root has root.val = 1, root.next.val = 2,
 * \root.next.next.val = 3, and root.next.next.next = null.
 * The first element output[0] has output[0].val = 1, output[0].next = null.
 * The last element output[4] is null, but it's string representation as a
 * ListNode is [].
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: 
 * root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
 * Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
 * Explanation:
 * The input has been split into consecutive parts with size difference at most
 * 1, and earlier parts are a larger size than the later parts.
 * 
 * 
 * 
 * Note:
 * The length of root will be in the range [0, 1000].
 * Each value of a node in the input will be an integer in the range [0, 999].
 * k will be an integer in the range [1, 50].
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

#include <vector>

using namespace std;

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k)
    {
        ListNode* head = root;
        int num = 0;
        while (head) {
            num++;
            head = head->next;
        }

        int avg = num / k, ext = num % k;
        vector<ListNode*> ans;

        ListNode *origin = new ListNode(0), *tail = root, *pre = origin;
        pre->next = root;

        for (int i = 0; i < k; i++) {
            ans.push_back(tail);
            int avg_1 = avg;

            while (avg_1--) {
                pre = pre->next;
            }
            if (i < ext) {
                pre = pre->next;
            }

            if (pre->next) {
                tail = pre->next;
                pre->next = NULL;
            } else {
                tail = NULL;
            }
            pre = origin;
            pre->next = tail;
        }

        return ans;
    }
};
// @lc code=end