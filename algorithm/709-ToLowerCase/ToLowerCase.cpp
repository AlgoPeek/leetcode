// Source: https://leetcode.com/problems/to-lower-case/description/
// Author: Diego Lee
// Date: 2018-08-08
//
// Description:
// Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.
//
// Example 1:
//
// Input: "Hello"
// Output: "hello"
// Example 2:
//
// Input: "here"
// Output: "here"
// Example 3:
//
// Input: "LOVELY"
// Output: "lovely

#include <iostream>
#include <string>

class Solution
{
    public:
        std::string toLowerCase(std::string str)
        {
            for (size_t i = 0; i < str.size(); ++i)
            {
                if (str[i] >= 'A' && str[i] <= 'Z')
                {
                    str[i] = 'a' + str[i] - 'A';
                }
            }
            return str;
        }
};

void testToLowerCase()
{
    Solution s;
    assert(s.toLowerCase("Hello") == std::string("hello"));
    assert(s.toLowerCase("here") == std::string("here"));
    assert(s.toLowerCase("LOVELY") == std::string("lovely"));
}

int main()
{
    testToLowerCase();
    return 0;
}
