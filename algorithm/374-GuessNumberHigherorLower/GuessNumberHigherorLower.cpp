// Source: https://leetcode.com/problems/guess-number-higher-or-lower/description/
// Author: Diego Lee
// Date: 2018-08-15
//
// Description:
// We are playing the Guess Game. The game is as follows:
//
//
// I pick a number from 1 to n. You have to guess which number I picked.
//
// Every time you guess wrong, I'll tell you whether the number is higher or lower.
//
// You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):
//
// -1 : My number is lower
//  1 : My number is higher
//  0 : Congrats! You got it!
// Example:
// n = 10, I pick 6.
//
// Return 6.

#include <iostream>
#include <cassert>

int getPickNumber()
{
    // dummpy pick number
    return 6;
}

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num)
{
    if (num == getPickNumber())
    {
        return 0;
    }
    else if (num < getPickNumber())
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

class Solution
{
    public:
        int guessNumber(int n)
        {
            int left = 1;
            int right = n;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                int result = guess(mid);
                if (result == 0)
                {
                    return mid;
                }
                else if (result > 0)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            return -1;
        }
};

void testGuessNumber()
{
    Solution s;
    assert(s.guessNumber(10) == getPickNumber());
}

int main()
{
    testGuessNumber();
    return 0;
}
