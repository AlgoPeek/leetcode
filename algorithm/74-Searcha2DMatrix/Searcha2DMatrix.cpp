// Source: https://leetcode.com/problems/search-a-2d-matrix/description/
// Author: Diego Lee
// Date: 2018-08-07
//
// Description:
// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// Example 1:
//
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// Output: true
// Example 2:
//
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 13
// Output: false

#include <iostream>
#include <vector>
#include <cassert>

#define countof(A) (sizeof A / sizeof A[0])

typedef std::vector<std::vector<int>> Matrix;
class Solution
{
    public:
        bool searchMatrix(Matrix& matrix, int target)
        {
            if (matrix.empty())
            {
                return false;
            }

            // locate row
            int n = matrix.size();
            int m = matrix[0].size();
            int top = 0;
            int bottom = n - 1;
            while (top <= bottom)
            {
                int center = top + (bottom - top) / 2;
                std::vector<int>& row = matrix[center];
                if (row.empty())
                {
                    return false;
                }

                if (target < row[0])
                {
                    bottom = center - 1;
                }
                else if (target > row[m-1])
                {
                    top = center + 1;
                }
                else
                {
                    return searchRow(row, target);
                }
            }
            return false;
        }

        bool searchRow(std::vector<int>& row, int target)
        {
            int left = 0;
            int right = row.size() - 1;
            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (row[mid] > target)
                {
                    right = mid - 1;
                }
                else if (row[mid] < target)
                {
                    left = mid + 1;
                }
                else
                {
                    return true;
                }
            }
            return false;
        }
};

void testSearchMatrix()
{
    int mm[][4] =
    {
        {1,   3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };

    Matrix matrix;
    for (int i = 0; i < countof(mm); ++i)
    {
        matrix.push_back(std::vector<int>(std::begin(mm[i]), std::end(mm[i])));
    }
    Solution s;
    assert(s.searchMatrix(matrix, 3) == true);

    matrix.clear();
    matrix.push_back(std::vector<int>());
    assert(s.searchMatrix(matrix, 1) == false);
}

int main()
{
    testSearchMatrix();
    return 0;
}
