// Source: https://leetcode.com/problems/buddy-strings/description/
// Author: Diego Lee
// Date: 2018-09-21
//
// Description:
// Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.
//
// Example 1:
//
// Input: A = "ab", B = "ba"
// Output: true
// Example 2:
//
// Input: A = "ab", B = "ab"
// Output: false
// Example 3:
//
// Input: A = "aa", B = "aa"
// Output: true
// Example 4:
//
// Input: A = "aaaaaaabc", B = "aaaaaaacb"
// Output: true
// Example 5:
//
// Input: A = "", B = "aa"
// Output: false
//
//
// Note:
//
// 0 <= A.length <= 20000
// 0 <= B.length <= 20000
// A and B consist only of lowercase letters.
//

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

class Solution {
    public:
        bool buddyStrings(std::string A, std::string B) {
            if (A.size() != B.size() || A.size() <= 1) {
                return false;
            }

            bool result = false;
            if (A == B) {
                std::vector<int> counter(26, 0);
                for (size_t i = 0; i < A.size(); ++i) {
                    ++counter[A[i] - 'a'];
                }
                for (int cnt : counter) {
                    if (cnt > 1) {
                        result = true;
                    }
                }
            }
            else {
                std::vector<int> vecIndex;
                for (size_t i = 0; i < A.size(); ++i) {
                    if (A[i] != B[i]) {
                        vecIndex.push_back(i);
                    }
                }
                result = (vecIndex.size() == 2)
                    && (A[vecIndex[0]] == B[vecIndex[1]])
                    && (A[vecIndex[1]] == B[vecIndex[0]]);
            }
            return result;
        }
};

void testBuddyString() {
    Solution s;
    assert(s.buddyStrings("ab", "ba") == true);
    assert(s.buddyStrings("ab", "ab") == false);
    assert(s.buddyStrings("aa", "aa") == true);
}

int main() {
    testBuddyString();
    return 0;
}
