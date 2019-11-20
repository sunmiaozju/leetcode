/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (25.40%)
 * Likes:    2039
 * Dislikes: 942
 * Total Accepted:    324.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 * 
 * 
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * Note:
 * 
 * 
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * Output: 5
 * 
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
 * "dog" -> "cog",
 * return its length 5.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * Output: 0
 * 
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 * 
 * 
 * 
 * 
 * 
 */

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        queue<string> q;
        q.push(beginWord);
        int cnt = 0;
        while (!q.empty()) {
            int nums = q.size();
            cnt++;
            while (nums--) {
                string item = q.front();
                q.pop();
                if (item == endWord) {
                    return cnt;
                }
                for (size_t i = 0; i < wordList.size(); i++) {
                    if (wordList[i] == "") {
                        continue;
                    }
                    int flag = false;
                    for (size_t j = 0; j < item.size(); j++) {
                        if (item[j] != wordList[i][j]) {
                            if (flag == true) {
                                flag = false;
                                break;
                            }
                            flag = true;
                        } else {
                            continue;
                        }
                    }
                    if (flag == true) {
                        q.push(wordList[i]);
                        wordList[i] = "";
                    }
                }
            }
        }
        return 0;
    }
};
// @lc code=end
