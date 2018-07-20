// Source: https://leetcode.com/problems/number-of-1-bits/description/
// Author: Diego Lee
// Date: 2018-07-20
//
// Description:
// Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
//
// Example 1:
//
// Input: 11
// Output: 3
// Explanation: Integer 11 has binary representation 00000000000000000000000000001011
// Example 2:
//
// Input: 128
// Output: 1
// Explanation: Integer 128 has binary representation 00000000000000000000000010000000

#include <iostream>
#include <cassert>

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int result = 0;
        uint32_t mask = 1;
        for (int i = 0; i < 32; ++i)
        {
            if (n & mask)
            {
                ++result;
            }
            mask <<= 1;
        }
        return result;
    }
};

void testHammingWeight()
{
    Solution s;
    assert(s.hammingWeight(11) == 3);
    assert(s.hammingWeight(128) == 1);
}

int main()
{
    testHammingWeight();
    return 0;
}
