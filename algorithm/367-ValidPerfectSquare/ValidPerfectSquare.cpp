// Source: https://leetcode.com/problems/valid-perfect-square/description/
// Author: Diego Lee
// Date: 2018-08-29
//
// Description:
// Given a positive integer num, write a function which returns True if num is a perfect square else False.
//
// Note: Do not use any built-in library function such as sqrt.
//
// Example 1:
//
// Input: 16
// Output: true
// Example 2:
//
// Input: 14
// Output: false
//

#include <iostream>
#include <cassert>

class Solution
{
    public:
        bool isPerfectSquare(int num)
        {
            long left = 1;
            long right = num;
            while (left <= right)
            {
                long mid = left + (right - left) / 2;
                long square = mid * mid;
                if (square == num)
                {
                    return true;
                }
                else if (square < num)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            return false;
        }
};

void testIsPerfectSquare()
{
    Solution s;
    assert(s.isPerfectSquare(16) == true);
    assert(s.isPerfectSquare(14) == false);
}

int main()
{
    testIsPerfectSquare();
    return 0;
}
