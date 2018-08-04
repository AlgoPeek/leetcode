// Source: https://leetcode.com/problems/minimum-path-sum/description/
// Author: Diego Lee
// Date: 2018-08-04
//
// Description:
// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
// Note: You can only move either down or right at any point in time.
//
// Example:
//
// Input:
// [
//   [1,3,1],
//   [1,5,1],
//   [4,2,1]
// ]
// Output: 7
// Explanation: Because the path 1→3→1→1→1 minimizes the sum.

#include <iostream>
#include <vector>
#include <cassert>

#define countof(A) (sizeof A / sizeof A[0])

class Solution
{
    public:
        int minPathSum(std::vector<std::vector<int>>& grid)
        {
            if (grid.empty())
            {
                return 0;
            }

            int n = grid.size();
            int m = grid[0].size();
            std::vector<std::vector<int>> dp;
            for (int i = 0; i < n; ++i)
            {
                dp.push_back(std::vector<int>(m, 0));
            }

            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (i == 0 && j == 0)
                    {
                        dp[i][j] = grid[i][j];
                    }
                    else if (i == 0)
                    {
                        dp[i][j] = grid[i][j] + dp[i][j - 1];
                    }
                    else if (j == 0)
                    {
                        dp[i][j] = grid[i][j] + dp[i - 1][j];
                    }
                    else
                    {
                        dp[i][j] = grid[i][j] + std::min(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
            return dp[n-1][m-1];
        }
};

void testMinPathSum()
{
    int matrix[][3] =
    {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };

    std::vector<std::vector<int>> grid;
    for (int i = 0; i < countof(matrix); ++i)
    {
        grid.push_back(std::vector<int>(std::begin(matrix[i]), std::end(matrix[i])));
    }

    Solution s;
    int result = s.minPathSum(grid);
    //std::cout << "result=" << result << std::endl;
    assert(result == 7);
}

int main()
{
    testMinPathSum();
    return 0;
}
