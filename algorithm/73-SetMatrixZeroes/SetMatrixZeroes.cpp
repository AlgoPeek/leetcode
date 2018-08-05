// Source: https://leetcode.com/problems/set-matrix-zeroes/description/
// Author: Diego Lee
// Date: 2018-08-05
//
// Description:
// Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
//
// Example 1:
//
// Input:
// [
//   [1,1,1],
//   [1,0,1],
//   [1,1,1]
// ]
// Output:
// [
//   [1,0,1],
//   [0,0,0],
//   [1,0,1]
// ]
// Example 2:
//
// Input:
// [
//   [0,1,2,0],
//   [3,4,5,2],
//   [1,3,1,5]
// ]
// Output:
// [
//   [0,0,0,0],
//   [0,4,5,0],
//   [0,3,1,0]
// ]
// Follow up:
//
// A straight forward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?

#include <iostream>
#include <vector>
#include <cassert>

#define countof(A) (sizeof A / sizeof A[0])
typedef std::vector<std::vector<int>> Matrix;

class Solution
{
    public:
        void setZeroes(Matrix& matrix)
        {
            if (matrix.empty())
            {
                return;
            }

            int n = matrix.size();
            int m = matrix[0].size();
            std::vector<bool> row(n, false);
            std::vector<bool> col(m, false);
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (matrix[i][j] == 0)
                    {
                        row[i] = true;
                        col[j] = true;
                    }
                }
            }

            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    if (row[i] || col[j])
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
};

template <typename T>
Matrix convertToMatrix(T A, int n, int m)
{
    Matrix matrix;
    for (int i = 0; i < n; ++i)
    {
        matrix.push_back(std::vector<int>(A[i], A[i] + m));
    }
    return matrix;
}

void testSetZeroes()
{
    int m1[][3] =
    {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };
    int m2[][4] =
    {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };
    int r1[][3] =
    {
        {1,0,1},
        {0,0,0},
        {1,0,1}
    };
    int r2[][4] =
    {
        {0,0,0,0},
        {0,4,5,0},
        {0,3,1,0}
    };

    Solution s;
    Matrix matrix1 = convertToMatrix(m1, countof(m1), 3);
    s.setZeroes(matrix1);
    assert(matrix1 == convertToMatrix(r1, countof(r1), 3));

    Matrix matrix2 = convertToMatrix(m2, countof(m2), 4);
    s.setZeroes(matrix2);
    assert(matrix2 == convertToMatrix(r2, countof(r2), 4));
}

int main()
{
    testSetZeroes();
    return 0;
}
