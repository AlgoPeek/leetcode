// Source: https://leetcode.com/problems/powx-n/description/
// Author: Diego Lee
// Date: 2018-07-28
//
// Description:
// Implement pow(x, n), which calculates x raised to the power n (x^n).
//
// Example 1:
//
// Input: 2.00000, 10
// Output: 1024.00000
// Example 2:
//
// Input: 2.10000, 3
// Output: 9.26100
// Example 3:
//
// Input: 2.00000, -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25
// Note:
//
// -100.0 < x < 100.0
// n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]

#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n > 0)
        {
            return positivePow(x, n);
        }
        else if (n == 0)
        {
            return 1.0;
        }
        else if (n != INT_MIN)
        {
            return 1 / positivePow(x, -n);
        }
        else
        {
            return 1 / positivePow(x, -(n + 1)) / x;
        }
    }

    double positivePow(double x, int n)
    {
        if (n == 1)
        {
            return x;
        }

        double half = positivePow(x, n / 2);
        if (n % 2 == 0)
        {
            return half * half;
        }
        else
        {
            return half * half * x;
        }
    }
};

void testMyPow()
{
    Solution s;
    double r = s.myPow(2.0, 10);
    assert(r - 1024.0 < 0.00001);
    r = s.myPow(2.1, 3);
    assert(r - 9.261 < 0.00001);
}

int main()
{
    testMyPow();
    return 0;
}

