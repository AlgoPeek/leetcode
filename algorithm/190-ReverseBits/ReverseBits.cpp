// Source: https://leetcode.com/problems/reverse-bits/description/
// Author: Diego Lee
// Date: 2018-07-20
//
// Description:
// Reverse bits of a given 32 bits unsigned integer.
// Example:
// Input: 43261596
// Output: 964176192
// Explanation: 43261596 represented in binary as 00000010100101000001111010011100,
//             return 964176192 represented in binary as 00111001011110000010100101000000.
// Follow up:
// If this function is called many times, how would you optimize it?

#include <iostream>
#include <cassert>

class Solution
{
    public:
        uint32_t reverseBits(uint32_t n)
        {
            uint32_t result = 0;
            uint32_t mask = 1;
            for (int i = 0; i < 32; ++i)
            {
                if (n & mask)
                {
                    result |= (static_cast<uint32_t>(1) << (32 - i - 1));
                }
                mask <<= 1;
            }
            return result;
        }
};

void testReverseBits()
{
    uint32_t n = 43261596;
    assert(Solution().reverseBits(n) == static_cast<uint32_t>(964176192));
}

int main()
{
    testReverseBits();
    return 0;
}
