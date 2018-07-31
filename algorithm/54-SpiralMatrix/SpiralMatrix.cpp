// Source: https://leetcode.com/problems/spiral-matrix/description/
// Author: Diego Lee
// Date: 2018-07-31
//
// Description:
// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
// Example 1:
//
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:
//
// Input:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
//

#include <iostream>
#include <vector>
#include <cassert>

#define countof(A) (sizeof A / sizeof A[0])

typedef std::vector<std::vector<int>> Matrix;

class Solution
{
    public:
        std::vector<int> spiralOrder(Matrix& matrix)
        {
            std::vector<int> result;
            if (matrix.empty())
            {
                return result;
            }
            int m1 = 0;
            int n1 = 0;
            int m2 = matrix.size() - 1;
            int n2 = matrix[0].size() - 1;
            while (m1 <= m2 && n1 <= n2)
            {
                // std::cout << "m1=" << m1 << ", m2=" << m2 << ", n1=" << n1 << ", n2=" << n2 << std::endl;
                if (m1 == m2)
                {
                    for (int i = n1; i <= n2; ++i)
                    {
                        result.push_back(matrix[m1][i]);
                    }
                    break;
                }
                else if (n1 == n2)
                {
                    for (int i = m1; i <= n2; ++i)
                    {
                        result.push_back(matrix[i][n1]);
                    }
                    break;
                }
                else
                {
                    for (int i = n1; i < n2; ++i)
                    {
                        result.push_back(matrix[m1][i]);
                    }
                    for (int j = m1; j < m2; ++j)
                    {
                        result.push_back(matrix[j][n2]);
                    }
                    for (int k = n2; k > n1; --k)
                    {
                        result.push_back(matrix[m2][k]);
                    }
                    for (int g = m2; g > m1; --g)
                    {
                        result.push_back(matrix[g][n1]);
                    }
                    m1 += 1;
                    m2 -= 1;
                    n1 += 1;
                    n2 -= 1;
                }
            }
            return result;
        }
};

void printVector(const std::vector<int>& vec)
{
    for (auto i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void testSpiralOrder()
{
    int A1[][3] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int R1[] = {1,2,3,6,9,8,7,4,5};
    Matrix matrix;
    for (int i = 0; i < countof(A1); ++i)
    {
        matrix.push_back(std::vector<int>(std::begin(A1[i]), std::end(A1[i])));
    }

    Solution s;
    std::vector<int> result = s.spiralOrder(matrix);
    printVector(result);
    assert(result == std::vector<int>(std::begin(R1), std::end(R1)));

    int A2[][4] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12}
    };
    int R2[] = {1,2,3,4,8,12,11,10,9,5,6,7};

    matrix.clear();
    for (int i = 0; i < countof(A2); ++i)
    {
        matrix.push_back(std::vector<int>(std::begin(A2[i]), std::end(A2[i])));
    }
    result = s.spiralOrder(matrix);
    printVector(result);
    assert(result == std::vector<int>(std::begin(R2), std::end(R2)));

    matrix.clear();
    matrix.push_back(std::vector<int>(1,1));
    result = s.spiralOrder(matrix);
    printVector(result);
    assert(result == std::vector<int>(1,1));
}

int main()
{
    testSpiralOrder();
    return 0;
}
