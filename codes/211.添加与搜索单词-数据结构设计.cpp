/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 *
 * https://leetcode-cn.com/problems/add-and-search-word-data-structure-design/description/
 *
 * algorithms
 * Medium (42.61%)
 * Likes:    113
 * Dislikes: 0
 * Total Accepted:    9.8K
 * Total Submissions: 22.3K
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * 设计一个支持以下两种操作的数据结构：
 * 
 * void addWord(word)
 * bool search(word)
 * 
 * 
 * search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 可以表示任何一个字母。
 * 
 * 示例:
 * 
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 * 
 * 
 * 说明:
 * 
 * 你可以假设所有单词都是由小写字母 a-z 组成的。
 * 
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class WordDictionary {
public:
    class Node {
    public:
        bool isWord;
        Node* child[26];
        Node()
            : isWord(false)
        {
            for (int i = 0; i < 26; ++i) {
                child[i] = NULL;
            }
        }
        ~Node() {}
    };

private:
    Node* root;

public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
        root = new Node();
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        Node* cur = root;
        for (auto& a : word) {
            int i = a - 'a';
            if (!cur->child[i]) {
                cur->child[i] = new Node();
            }
            cur = cur->child[i];
        }
        cur->isWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        Node* cur = root;
        return find(word, cur, 0);
    }

    bool find(string word, Node* cur, int i)
    {
        if (i == word.size()) {
            return cur->isWord;
        }
        if (word[i] == '.') {
            for (auto& a : cur->child) {
                if (a && find(word, a, i + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            return cur->child[word[i] - 'a'] && find(word, cur->child[word[i] - 'a'], i + 1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
