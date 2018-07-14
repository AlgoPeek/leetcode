// Source: https://leetcode.com/problems/regular-expression-matching/description/
// Author: Diego Lee
// Date: 2018-07-12
//
// Description:
// Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).
//
// Note:
// s could be empty and contains only lowercase letters a-z.
// p could be empty and contains only lowercase letters a-z, and characters like . or *.
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
// p = "a*"
// Output: true
// Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
//
// Example 3:
// Input:
// s = "ab"
// p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".
//
// Example 4:
// Input:
// s = "aab"
// p = "c*a*b"
// Output: true
// Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
//
// Example 5:
// Input:
// s = "mississippi"
// p = "mis*is*p*."
// Output: false
//

#include <iostream>
#include <cassert>
#include <string>

class Solution
{
    public:
        bool isMatch(std::string s, std::string p)
        {
            if (p.empty())
            {
                return s.empty();
            }

            bool firstMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');
            if (p.size() >= 2 && p[1] == '*')
            {
                return isMatch(s, p.substr(2)) || (firstMatch && isMatch(s.substr(1), p));
            }
            else
            {
                return firstMatch && isMatch(s.substr(1), p.substr(1));
            }
        }
};

void testIsMatch(void)
{
    Solution s;
    assert(s.isMatch("aa", "a") == false);
    assert(s.isMatch("aa", "a*") == true);
    assert(s.isMatch("ab", ".*") == true);
    assert(s.isMatch("aab", "c*a*b") == true);
    assert(s.isMatch("mississippi", "mis*is*p*.") == false);
}

int main()
{
    testIsMatch();
    return 0;
}
