// Source: https://leetcode.com/problems/interleaving-string/description/
// Author: Diego Lee
// Date: 2018-10-04
//
// Description:
// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
// Example 1:
//
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true
// Example 2:
//
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false

#include <iostream>
#include <string>
#include <cassert>
#include <stack>

struct Index {
    int i;
    int j;
    int k;
    Index() {}
    Index(int _i, int _j, int _k) :
        i(_i), j(_j), k(_k) {}
};

class Solution {
    public:
        bool isInterleave(std::string s1, std::string s2, std::string s3) {
            int i = 0, j = 0, k = 0;
            int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
            std::stack<Index> S;
            while (k < len3) {
                if (i < len1 && s1[i] == s3[k]
                    && j < len2 && s2[j] == s3[k]) {
                    S.push(Index(i, j, k));
                    ++i;
                }
                else if (i < len1 && s1[i] == s3[k]) {
                    ++i;
                }
                else if (j < len2 && s2[j] == s3[k]) {
                    ++j;
                }
                else {
                    if (S.empty()) {
                        break;
                    }
                    else {
                        Index& ind = S.top();
                        i = ind.i;
                        j = ind.j;
                        k = ind.k;
                        S.pop();
                        ++j;
                    }
                }
                ++k;
            }
            return (i == len1) && (j == len2) && (k == len3);
        }
};

void testIsInterleaveCase1() {
    std::string s1 = "aabcc";
    std::string s2 = "dbbca";
    std::string s3 = "aadbbcbcac";
    assert(Solution().isInterleave(s1, s2, s3) == true);
}

void testIsInterleaveCase2() {
    std::string s1 = "aabcc";
    std::string s2 = "dbbca";
    std::string s3 = "aadbbbaccc";
    assert(Solution().isInterleave(s1, s2, s3) == false);
}

void RunTest() {
    testIsInterleaveCase1();
    testIsInterleaveCase2();
}

int main() {
    RunTest();
    return 0;
}
