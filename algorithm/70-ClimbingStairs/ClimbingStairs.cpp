// Source: https://leetcode.com/problems/climbing-stairs/description/
// Author: Diego Lee
// Date: 2018-07-19
//
// Description
// You are climbing a stair case. It takes n steps to reach to the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
// Note: Given n will be a positive integer.

// Example 1:
// Input: 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

// Example 2:
// Input: 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

#include <iostream>
#include <cassert>
#include <vector>

class Solution
{
    public:
        int climbStairs(int n)
        {
            std::vector<int> dp(n + 2);
            dp[0] = 1;
            dp[1] = 2;
            for (int i = 2; i < n; ++i)
            {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            return dp[n - 1];
        }
};

void testClimbStairs()
{
    Solution s;
    assert(s.climbStairs(2) == 2);
    assert(s.climbStairs(3) == 3);
    assert(s.climbStairs(4) == 5);
}

int main()
{
    testClimbStairs();
    return 0;
}
