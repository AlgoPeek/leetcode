// Source: https://leetcode.com/problems/isomorphic-strings/description/
// Author: Diego Lee
// Date: 2018-07-25
//
// Description:
// Given two strings s and t, determine if they are isomorphic.
// Two strings are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
//
// Example 1:
// Input: s = "egg", t = "add"
// Output: true
//
// Example 2:
// Input: s = "foo", t = "bar"
// Output: false
//
// Example 3:
// Input: s = "paper", t = "title"
// Output: true
//
// Note:
// You may assume both s and t have the same length.

#include <iostream>
#include <string>
#include <cassert>
#include <vector>

class Solution
{
    public:
        bool isIsomorphic(std::string s, std::string t)
        {
            if (s.size() != t.size())
            {
                return false;
            }

            bool result = true;
            std::vector<int> hash_s(128);
            std::vector<int> hash_t(128);
            for (int i = 0; i < s.size(); ++i)
            {
                if (hash_s[s[i]] != hash_t[t[i]])
                {
                    result = false;
                    break;
                }
                hash_s[s[i]] = i + 1;
                hash_t[t[i]] = i + 1;
            }
            return result;
        }
};

void testIsIsomorphic()
{
    Solution s;
    assert(s.isIsomorphic("egg", "add") == true);
    assert(s.isIsomorphic("foo", "bar") == false);
    assert(s.isIsomorphic("paper", "title") == true);
}

int main()
{
    testIsIsomorphic();
    return 0;
}
