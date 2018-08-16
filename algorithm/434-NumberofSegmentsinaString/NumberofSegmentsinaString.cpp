// Source: https://leetcode.com/problems/number-of-segments-in-a-string/description/
// Author: Diego Lee
// Date: 2018-08-17
//
// Description:
// Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
//
// Please note that the string does not contain any non-printable characters.
//
// Example:
//
// Input: "Hello, my name is John"
// Output: 5

#include <iostream>
#include <string>

class Solution
{
    public:
        int countSegments(std::string s)
        {
            int count = 0;
            int pos = 0;
            for (int i = 0; i < s.size(); ++i)
            {
                if (s[i] == ' ')
                {
                    if (i != pos)
                    {
                        ++count;
                    }
                    pos = i + 1;
                }
                else if (i == s.size() - 1)
                {
                    ++count;
                }
            }
            return count;
        }
};

void testCountSegments()
{
    Solution s;
    int result = s.countSegments("Hello, my name is John");
    assert(result == 5);
}

int main()
{
    testCountSegments();
    return 0;
}
