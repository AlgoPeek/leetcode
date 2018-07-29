// Source: https://leetcode.com/problems/sudoku-solver/description/
// Author: Diego Lee
// Date: 2018-07-29
//
// Description:
// Write a program to solve a Sudoku puzzle by filling the empty cells.
//
// A sudoku solution must satisfy all of the following rules:
//
// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// Empty cells are indicated by the character '.'.
//
// Note:
// The given board contain only digits 1-9 and the character '.'.
// You may assume that the given Sudoku puzzle will have a single unique solution.
// The given board size is always 9x9.

#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

#define countof(A) (sizeof A / sizeof(A[0]))

typedef std::vector<std::vector<char>> Matrix;

class Solution
{
    public:
        void solveSudoku(Matrix& board)
        {
            if (board.size() != 9 ||  board[0].size() != 9)
            {
                return;
            }
            solve(board);
        }

        bool solve(Matrix& board)
        {
            for (int i = 0; i < 9; ++i)
            {
                for (int j = 0; j < 9; ++j)
                {
                    if (board[i][j] == '.')
                    {
                        for (char ch = '1'; ch <= '9'; ++ch)
                        {
                            if (isValid(board, i, j, ch))
                            {
                                board[i][j] = ch;
                                if (solve(board))
                                {
                                    return true;
                                }
                                else
                                {
                                    board[i][j] = '.';
                                }
                            }
                        }
                        return false;
                    }
                }
            }
            return true;
        }

        bool isValid(const Matrix& board, int row, int col, char ch)
        {
            int box_x = (row / 3) * 3;
            int box_y = (col / 3) * 3;
            for (int i = 0; i < 9; ++i)
            {
                // check row
                if (board[row][i] == ch)
                {
                    return false;
                }

                // check column
                if (board[i][col] == ch)
                {
                    return false;
                }

                // check box
                if (board[box_x + i / 3][box_y + i % 3] == ch)
                {
                    return false;
                }
            }
            return true;
        }
};

void printMatrix(const Matrix& matrix)
{
    for (size_t i = 0; i < matrix.size(); ++i)
    {
        for (size_t j = 0; j < matrix[i].size(); ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void testSolveSudoku()
{
    char sudoku[][9] =
    {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'},
    };
    Matrix board;
    for (size_t i= 0; i < countof(sudoku); ++i)
    {
        board.push_back(std::vector<char>(std::begin(sudoku[i]), std::end(sudoku[i])));
    }

    printMatrix(board);
    std::cout << "-----------------" << std::endl;

    Solution s;
    s.solveSudoku(board);
    printMatrix(board);
}

int main()
{
    testSolveSudoku();
    return 0;
}
