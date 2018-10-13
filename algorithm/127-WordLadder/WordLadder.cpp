// Source: https://leetcode.com/problems/word-ladder/description/
// Author: Diego Lee
// Date: 2018-10-13
//
// Description:
// Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
//
// Only one letter can be changed at a time.
// Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
// Note:
//
// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
// You may assume no duplicates in the word list.
// You may assume beginWord and endWord are non-empty and are not the same.
// Example 1:
//
// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
//
// Output: 5
//
// Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
// Example 2:
//
// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
//
// Output: 0
//
// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <cassert>

class Solution {
    public:
        int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
            std::unordered_set<std::string> dict;
            for (auto word : wordList) {
                dict.insert(word);
            }
            dict.insert(beginWord);
            std::vector<std::string> neighbors;
            findNeighbors(beginWord, dict, neighbors);
            int dist = 2;
            while (!neighbors.empty()) {
                std::vector<std::string> curr;
                curr.swap(neighbors);
                for (const std::string& neighbor : curr) {
                    if (neighbor == endWord) {
                        return dist;
                    }
                    findNeighbors(neighbor, dict, neighbors);
                }
                ++dist;
            }
            return 0;
        }

        void findNeighbors(std::string word, std::unordered_set<std::string>& dict,
                std::vector<std::string>& neighbors) {
            dict.erase(word);
            for (size_t i = 0; i < word.size(); ++i) {
                char letter = word[i];
                for (int j = 0; j < 26; ++j) {
                    word[i] = 'a' + j;
                    if (dict.find(word) != dict.end()) {
                        neighbors.push_back(word);
                        dict.erase(word);
                    }
                }
                word[i] = letter;
            }
        }
};

void testLadderLength() {
    std::string beginWord = "hit";
    std::string endWord = "cog";
    std::vector<std::string> wordList = {"hot","dot","dog","lot","log","cog"};
    Solution s;
    int result = s.ladderLength(beginWord, endWord, wordList);
    assert(result == 5);
}

int main() {
    testLadderLength();
    return 0;
}
