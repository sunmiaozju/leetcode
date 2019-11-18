/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (49.64%)
 * Likes:    2567
 * Dislikes: 196
 * Total Accepted:    465.5K
 * Total Submissions: 918.1K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        // ????nth_element
        // nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), cmp);
        // return nums[k - 1];

        // ????partial_sort
        // partial_sort(nums.begin(), nums.begin() + k, nums.end(), cmp);
        // return nums[k - 1];

        // ??????priority_queue ????????K?????
        // priority_queue<int, vector<int>, greater<int>> pq;
        // for (size_t i = 0; i < nums.size(); i++) {
        //     if (pq.size() < k) {
        //         pq.push(nums[i]);
        //     } else if (pq.top() < nums[i]) {
        //         pq.push(nums[i]);
        //         pq.pop();
        //     }
        // }
        // return pq.top();

        // ???? ??proirity_queue????????????k-1?
        // priority_queue<int> pq(nums.begin(), nums.end());
        // for (size_t i = 0; i < k - 1; i++) {
        //     pq.pop();
        // }
        // return pq.top();

        // ????
        // multiset<int> mset;
        // for (auto num : nums) {
        //     if (mset.size() < k) {
        //         mset.insert(num);
        //     } else if (*mset.begin() < num) {
        //         mset.insert(num);
        //         mset.erase(mset.begin());
        //     }
        // }
        // return *mset.begin();

        // ????
        // multiset<int, greater<int>> mset;
        // for (auto num : nums) {
        //     mset.insert(num);
        // }
        // for (size_t i = 0; i < k - 1; i++) {
        //     mset.erase(mset.begin());
        // }
        // return *mset.begin();

        // ????????????
        // int left = 0, right = nums.size() - 1;
        // while (left <= right) {
        //     int index = quicksort(nums, left, right);
        //     if (index == k - 1) {
        //         return nums[index];
        //     } else if (k - 1 < index) {
        //         right = index - 1;
        //     } else {
        //         left = index + 1;
        //     }
        // }
        // return -1;

        // ???? ??????????
        int heapSize = nums.size();
        for (int i = (nums.size() - 1) / 2; i >= 0; i--) {
            maxHeapify(nums, i, heapSize);
        }
        for (size_t i = 0; i < k - 1; i++) {
            swap(nums[0], nums[--heapSize]);
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }
    void maxHeapify(vector<int>& nums, int i, int heapSize)
    {
        int largest = i, left = 2 * i + 1, right = 2 * i + 2;
        if (left < heapSize && nums[left] > nums[largest]) {
            largest = left;
        }
        if (right < heapSize && nums[right] > nums[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(nums[largest], nums[i]);
            maxHeapify(nums, largest, heapSize);
        }
    }
    // int quicksort(vector<int>& nums, int left, int right)
    // {
    //     int ll = left + 1, rr = right;
    //     int item = nums[left];
    //     while (ll <= rr) {
    //         if (nums[ll] <= item && nums[rr] >= item) {
    //             swap(nums[ll++], nums[rr--]);
    //         } else {
    //             if (nums[ll] >= item) {
    //                 ll++;
    //             }
    //             if (nums[rr] <= item) {
    //                 rr--;
    //             }
    //         }
    //     }
    //     swap(nums[left], nums[ll - 1]);
    //     return ll - 1;
    // }
};
// @lc code=end
