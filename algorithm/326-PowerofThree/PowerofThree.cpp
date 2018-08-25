// Source: https://leetcode.com/problems/power-of-three/description/
// Author: Diego Lee
// Date: 2018-08-25
//
// Description:
// Given an integer, write a function to determine if it is a power of three.
//
// Example 1:
//
// Input: 27
// Output: true
// Example 2:
//
// Input: 0
// Output: false
// Example 3:
//
// Input: 9
// Output: true
// Example 4:
//
// Input: 45
// Output: false
// Follow up:
// Could you do it without using any loop / recursion?

#include <iostream>
#include <cassert>

class Solution
{
    public:
        bool isPowerOfThree(int n)
        {
            if (n < 1)
            {
                return false;
            }

            while (n % 3 == 0)
            {
                n /= 3;
            }
            return (n == 1);
        }
};

void testIsPowerOfTree()
{
    Solution s;
    assert(s.isPowerOfThree(27) == true);
    assert(s.isPowerOfThree(0) == false);
    assert(s.isPowerOfThree(9) == true);
    assert(s.isPowerOfThree(45) == false);
}

int main()
{
    testIsPowerOfTree();
    return 0;
}
