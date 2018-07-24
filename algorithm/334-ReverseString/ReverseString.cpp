// Source: https://leetcode.com/problems/reverse-string/description/
// Author: Diego Lee
// Date: 2018-07-24
//
// Description:
// Write a function that takes a string as input and returns the string reversed.
//
// Example:
// Given s = "hello", return "olleh".

#include <iostream>
#include <string>
#include <cassert>

class Solution
{
    public:
        std::string reverseString(std::string s)
        {
            int left = 0;
            int right = s.size() - 1;
            while (left < right)
            {
                std::swap(s[left++], s[right--]);
            }
            return s;
        }
};

void testReverseString()
{
    Solution s;
    assert(s.reverseString("hello") == std::string("olleh"));
}

int main()
{
    testReverseString();
    return 0;
}
