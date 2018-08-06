// Source: https://leetcode.com/problems/combinations/description/
// Author: Diego Lee
// Date: 2018-08-06
//
// Description:
// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
// Example:
//
// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

#include <iostream>
#include <vector>
#include <cassert>

#define countof(A) (sizeof A / sizeof A[0])

typedef std::vector<std::vector<int>> Matrix;

class Solution
{
    public:
        Matrix combine(int n, int k)
        {
            Matrix result;
            std::vector<int> curr;
            combineHelp(n, k, 1, curr, result);
            return result;
        }

        void combineHelp(int n, int k, int start, std::vector<int>& curr, Matrix& result)
        {
            if (curr.size() >= k)
            {
                result.push_back(curr);
                return;
            }
            for (int i = start; i <= n; ++i)
            {
                curr.push_back(i);
                combineHelp(n, k, i + 1, curr, result);
                curr.pop_back();
            }
        }
};

void printMatrix(const Matrix& matrix)
{
    for (auto row : matrix)
    {
        for (auto i : row)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}

void testCombine()
{
    int R[][2] =
    {
        {1,2},
        {1,3},
        {1,4},
        {2,3},
        {2,4},
        {3,4}
    };

    Solution s;
    Matrix result = s.combine(4, 2);
    // printMatrix(result);
    assert(result.size() == countof(R));
    for (size_t i = 0; i < result.size(); ++i)
    {
        assert(result[i] == std::vector<int>(std::begin(R[i]), std::end(R[i])));
    }
}

int main()
{
    testCombine();
    return 0;
}
