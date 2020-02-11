/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (50.56%)
 * Likes:    1753
 * Dislikes: 105
 * Total Accepted:    151.3K
 * Total Submissions: 290.7K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * Given a n x n matrix where each of the rows and columns are sorted in
 * ascending order, find the kth smallest element in the matrix.
 * 
 * 
 * Note that it is the kth smallest element in the sorted order, not the kth
 * distinct element.
 * 
 * 
 * Example:
 * 
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 * 
 * return 13.
 * 
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ n^2.
 */

// @lc code=start
// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& matrix, int k)
//     {
//         priority_queue<int> q;
//         for (int i = 0; i < matrix.size(); i++) {
//             for (int j = 0; j < matrix[0].size(); j++) {
//                 q.push(matrix[i][j]);
//                 if (q.size() > k) {
//                     q.pop();
//                 }
//             }
//         }
//         return q.top();
//     }
// };

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        // priority_queue<int> q;
        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix[0].size();j++){
        //         q.push(matrix[i][j]);
        //         if(q.size() > k){
        //             q.pop();
        //         }
        //     }
        // }
        // return q.top();

        int left = matrix[0][0], right = matrix.back().back();
        while (left < right) {
            int mid = (left + right) / 2;
            int cnt = 0;

            for (int i = 0; i < matrix.size(); i++) {
                if (matrix[i].back() <= mid) {
                    cnt += matrix[i].size();
                } else if (matrix[i][0] <= mid) {
                    int j = 0;
                    while (mid >= matrix[i][j]) {
                        cnt++;
                        j++;
                    }
                }
            }
            if (cnt < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
// @lc code=end
