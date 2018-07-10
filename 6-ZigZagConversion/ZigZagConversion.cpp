// Source: https://leetcode.com/problems/zigzag-conversion/description/
// Author: Diego Lee
// Date: 2018-07-10
//
// Description:
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
// (you may want to display this pattern in a fixed font for better legibility)
// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:
// string convert(string s, int numRows);
//
// Example 1:
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
//
// Example 2:
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
//

#include <cassert>
#include <iostream>
#include <string>

class Solution
{
    public:
        std::string convert(const std::string& s, int numRows)
        {
            if (numRows == 1)
            {
                return s;
            }

            std::string result;
            for (int i = 0; i < numRows; ++i)
            {
                int step1 = (i == numRows - 1) ? 2 * i : 2 * (numRows - 1 - i);
                int step2 = (i == 0) ? 2 * (numRows - 1) : 2 * i;
                int j = i;
                bool flag = true;
                while (j < s.size())
                {
                    if (flag)
                    {
                        result.append(1, s[j]);
                        j += step1;
                    }
                    else
                    {
                        result.append(1, s[j]);
                        j += step2;
                    }
                    flag = !flag;
                }
            }
            return result;
        }
};

void testConvert()
{
    Solution s;
    std::string src = "PAYPALISHIRING";
    int row = 3;
    std::string result = s.convert(src, 3);
    assert(result == "PAHNAPLSIIGYIR");

    src = "A";
    result = s.convert(src, 1);
    assert(result == "A");
}

int main()
{
    testConvert();
    return 0;
}
