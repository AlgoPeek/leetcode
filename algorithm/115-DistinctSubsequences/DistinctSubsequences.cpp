// Source: https://leetcode.com/problems/distinct-subsequences/
// Author: Diego Lee
// Date: 2018-10-26
//
// Description:
// Given a string S and a string T, count the number of distinct subsequences of S which equals T.
//
// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
//
// Example 1:
//
// Input: S = "rabbbit", T = "rabbit"
// Output: 3
// Explanation:
//
// As shown below, there are 3 ways you can generate "rabbit" from S.
// (The caret symbol ^ means the chosen letters)
//
// rabbbit
// ^^^^ ^^
// rabbbit
// ^^ ^^^^
// rabbbit
// ^^^ ^^^
// Example 2:
//
// Input: S = "babgbag", T = "bag"
// Output: 5
// Explanation:
//
// As shown below, there are 5 ways you can generate "bag" from S.
// (The caret symbol ^ means the chosen letters)
//
// babgbag
// ^^ ^
// babgbag
// ^^    ^
// babgbag
// ^    ^^
// babgbag
//   ^  ^^
// babgbag
//     ^^^

#include <iostream>
#include <string>
#include <cassert>
#include <vector>

class Solution {
    public:
        int numDistinct(std::string s, std::string t) {
            size_t tlen = t.size();
            size_t slen = s.size();
            std::vector<std::vector<int>> dp;
            for (size_t i = 0; i < tlen + 1; ++i) {
                dp.push_back(std::vector<int>(slen + 1, 0));
            }
            for (size_t j = 0; j < slen + 1; ++j) {
                dp[0][j] = 1;
            }

            for (size_t i = 0; i < tlen; ++i) {
                for (size_t j = 0; j < slen; ++j) {
                    if (t[i] == s[j]) {
                        dp[i+1][j+1] = dp[i+1][j] + dp[i][j];
                    }
                    else {
                        dp[i+1][j+1] = dp[i+1][j];
                    }
                }
            }
            return dp[tlen][slen];
        }
};

void testNumDistinct() {
    std::string s = "rabbbit";
    std::string t = "rabbit";
    int result = Solution().numDistinct(s, t);
    assert(result == 3);
}

int main() {
    testNumDistinct();
    return 0;
}
