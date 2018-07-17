// Source: https://leetcode.com/problems/sqrtx/description/
// Author: Diego Lee
// Date: 2018-07-17
//
// Description:
// Implement int sqrt(int x).
// Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
// Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
//
// Example 1:
// Input: 4
// Output: 2
//
// Example 2:
// Input: 8
// Output: 2
//
// Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.

#include <iostream>
#include <cassert>

// The key point is: i * i <= x && (i + 1) * (i + 1) > x
class Solution
{
    public:
        int mySqrt(int x)
        {
            if (x == 0)
            {
                return 0;
            }

            int left = 1;
            int right = x / 2 + 1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (mid <= x / mid && (mid + 1) > x / (mid + 1))
                {
                    return mid;
                }
                else if (mid > x / mid)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            return 0;
        }
};

void testMySqrt()
{
    Solution s;
    assert(s.mySqrt(4) == 2);
    assert(s.mySqrt(8) == 2);
}

int main()
{
    testMySqrt();
    return 0;
}
