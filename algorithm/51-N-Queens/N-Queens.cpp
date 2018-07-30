// Source: https://leetcode.com/problems/n-queens/description/
// Author: Diego Lee
// Date: 2018-07-30
//
// Description:
// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle.
//
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.'
// both indicate a queen and an empty space respectively.
//
// Example:
//
// Input: 4
// Output: [
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
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

typedef std::vector<std::string> Board;
typedef std::vector<Board> BoardMatrix;

void printBoard(const Board& board);

class Solution
{
public:
    BoardMatrix solveNQueens(int n)
    {
        BoardMatrix result;
        if (n == 1 || n > 3)
        {
            Board curr;
            for (int i = 0; i < n; ++i)
            {
                curr.push_back(std::string(n, '.'));
            }
            solveNQueensHelp(0, n, curr, result);
        }
        return result;
    }

    void solveNQueensHelp(int i, int n, Board& curr, BoardMatrix& result)
    {
        if (i >= n)
        {
            result.push_back(curr);
            return;
        }

        for (int j = 0; j < n; ++j)
        {
            if (isValid(i, j, curr))
            {
                curr[i][j] = 'Q';
                solveNQueensHelp(i + 1, n, curr, result);
                curr[i][j] = '.';
            }
        }
    }

    bool isValid(int i, int j, const Board& curr)
    {
        int n = curr.size();
        for (int row = 0; row < i; ++row)
        {
            // check row
            if (curr[row][j] == 'Q')
            {
                return false;
            }

            // check cross corner
            int len = row - i;
            if ((j - len >= 0 && curr[row][j - len] == 'Q')
                || (j + len < n && curr[row][j + len] == 'Q'))
            {
                return false;
            }
        }
        return true;
    }
};

void printBoard(const Board& board)
{
    for (auto str : board)
    {
        std::cout << str << std::endl;
    }
}

void testSolveNQueens()
{
    Solution s;

    Board board1;
    board1.push_back(".Q..");
    board1.push_back("...Q");
    board1.push_back("Q...");
    board1.push_back("..Q.");

    Board board2;
    board2.push_back("..Q.");
    board2.push_back("Q...");
    board2.push_back("...Q");
    board2.push_back(".Q..");

    BoardMatrix result = s.solveNQueens(4);
    assert(result.size() == 2);
    // printBoard(result[0]);
    // printBoard(result[1]);
    assert(result[0] == board1);
    assert(result[1] == board2);

    result = s.solveNQueens(1);
    assert(result.size() == 1);
    assert(result[0][0] == "Q");
}

int main()
{
    testSolveNQueens();
    return 0;
}

