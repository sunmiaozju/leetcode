/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (40.40%)
 * Likes:    2313
 * Dislikes: 41
 * Total Accepted:    236.9K
 * Total Submissions: 545K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * Example:
 * 
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");   
 * trie.search("app");     // returns true
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 * 
 * 
 */

// @lc code=start
class TrieNode {
public:
    TrieNode* child[26];
    bool isWord;
    TrieNode()
        : isWord(false)
    {
        for (auto& a : child) {
            a = NULL;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode* node = root;
        for (auto& a : word) {
            int i = a - 'a';

            if (!node->child[i]) {
                node->child[i] = new TrieNode();
            }
            node = node->child[i];
        }
        node->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode* node = root;
        for (auto& a : word) {
            int i = a - 'a';
            if (!node->child[i]) {
                return false;
            }
            node = node->child[i];
        }
        return node->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode* node = root;
        for (auto& a : prefix) {
            int i = a - 'a';
            if (!node->child[i]) {
                return false;
            }
            node = node->child[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
