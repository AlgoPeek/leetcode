// Source: https://leetcode.com/problems/length-of-last-word/description/
// Author: Diego Lee
// Date: 2018-07-28
//
// Description:
// Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
//  return the length of last word in the string.
//
// If the last word does not exist, return 0.
//
// Note: A word is defined as a character sequence consists of non-space characters only.
//
// Example:
//
// Input: "Hello World"
// Output: 5

#include <assert.h>
#include <iostream>
#include <string>

class Solution
{
    public:
        int lengthOfLastWord(const std::string& s)
        {
            int i = s.size() - 1;
            while (i >= 0 && s[i] == ' ')
            {
                --i;
            }
            std::string str = i >= 0 ? s.substr(0, i + 1) : "";
            size_t pos = str.find_last_of(' ');
            return pos == std::string::npos ? str.size() : str.substr(pos + 1).size();
        }
};

void testLengthOfLastWord()
{
    Solution s;
    std::string str = "Hello World";
    int r = s.lengthOfLastWord(str);
    assert(r == 5);

    str = "a ";
    r = s.lengthOfLastWord(str);
    assert(r == 1);

    str = "hello";
    r = s.lengthOfLastWord(str);
    assert(r == 5);

    str = " hello";
    r = s.lengthOfLastWord(str);
    assert(r == 5);
}

int main()
{
    testLengthOfLastWord();
    return 0;
}
