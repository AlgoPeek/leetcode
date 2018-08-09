// Source: https://leetcode.com/problems/excel-sheet-column-number/description/
// Author: Diego Lee
// Date: 2018-08-09
//
// Description:
// Given a column title as appear in an Excel sheet, return its corresponding column number.
//
// For example:
//
//     A -> 1
//     B -> 2
//     C -> 3
//     ...
//     Z -> 26
//     AA -> 27
//     AB -> 28
//     ...
// Example 1:
//
// Input: "A"
// Output: 1
// Example 2:
//
// Input: "AB"
// Output: 28
// Example 3:
//
// Input: "ZY"
// Output: 701

#include <iostream>
#include <string>
#include <cassert>

class Solution
{
    public:
        int titleToNumber(std::string s)
        {
            int result = 0;
            int base = 1;
            for (int i = s.size() - 1; i >= 0; --i)
            {
                result += (s[i] - 'A' + 1) * base;
                base *= 26;
            }
            return result;
        }
};

void testTitleToNumber()
{
    Solution s;
    assert(s.titleToNumber("A") == 1);
    assert(s.titleToNumber("AB") == 28);
    assert(s.titleToNumber("ZY") == 701);
}

int main()
{
    testTitleToNumber();
    return 0;
}
