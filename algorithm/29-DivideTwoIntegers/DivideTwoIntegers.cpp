// Source: https://leetcode.com/problems/divide-two-integers/description/
// Author: Diego Lee
// Date: 2018-07-19
//
// Description:
// Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
// Return the quotient after dividing dividend by divisor.
// The integer division should truncate toward zero.
//
// Example 1:
// Input: dividend = 10, divisor = 3
// Output: 3
//
// Example 2:
// Input: dividend = 7, divisor = -3
// Output: -2
// Note:
// Both dividend and divisor will be 32-bit signed integers.
// The divisor will never be 0.
// Assume we are dealing with an environment which could only store integers within the
// 32-bit signed integer range: [−2^31, 2^31 − 1]. For the purpose of this problem, assume
// that your function returns 2^31 − 1 when the division result overflows.

#include <iostream>
#include <cassert>

class Solution
{
    public:
        int divide(int dividend, int divisor)
        {
            if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
            {
                return INT_MAX;
            }

            int sign = ((dividend < 0 ) ^ (divisor < 0)) ? -1 : 1;
            long long dvd = labs(dividend);
            long long dvs = labs(divisor);
            int result = 0;
            while (dvd >= dvs)
            {
                long long tmp = dvs;
                long long multi = 1;
                while (dvd >= (tmp << 1))
                {
                    tmp <<= 1;
                    multi <<= 1;
                }
                dvd -= tmp;
                result += static_cast<int>(multi);
            }
            return (sign == 1 ? result : -result);
        }
};

void testDivide(void)
{
    Solution s;
    assert(s.divide(15, 3) == 5);
    assert(s.divide(15, -3) == -5);
    assert(s.divide(10, 3) == 3);
    assert(s.divide(0, 1) == 0);
    assert(s.divide(1, 0) == INT_MAX);
    assert(s.divide(INT_MIN, -1) == INT_MAX);
}

int main()
{
    testDivide();
    return 0;
}
