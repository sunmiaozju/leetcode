/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (29.77%)
 * Likes:    1267
 * Dislikes: 442
 * Total Accepted:    267.4K
 * Total Submissions: 896.9K
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 */
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n)
    {
        // vector<bool> isPrimes(n, true);
        // int ans = 0;
        // for (size_t i = 2; i < sqrt(n); ++i) {
        //     if (isPrimes[i]) {
        //         for (size_t j = i * i; j < n; j += i) {
        //             isPrimes[j] = false;
        //         }
        //     }
        // }
        // for (size_t i = 2; i < n; i++) {
        //     if (isPrimes[i]) {
        //         ans++;
        //     }
        // }
        // return ans;

        vector<int> isPrime(n, true);
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (!isPrime[i]) {
                continue;
            }
            count++;
            for (int j = 2; j * i < n; j++) {
                isPrime[i * j] = false;
            }
        }
        return count;
    }
};
