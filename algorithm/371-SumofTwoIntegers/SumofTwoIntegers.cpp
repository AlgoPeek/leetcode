// Source: https://leetcode.com/problems/sum-of-two-integers/description/
// Author: Diego Lee
// Date: 2018-10-02
//
// Description:
// Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
//
// Example 1:
//
// Input: a = 1, b = 2
// Output: 3
// Example 2:
//
// Input: a = -2, b = 3
// Output: 1

#include <iostream>
#include <cassert>

class Solution {
    public:
        int getSum(int a, int b) {
            while (b != 0) {
                int carry = a & b;
                a ^= b;
                b = carry << 1;
            }
            return a;
        }
};

void testGetSum() {
    Solution s;
    assert(s.getSum(1, 2) == 3);
    assert(s.getSum(-2, 3) == 1);
}

int main() {
    testGetSum();
    return 0;
}
