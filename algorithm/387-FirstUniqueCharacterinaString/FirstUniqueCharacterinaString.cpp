// Source: https://leetcode.com/problems/first-unique-character-in-a-string/description/
// Author: Diego Lee
// Date: 2018-08-23
//
// Description:
// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
//
// Examples:
//
// s = "leetcode"
// return 0.
//
// s = "loveleetcode",
// return 2.
// Note: You may assume the string contain only lowercase letters.

#include <iostream>
#include <cassert>
#include <string>
#include <vector>

class Solution
{
    public:
        int firstUniqChar(std::string s)
        {
            std::vector<int> hash(128);
            for (auto c : s)
            {
                ++hash[c];
            }
            for (size_t i = 0, len = s.size(); i < len; ++i)
            {
                if (hash[s[i]] == 1)
                {
                    return i;
                }
            }
            return -1;
        }
};

void testFirstUniqChar()
{
    Solution s;
    int result = s.firstUniqChar("leetcode");
    assert(result == 0);

    result = s.firstUniqChar("loveleetcode");
    assert(result == 2);
}

int main()
{
    testFirstUniqChar();
    return 0;
}
