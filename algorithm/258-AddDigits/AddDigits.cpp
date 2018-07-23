// Source: https://leetcode.com/problems/add-digits/description/
// Author: Diego Lee
// Date: 2018-07-24
//
// Description:
// Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
//
// Example:
// Input: 38
// Output: 2
// Explanation: The process is like: 3 + 8 = 11, 1 + 1 = 2.
// Since 2 has only one digit, return it.
// Follow up:
// Could you do it without any loop/recursion in O(1) runtime?

#include <iostream>
#include <cassert>

class Solution
{
    public:
        int addDigits(int num)
        {
            int result = num;
            while (result / 10 > 0)
            {
                int sum = 0;
                while (result > 0)
                {
                    sum += (result % 10);
                    result /= 10;
                }
                result = sum;
            }
            return result;
        }
};

void testAddDigits()
{
    Solution s;
    assert(s.addDigits(38) == 2);
}

int main()
{
    testAddDigits();
    return 0;
}
