// Source: https://leetcode.com/problems/excel-sheet-column-title/description/
// Author: Diego Lee
// Date: 2018-08-09
//
// Description:
// Given a positive integer, return its corresponding column title as appear in an Excel sheet.
//
// For example:
//
//     1 -> A
//     2 -> B
//     3 -> C
//     ...
//     26 -> Z
//     27 -> AA
//     28 -> AB
//     ...
// Example 1:
//
// Input: 1
// Output: "A"
// Example 2:
//
// Input: 28
// Output: "AB"
// Example 3:
//
// Input: 701
// Output: "ZY"

#include <iostream>
#include <string>
#include <cassert>

class Solution
{
    public:
        std::string convertToTitle(int n)
        {
            const int BASE = 26;
            std::string result;
            while (n > 0)
            {
                int i = (n - 1) % BASE;
                result.push_back('A' + i);
                n = (n - 1) / BASE;
            }
            reverseString(result);
            return result;
        }

        void reverseString(std::string& str)
        {
            int left = 0;
            int right = str.size() - 1;
            while (left < right)
            {
                std::swap(str[left++], str[right--]);
            }
        }
};

void testConvertToTitle()
{
    Solution s;
    assert(s.convertToTitle(1) == std::string("A"));
    assert(s.convertToTitle(28) == std::string("AB"));
    assert(s.convertToTitle(701) == std::string("ZY"));
}

int main()
{
    testConvertToTitle();
    return 0;
}
