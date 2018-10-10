// Source: https://leetcode.com/problems/palindrome-partitioning/description/
// Author: Diego Lee
// Date: 2018-10-10
//
// Description:
// Given a string s, partition s such that every substring of the partition is a palindrome.
//
// Return all possible palindrome partitioning of s.
//
// Example:
//
// Input: "aab"
// Output:
// [
//   ["aa","b"],
//   ["a","a","b"]
// ]

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

class Solution {
    public:
        std::vector<std::vector<std::string>> partition(std::string s) {
            std::vector<std::vector<std::string>> result;
            for (int i = 1, len = s.size(); i <= len; ++i) {
                std::string part = s.substr(0, i);
                if (isPalindrome(part)) {
                    if (i == len) {
                        result.push_back(std::vector<std::string>({part}));
                    }
                    else {
                        std::vector<std::vector<std::string>> curr = partition(s.substr(i, len - i));
                        if (!curr.empty()) {
                            for (size_t j = 0; j < curr.size(); ++j) {
                                curr[j].insert(curr[j].begin(), part);
                                result.push_back(curr[j]);
                            }
                        }
                    }
                }
            }
            return result;
        }

        bool isPalindrome(const std::string& s) {
            int left = 0;
            int right = s.size() - 1;
            while (left <= right) {
                if (s[left++] != s[right--]) {
                    return false;
                }
            }
            return true;
        }
};

void testPartition() {
    Solution s;
    std::vector<std::vector<std::string>> result = s.partition("aab");
    assert(result.size() == 2);
    assert(result[0] == std::vector<std::string>({"a", "a", "b"}));
    assert(result[1] == std::vector<std::string>({"aa", "b"}));
}

int main() {
    testPartition();
}
