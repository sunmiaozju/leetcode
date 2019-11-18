/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (56.46%)
 * Likes:    2014
 * Dislikes: 130
 * Total Accepted:    268.4K
 * Total Submissions: 467.5K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Note: 
 * 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * 
 * 
 */
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        // heap
        // vector<int> ans;
        // unordered_map<int, int> myMap;
        // for (size_t i = 0; i < nums.size(); i++) {
        //     myMap[nums[i]]++;
        // }
        // priority_queue<pair<int, int>> pq;
        // int count = 0;
        // for (auto i = myMap.begin(); i != myMap.end(); count++, i++) {
        //     pq.push(make_pair(i->second, i->first));
        //     if (pq.size() > myMap.size() - k) {
        //         ans.push_back(pq.top().second);
        //         pq.pop();
        //     }
        // }
        // return ans;

        // 桶排序
        vector<int> ans;
        unordered_map<int, int> myMap;
        for (auto item : nums) {
            myMap[item]++;
        }
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto i = myMap.begin(); i != myMap.end(); i++) {
            bucket[i->second].push_back(i->first);
        }

        for (int i = bucket.size() - 1; i >= 0; i--) {
            for (size_t j = 0; j < bucket[i].size(); j++) {
                ans.push_back(bucket[i][j]);
                if (ans.size() == k)
                    return ans;
            }
        }
        return ans;
    }
};
// @lc code=end
