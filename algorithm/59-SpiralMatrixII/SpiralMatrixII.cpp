// Source: https://leetcode.com/problems/spiral-matrix-ii/description/
// Author: Diego
// Date: 2018-07-31
//
// Description:
// Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
// Example:
//
// Input: 3
// Output:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

#include <iostream>
#include <vector>
#include <cassert>

typedef std::vector<std::vector<int>> Matrix;

class Solution
{
    public:
        Matrix generateMatrix(int n)
        {
            Matrix result;
            if (n <= 0)
            {
                return result;
            }

            // init
            for (int i = 0; i < n; ++i)
            {
                result.push_back(std::vector<int>(n, 0));
            }

            int start = 1;
            int p = 0;
            int q = n - 1;
            while (p <= q)
            {
                if (p == q)
                {
                    result[p][q] = start++;
                    break;
                }
                else
                {
                    // top
                    for (int i = p; i < q; ++i)
                    {
                        result[p][i] = start++;
                    }
                    // right
                    for (int j = p; j < q; ++j)
                    {
                        result[j][q] = start++;
                    }
                    // bottom
                    for (int k = q; k > p; --k)
                    {
                        result[q][k] = start++;
                    }
                    // left
                    for (int g = q; g > p; --g)
                    {
                        result[g][p] = start++;
                    }

                    p += 1;
                    q -= 1;
                }
            }
            return result;
        }
};

void printMatrix(const Matrix& matrix)
{
    for (auto vec : matrix)
    {
        for (auto i : vec)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}

void testGenerateMatrix()
{
    int R0[] = {1, 2, 3};
    int R1[] = {8, 9, 4};
    int R2[] = {7, 6, 5};

    Solution s;
    Matrix result = s.generateMatrix(3);
    // printMatrix(result);
    assert(result.size() == 3);
    assert(result[0] == std::vector<int>(std::begin(R0), std::end(R0)));
    assert(result[1] == std::vector<int>(std::begin(R1), std::end(R1)));
    assert(result[2] == std::vector<int>(std::begin(R2), std::end(R2)));

    result = s.generateMatrix(1);
    // printMatrix(result);
    assert(result.size() == 1);
    assert(result[0] == std::vector<int>(1, 1));
}

int main()
{
    testGenerateMatrix();
    return 0;
}
