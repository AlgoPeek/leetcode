// Source: https://leetcode.com/problems/factorial-trailing-zeroes/description/
// Author: Diego Lee
// Date: 2018-07-21
//
// Description:
// Given an integer n, return the number of trailing zeroes in n!.
//
// Example 1:
// Input: 3
// Output: 0
// Explanation: 3! = 6, no trailing zero.
// Example 2:
// Input: 5
// Output: 1
// Explanation: 5! = 120, one trailing zero.
// Note: Your solution should be in logarithmic time complexity.

#include <iostream>
#include <cassert>

class Solution
{
    public:
        int trailingZeroes(int n)
        {
            int result = 0;
            long long divisor = 5;
            while ((n / divisor) > 0)
            {
                result += (n / divisor);
                divisor *= 5;
            }
            return result;
        }
};

void testTrailingZeroes()
{
    Solution s;
    assert(s.trailingZeroes(3) == 0);
    assert(s.trailingZeroes(5) == 1);
    assert(s.trailingZeroes(1808548329) == 452137076);
}

int main()
{
    testTrailingZeroes();
    return 0;
}
