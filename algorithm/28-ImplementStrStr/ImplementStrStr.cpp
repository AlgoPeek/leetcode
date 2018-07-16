// Source: https://leetcode.com/problems/implement-strstr/description/
// Author: Diego Lee
// Date: 2018-07-16
//
// Description:
// Implement strStr().
// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//
// Example 1:
// Input: haystack = "hello", needle = "ll"
// Output: 2
//
// Example 2:
// Input: haystack = "aaaaa", needle = "bba"
// Output: -1
//
// Clarification:
// What should we return when needle is an empty string? This is a great question to ask during an interview.
// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

#include <iostream>
#include <string>
#include <cassert>

class Solution
{
    public:
        int strStr(std::string haystack, std::string needle)
        {
            if (needle.empty())
            {
                return 0;
            }

            int len = haystack.size() - needle.size();
            for (int i = 0; i < len + 1; ++i)
            {
                int pos = i;
                for (int j = 0; j < needle.size(); ++j)
                {
                    if (haystack[i + j] != needle[j])
                    {
                        pos = -1;
                        break;
                    }
                }
                if (pos != -1)
                {
                    return pos;
                }
            }
            return -1;
        }
};

void testStrStr(void)
{
    Solution s;
    assert(s.strStr("hello", "ll") == 2);
    assert(s.strStr("aaaaa", "bba") == -1);
    assert(s.strStr("a", "a") == 0);
    assert(s.strStr("mississppi", "a") == -1);
}

int main()
{
    testStrStr();
    return 0;
}
