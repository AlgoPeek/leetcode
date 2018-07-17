// Source: https://leetcode.com/problems/wildcard-matching/description/
// Author: Diego Lee
// Date: 2018-07-17
//
// Description:
// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).
//
// Note:
// s could be empty and contains only lowercase letters a-z.
// p could be empty and contains only lowercase letters a-z, and characters like ? or *.
//
// Example 1:
// Input:
// s = "aa"
// p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
//
// Example 2:
// Input:
// s = "aa"
// p = "*"
// Output: true
// Explanation: '*' matches any sequence.
//
// Example 3:
// Input:
// s = "cb"
// p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
//
// Example 4:
// Input:
// s = "adceb"
// p = "*a*b"
// Output: true
// Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
//
// Example 5:
// Input:
// s = "acdcb"
// p = "a*c?b"
// Output: false

#include <string>
#include <iostream>
#include <vector>

class Solution
{
    public:
        bool isMatch(std::string s, std::string p)
        {
            int m = static_cast<int>(s.size());
            int n = static_cast<int>(p.size());
            std::vector<std::vector<bool>> dp;
            for (int i = 0; i < m + 1; ++i)
            {
                dp.push_back(std::vector<bool>(n + 1 )) ;
            }

            dp[0][0] = true;
            for (int j = 1; j <= n; ++j)
            {
                dp[0][j] = dp[0][j-1] && (p[j - 1] == '*');
            }

            for (int i = 1; i <= m; ++i)
            {
                for (int j = 1; j <= n; ++j)
                {
                    if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    else if (p[j - 1] == '*')
                    {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                    }
                }
            }
            return dp[m][n];
        }

        bool isMatchByRecursive(std::string s, std::string p)
        {
            if (p.empty())
            {
                return s.empty();
            }

            //std::cout << "s=" << s << ", p=" << p << std::endl;
            if (p[0] == '*')
            {
                int dup = 1;
                int i = 1;
                while (i < p.size() && p[i++] == '*')
                {
                    ++dup;
                }

                if (s.empty())
                {
                    return isMatch(s, p.substr(dup));
                }
                else
                {
                    return isMatch(s, p.substr(dup)) || isMatch(s.substr(1), p);
                }
            }
            else
            {
                bool firstMatch = !s.empty() && (s[0] == p[0] || p[0] == '?');
                return firstMatch && isMatch(s.substr(1), p.substr(1));
            }
        }
};

void testIsMatch()
{
    Solution s;
    assert(s.isMatch("aa", "a") == false);
    assert(s.isMatch("aa", "*") == true);
    assert(s.isMatch("cb", "?a") == false);
    assert(s.isMatch("adceb", "*a*b") == true);
    assert(s.isMatch("acdcb", "a*c?b") == false);
    assert(s.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b") == false);
}

int main()
{
    testIsMatch();
    return 0;
}

