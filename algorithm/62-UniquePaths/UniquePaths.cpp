// Source: https://leetcode.com/problems/unique-paths/description/
// Author: Diego Lee
// Date: 2018-08-03
//
// Description:
// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//
// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//
// How many possible unique paths are there?
// Note: m and n will be at most 100.
//
// Example 1:
//
// Input: m = 3, n = 2
// Output: 3
// Explanation:
// From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Right -> Down
// 2. Right -> Down -> Right
// 3. Down -> Right -> Right
// Example 2:
//
// Input: m = 7, n = 3
// Output: 28

#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
    public:
        int uniquePaths(int m, int n)
        {
            if (m == 0 || n == 0)
            {
                return 0;
            }

            std::vector<std::vector<int>> dp;
            for (int i = 0; i < n; ++i)
            {
                dp.push_back(std::vector<int>(m));
            }

            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (i == 0 || j == 0)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                    }
                }
            }
            return dp[n - 1][m - 1];
        }
};

void testUniquePaths()
{
    Solution s;
    assert(s.uniquePaths(3, 2) == 3);
    assert(s.uniquePaths(7, 3) == 28);
    assert(s.uniquePaths(3, 3) == 6);
    assert(s.uniquePaths(1, 1) == 1);
}

int main()
{
    testUniquePaths();
    return 0;
}

