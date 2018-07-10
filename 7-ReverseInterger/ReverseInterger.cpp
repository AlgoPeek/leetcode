// Source: https://leetcode.com/problems/reverse-integer/description/
// Author: Diego Lee
// Date: 2018-07-10
//
// Description:
// Given a 32-bit signed integer, reverse digits of an integer.
//
// Example 1:
// Input: 123
// Output: 321
//
// Example 2:
// Input: -123
// Output: -321
//
// Example 3:
// Input: 120
// Output: 21
//
// Note:
// Assume we are dealing with an environment which could only store integers within the 32-bit
// signed integer range: [−2^31,  2^31 − 1]. For the purpose of this problem, assume that your
// function returns 0 when the reversed integer overflows.
//

#include <cassert>
#include <iostream>
#include <climits>

class Solution
{
    public:
        int reverse(int x)
        {
            int r = 0;
            while (x)
            {
                if (r != 0
                    && INT_MAX / r < 10
                    && INT_MAX / r > -10)
                {
                    return 0;
                }
                r = r * 10 + x % 10;
                x /= 10;
            }
            return r;
        }
};

void testReverse()
{
    Solution s;
    int x = 123;
    int r = s.reverse(x);
    assert(321 == r);

    x = 0;
    r = s.reverse(x);
    assert(0 == r);

    x = 10100;
    r = s.reverse(x);
    assert(101 == r);

    x = -123;
    r = s.reverse(x);
    assert(-321 == r);

    x = 1000000003;
    r = s.reverse(x);
    //	std::cout << r << std::endl;
    assert(0 == r);

    x = -1000000003;
    r = s.reverse(x);
    //	std::cout << r << std::endl;
    assert(0 == r);

    x = 1534236469;
    r = s.reverse(x);
    assert(0 == r);
}

int main()
{
    testReverse();
    return 0;
}
