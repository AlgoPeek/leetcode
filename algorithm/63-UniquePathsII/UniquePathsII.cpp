// Source: https://leetcode.com/problems/unique-paths-ii/description/
// Author: Diego Lee
// Date: 2018-08-04
//
// Description:
// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
//
// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
//
// Now consider if some obstacles are added to the grids. How many unique paths would there be?
// An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
// Note: m and n will be at most 100.
//
// Example 1:
//
// Input:
// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// Output: 2
// Explanation:
// There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right

#include <iostream>
#include <vector>
#include <cassert>

#define countof(A) (sizeof A / sizeof A[0])

class Solution
{
    public:
        int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid)
        {
            if (obstacleGrid.empty())
            {
                return 0;
            }

            int n = obstacleGrid.size();
            int m = obstacleGrid[0].size();
            std::vector<std::vector<int>> paths;
            for (int i = 0; i < n; ++i)
            {
                paths.push_back(std::vector<int>(m, 0));
            }

            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (obstacleGrid[i][j] == 1)
                    {
                        continue;
                    }

                    if (i == 0 || j == 0)
                    {
                        if (i == 0 && j == 0)
                        {
                            paths[i][j] = 1;
                        }
                        else if (i == 0)
                        {
                            paths[i][j] = paths[i][j-1];
                        }
                        else
                        {
                            paths[i][j] = paths[i-1][j];
                        }
                    }
                    else
                    {
                        paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
                    }
                }
            }
            return paths[n - 1][m - 1];
        }
};

void testUniquePathsWithObstacles()
{
    int paths[][3] =
    {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };

    std::vector<std::vector<int>> obstacleGrid;
    for (int i = 0; i < countof(paths); ++i)
    {
        obstacleGrid.push_back(std::vector<int>(std::begin(paths[i]), std::end(paths[i])));
    }

    Solution s;
    int result = s.uniquePathsWithObstacles(obstacleGrid);
    assert(result  == 2);

    obstacleGrid.clear();
    obstacleGrid.push_back(std::vector<int>(2, 0));
    obstacleGrid[0][0] = 1;
    result = s.uniquePathsWithObstacles(obstacleGrid);
    assert(result == 0);
}

int main()
{
    testUniquePathsWithObstacles();
    return 0;
}
