// Source: https://leetcode.com/problems/power-of-two/description/
// Author: Diego Lee
// Date: 2018-08-06
//
// Description:
// Given an integer, write a function to determine if it is a power of two.
//
// Example 1:
//
// Input: 1
// Output: true
// Explanation: 20 = 1
// Example 2:
//
// Input: 16
// Output: true
// Explanation: 24 = 16
// Example 3:
//
// Input: 218
// Output: false

#include <iostream>
#include <cassert>

class Solution
{
    public:
        bool isPowerOfTwo(int n)
        {
            if (n == INT_MIN)
            {
                return false;
            }

            unsigned int mask = 1;
            int cnt = 0;
            while (mask > 0 && cnt <= 1)
            {
                if ((mask & n) != 0)
                {
                    ++cnt;
                }
                mask <<= 1;
            }
            return (cnt == 1);
        }
};

void testIsPowerOfTwo()
{
    Solution s;
    assert(s.isPowerOfTwo(1) == true);
    assert(s.isPowerOfTwo(218) == false);
    assert(s.isPowerOfTwo(INT_MIN) == false);
}

int main()
{
    testIsPowerOfTwo();
    return 0;
}
