// Source: https://leetcode.com/problems/reverse-string-ii/description/
// Author: Diego Lee
// Date: 2018-08-17
//
// Description:
// Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
//
// Example:
// Input: s = "abcdefg", k = 2
// Output: "bacdfeg"
// Restrictions:
// The string consists of lower English letters only.
// Length of the given string and k will in the range [1, 10000]

#include <iostream>
#include <string>

class Solution
{
    public:
        std::string reverseStr(std::string s, int k)
        {
            for (int i = 0; i < s.size(); i += 2*k)
            {
                reverseRangeStr(s, i, k);
            }
            return s;
        }

        void reverseRangeStr(std::string& s, int start, int k)
        {
            int step = std::min(k, static_cast<int>(s.size() - start));
            int left = start;
            int right = start + step - 1;
            while (left < right)
            {
                std::swap(s[left++], s[right--]);
            }
        }
};

void testReverseStr()
{
    Solution s;
    assert(s.reverseStr("abcdefg", 2) == std::string("bacdfeg"));
}

int main()
{
    testReverseStr();
    return 0;
}
