// Source: https://leetcode.com/problems/power-of-four/description/
// Author: Diego Lee
// Date: 2018-08-25
//
// Description:
// Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
//
// Example 1:
//
// Input: 16
// Output: true
// Example 2:
//
// Input: 5
// Output: false
// Follow up: Could you solve it without loops/recursion?

#include <iostream>
#include <cassert>

class Solution
{
    public:
        bool isPowerOfFour(int num)
        {
            if (num < 1)
            {
                return false;
            }

            while (num % 4 == 0)
            {
                num /= 4;
            }
            return (num == 1);

        }
};

void testIsPowerOfFour()
{
    Solution s;
    assert(s.isPowerOfFour(16) == true);
    assert(s.isPowerOfFour(5) == false);
}

int main()
{
    testIsPowerOfFour();
    return 0;
}
