// Source: https://leetcode.com/problems/n-queens-ii/description/
// Author: Diegoe Lee
// Date: 2018-07-31
//
// Description:
// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
// Given an integer n, return the number of distinct solutions to the n-queens puzzle.
// Example:
//
// Input: 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],
//
//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]

#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
    public:
        int totalNQueens(int n)
        {
            int result = 0;
            if (n == 1 || n > 3)
            {
                // vec[row] = col means (row, col) is queen
                std::vector<int> vec(n, 0);
                totalNQueensHelp(0, vec, result);
            }
            return result;
        }

        void totalNQueensHelp(int row, std::vector<int>& vec, int& result)
        {
            int n = vec.size();
            if (row >= n)
            {
                result += 1;
                return;
            }

            for (int col = 0; col < n; ++col)
            {
                vec[row] = col;
                if (isValid(row, vec))
                {
                    totalNQueensHelp(row + 1, vec, result);
                }
            }
        }

        bool isValid(int row, const std::vector<int>& vec)
        {
            for (int i = 0; i < row; ++i)
            {
                // check column and cross corner conflict
                if (vec[row] == vec[i] || abs(vec[row] - vec[i]) == abs(row - i))
                {
                    return false;
                }
            }
            return true;
        }
};

void testTotalNQueens()
{
    Solution s;
    assert(s.totalNQueens(1) == 1);
    assert(s.totalNQueens(2) == 0);
    assert(s.totalNQueens(4) == 2);
}

int main()
{
    testTotalNQueens();
    return 0;
}
