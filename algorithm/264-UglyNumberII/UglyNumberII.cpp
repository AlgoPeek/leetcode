// Source: https://leetcode.com/problems/ugly-number-ii/description/
// Author: Diego Lee
// Date: 2018-08-11
//
// Description:
// Write a program to find the n-th ugly number.
//
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
//
// Example:
//
// Input: n = 10
// Output: 12
// Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
// Note:
//
// 1 is typically treated as an ugly number.
// n does not exceed 1690.

#include <vector>
#include <iostream>

class Solution {
    public:
        int nthUglyNumber(int n)
        {
            if (n <= 0)
            {
                return 0;
            }

            std::vector<int> dp(1, 1);
            int t2 = 0;
            int t3 = 0;
            int t5 = 0;
            while (dp.size() < n)
            {
                int m2 = dp[t2] * 2;
                int m3 = dp[t3] * 3;
                int m5 = dp[t5] * 5;
                int next = std::min(m2, std::min(m3, m5));
                if (next == m2)
                {
                    ++t2;
                }
                if (next == m3)
                {
                    ++t3;
                }
                if (next == m5)
                {
                    ++t5;
                }
                dp.push_back(next);
            }
            return dp.back();
        }
};

void testNthUglyNumber()
{
    Solution s;
    assert(s.nthUglyNumber(10) == 12);
}

int main()
{
    testNthUglyNumber();
    return 0;
}
