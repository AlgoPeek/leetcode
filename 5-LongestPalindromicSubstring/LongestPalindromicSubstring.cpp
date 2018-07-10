// Source: https://leetcode.com/problems/longest-palindromic-substring/description/
// Author: Diego Lee
// Date: 2018-7-10
//
// Description:
// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
// Example 1:
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
//
// Example 2:
// Input: "cbbd"
// Output: "bb"
//

#include <iostream>
#include <cassert>
#include <string>

class Solution
{
    public:
        std::string longestPalindrome(const std::string& s)
        {
            if (s.empty() || s.size() == 1)
            {
                return s;
            }

            std::string longest = s.substr(0, 1);
            for (size_t i = 0; i < s.size(); ++i)
            {
                // Find palindrome with center i
                std::string tmp = findPalindrome(s, i, i);
                if (tmp.size() > longest.size())
                {
                    longest = tmp;
                }

                // Find palindrome with center i, i+1
                tmp = findPalindrome(s, i, i + 1);
                if (tmp.size() > longest.size())
                {
                    longest = tmp;
                }
            }
            return longest;
        }

        std::string findPalindrome(const std::string& s, int L, int R)
        {
            while (L >= 0
                && R < s.size()
                && s[L] == s[R])
            {
                --L;
                ++R;
            }
            return s.substr(L + 1, R - L - 1);
        }
};

void testLongestPalindrome()
{
    Solution s;
    std::string str	= s.longestPalindrome("1");
    assert(str == "1");

    str	= s.longestPalindrome("121");
    assert(str == "121");

    str	= s.longestPalindrome("1221");
    assert(str == "1221");

    str	= s.longestPalindrome("ccc");
    assert(str == "ccc");
}

int main()
{
    testLongestPalindrome();
    return 0;
}
