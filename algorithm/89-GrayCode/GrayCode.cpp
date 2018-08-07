// Source: https://leetcode.com/problems/gray-code/description/
// Author: Diego Lee
// Date: 2018-08-07
// Ref: https://en.wikipedia.org/wiki/Gray_code
//
// Description:
// The gray code is a binary numeral system where two successive values differ in only one bit.
// Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
//
// Example 1:
// Input: 2
// Output: [0,1,3,2]
// Explanation:
// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2
//
// For a given n, a gray code sequence may not be uniquely defined.
// For example, [0,2,3,1] is also a valid gray code sequence.
// 00 - 0
// 10 - 2
// 11 - 3
// 01 - 1
//
// Example 2:
// Input: 0
// Output: [0]
// Explanation: We define the gray code sequence to begin with 0.
//              A gray code sequence of n has size = 2n, which for n = 0 the size is 20 = 1.
//              Therefore, for n = 0 the gray code sequence is [0].

// Hint:
// The binary-reflected Gray code list for n bits can be generated recursively from the list for
// n − 1 bits by reflecting the list (i.e. listing the entries in reverse order), prefixing the
// entries in the original list with a binary 0, prefixing the entries in the reflected list with
// a binary 1, and then concatenating the original list with the reversed list.[11] For example,
// generating the n = 3 list from the n = 2 list:
//
// 2-bit list: 00, 01, 11, 10
// Reflected: 10, 11, 01, 00
// Prefix old entries with 0: 000, 001, 011, 010,
// Prefix new entries with 1: 110, 111, 101, 100
// Concatenated: 000, 001, 011, 010,	110, 111, 101, 100

#include <vector>
#include <iostream>
#include <cassert>
#include <cmath>

class Solution
{
    public:
        std::vector<int> grayCode(int n)
        {
            std::vector<int> result;
            for (int i = 0, size = pow(2, n); i < size; ++i)
            {
                result.push_back(i ^ (i >> 1));
            }
            return result;
        }
};

void testGrayCode()
{
    int A[] = {0,1,3,2};
    Solution s;
    assert(s.grayCode(0) == std::vector<int>(1, 0));
    assert(s.grayCode(2) == std::vector<int>(std::begin(A), std::end(A)));
}

int main()
{
    testGrayCode();
    return 0;
}
