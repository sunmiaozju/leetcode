/*
 * @lc app=leetcode id=677 lang=cpp
 *
 * [677] Map Sum Pairs
 *
 * https://leetcode.com/problems/map-sum-pairs/description/
 *
 * algorithms
 * Medium (52.18%)
 * Likes:    394
 * Dislikes: 71
 * Total Accepted:    33.8K
 * Total Submissions: 64.1K
 * Testcase Example:  '["MapSum", "insert", "sum", "insert", "sum"]\n[[], ["apple",3], ["ap"], ["app",2], ["ap"]]'
 *
 * 
 * Implement a MapSum class with insert, and sum methods.
 * 
 * 
 * 
 * For the method insert, you'll be given a pair of (string, integer). The
 * string represents the key and the integer represents the value. If the key
 * already existed, then the original key-value pair will be overridden to the
 * new one.
 * 
 * 
 * 
 * For the method sum, you'll be given a string representing the prefix, and
 * you need to return the sum of all the pairs' value whose key starts with the
 * prefix.
 * 
 * 
 * Example 1:
 * 
 * Input: insert("apple", 3), Output: Null
 * Input: sum("ap"), Output: 3
 * Input: insert("app", 2), Output: Null
 * Input: sum("ap"), Output: 5
 * 
 * 
 * 
 */

// @lc code=start
class mapNode {
public:
    mapNode* child[26];
    int isWord, sum;
    mapNode()
        : isWord(0)
        , sum(0)
    {
        for (auto& a : child) {
            a = NULL;
        }
    }
};

class MapSum {
public:
    mapNode* root;
    /** Initialize your data structure here. */
    MapSum()
    {
        root = new mapNode();
    }

    void insert(string key, int val)
    {
        mapNode* node = root;
        for (auto& a : key) {
            int i = a - 'a';
            if (!node->child[i]) {
                node->child[i] = new mapNode();
            }
            node = node->child[i];
            node->sum += val;
        }

        if (node->isWord) {
            int num = node->isWord;
            mapNode* node = root;
            for (auto& a : key) {
                int i = a - 'a';
                node = node->child[i];
                node->sum -= num;
            }
        }
        node->isWord = val;
    }

    int sum(string prefix)
    {
        mapNode* node = root;
        for (auto& a : prefix) {
            int i = a - 'a';
            if (!node->child[i]) {
                return 0;
            }
            node = node->child[i];
        }
        return node->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end
