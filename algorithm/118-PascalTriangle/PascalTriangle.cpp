// Source: https://leetcode.com/problems/pascals-triangle/description/
// Author: Diego Lee
// Date: 2018-07-20
//
// Description:
// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it.
// Example:
// Input: 5
// Output:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]
//

#include <iostream>
#include <vector>
#include <cassert>

typedef std::vector<std::vector<int>> Matrix;

class Solution
{
    public:
        Matrix generate(int numRows)
        {
            Matrix matrix;
            if (numRows <= 0)
            {
                return matrix;
            }

            std::vector<int> row1(1, 1);
            std::vector<int> row2(2, 1);
            if (numRows == 1)
            {
                matrix.push_back(row1);
            }
            else if (numRows == 2)
            {
                matrix.push_back(row1);
                matrix.push_back(row2);
            }
            else
            {
                matrix.push_back(row1);
                matrix.push_back(row2);
                for (int i = 2; i < numRows; ++i)
                {
                    std::vector<int> row;
                    row.push_back(1);
                    for (int j = 0; j < i - 1; ++j)
                    {
                        row.push_back(matrix[i - 1][j] + matrix[i - 1][j + 1]);
                    }
                    row.push_back(1);
                    matrix.push_back(row);
                }
            }
            return matrix;
        }
};

void testGenerate()
{
    int A1[] = {1};
    int A2[] = {1, 1};
    int A3[] = {1, 2, 1};
    Matrix expire;
    expire.push_back(std::vector<int>(std::begin(A1), std::end(A1)));
    expire.push_back(std::vector<int>(std::begin(A2), std::end(A2)));
    expire.push_back(std::vector<int>(std::begin(A3), std::end(A3)));
    assert(Solution().generate(3) == expire);
}

int main()
{
    testGenerate();
    return 0;
}
