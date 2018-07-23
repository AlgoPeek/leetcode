// Source: https://leetcode.com/problems/valid-anagram/description/
// Author: Diego Lee
// Date: 2018-07-24
//
// Description:
// Given two strings s and t , write a function to determine if t is an anagram of s.
//
// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true
//
// Example 2:
// Input: s = "rat", t = "car"
// Output: false
//
// Note:
// You may assume the string contains only lowercase alphabets.
//
// Follow up:
// What if the inputs contain unicode characters? How would you adapt your solution to such case?

#include <iostream>
#include <algorithm>
#include <cassert>
#include <string>

class Solution
{
    public:
        bool isAnagram(std::string s, std::string t)
        {
            if (s.size() != t.size())
            {
                return false;
            }

            std::sort(s.begin(), s.end());
            std::sort(t.begin(), t.end());

            size_t i = 0;
            while (i < s.size() && s[i] == t[i])
            {
                ++i;
            }
            return (i == s.size());
        }
};

void testIsAnagram()
{
    Solution s;
    assert(s.isAnagram("anagram", "nagaram") == true);
    assert(s.isAnagram("rat", "car") == false);
}

int main()
{
    testIsAnagram();
    return 0;
}
