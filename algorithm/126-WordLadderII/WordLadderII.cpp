// Source: https://leetcode.com/problems/word-ladder-ii/
// Author: Diego Lee
// Date: 2018-11-03
//
// Description:
// Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
//
// Only one letter can be changed at a time
// Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
// Note:
//
// Return an empty list if there is no such transformation sequence.
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
// Output:
// [
//   ["hit","hot","dot","dog","cog"],
//   ["hit","hot","lot","log","cog"]
// ]
// Example 2:
//
// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
//
// Output: []
//
// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <unordered_set>
#include <queue>

typedef std::vector<std::vector<std::string>> WordMatrix;
typedef std::vector<std::string> WordPath;

class Solution {
    public:
        WordMatrix findLadders(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
            WordMatrix result;
            std::unordered_set<std::string> dict(wordList.begin(), wordList.end());
            std::queue<WordPath> Q;
            dict.insert(beginWord);
            Q.push(WordPath({beginWord}));
            int level = 1;
            int minLevel = INT_MIN;
            std::vector<std::string> visited;
            while (!Q.empty()) {
                WordPath path = Q.front();
                Q.pop();

                // reach a new level
                if (path.size() > level) {
                    for (auto word : visited) {
                        dict.erase(word);
                    }
                    visited.clear();
                    if (path.size() > minLevel) {
                        break;
                    } else {
                        level = path.size();
                    }
                }

                // find neighbor paths
                std::vector<WordPath> neighborPaths;
                findNeighborPaths(path, dict, visited, neighborPaths);
                for (const WordPath& path : neighborPaths) {
                    if (path.back() == endWord) {
                        minLevel = level;
                        result.push_back(path);
                    } else {
                        Q.push(path);
                    }
                }
            }
            return result;
        }

        void findNeighborPaths(const WordPath& currPath, std::unordered_set<std::string>& dict,
                std::vector<std::string>& visited, std::vector<WordPath>& neighborPaths) {
            if (currPath.empty()) {
                return;
            }

            std::string word = currPath.back();
            for (size_t i = 0; i < word.size(); ++i) {
                char letter = word[i];
                for (size_t j = 0; j < 26; ++j) {
                    word[i] = 'a' + j;
                    if (dict.find(word) != dict.end()) {
                        WordPath newPath = currPath;
                        newPath.push_back(word);
                        visited.push_back(word);
                        neighborPaths.push_back(newPath);
                    }
                }
                word[i] = letter;
            }
        }
};

void testFindLaddersCase1() {
    std::string beginWord = "hit";
    std::string endWord = "cog";
    std::vector<std::string> wordList = {"hot","dot","dog","lot","log","cog"};
    std::vector<std::vector<std::string>> result = Solution().findLadders(beginWord, endWord, wordList);
    assert(result.size() == 2);
    assert(result[0] == std::vector<std::string>({"hit","hot","dot","dog","cog"}));
    assert(result[1] == std::vector<std::string>({"hit","hot","lot","log","cog"}));
}

void testFindLaddersCase2() {
    std::string beginWord = "hit";
    std::string endWord = "cog";
    std::vector<std::string> wordList = {"hot","dot","dog","lot","log"};
    std::vector<std::vector<std::string>> result = Solution().findLadders(beginWord, endWord, wordList);
    assert(result.empty() == true);
}

void testFindLadders() {
    testFindLaddersCase1();
    testFindLaddersCase2();
}

int main() {
    testFindLadders();
    return 0;
}
