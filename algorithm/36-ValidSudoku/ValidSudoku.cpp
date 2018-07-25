// Source: https://leetcode.com/problems/valid-sudoku/description/
// Author: Diego Lee
// Date: 2018-07-25
//
// Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//
// Example 1:
// Input:
// [
//   ["5","3",".",".","7",".",".",".","."],
//   ["6",".",".","1","9","5",".",".","."],
//   [".","9","8",".",".",".",".","6","."],
//   ["8",".",".",".","6",".",".",".","3"],
//   ["4",".",".","8",".","3",".",".","1"],
//   ["7",".",".",".","2",".",".",".","6"],
//   [".","6",".",".",".",".","2","8","."],
//   [".",".",".","4","1","9",".",".","5"],
//   [".",".",".",".","8",".",".","7","9"]
// ]
// Output: true
//
// Example 2:
// Input:
// [
//   ["8","3",".",".","7",".",".",".","."],
//   ["6",".",".","1","9","5",".",".","."],
//   [".","9","8",".",".",".",".","6","."],
//   ["8",".",".",".","6",".",".",".","3"],
//   ["4",".",".","8",".","3",".",".","1"],
//   ["7",".",".",".","2",".",".",".","6"],
//   [".","6",".",".",".",".","2","8","."],
//   [".",".",".","4","1","9",".",".","5"],
//   [".",".",".",".","8",".",".","7","9"]
// ]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner being
//     modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
//
// Note:
// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.
// The given board contain only digits 1-9 and the character '.'.
// The given board size is always 9x9.

#include <iostream>
#include <vector>
#include <cassert>

typedef std::vector<std::vector<char>> Matrix;

class Solution
{
    public:
        bool isValidSudoku(Matrix& board)
        {
            if (board.size() != 9 && board[0].size() != 9)
            {
                return false;
            }

            std::vector<bool> visited;
            // check each row
            for (size_t i = 0; i < board.size(); ++i)
            {
                visited.assign(9, false);
                for (size_t j = 0; j < board[i].size(); ++j)
                {
                    if (!isValid(visited, board[i][j]))
                    {
                        return false;
                    }
                }
            }

            // check each colunm
            for (size_t i = 0; i < board.size(); ++i)
            {
                visited.assign(9, false);
                for (size_t j = 0; j < board.size(); ++j)
                {
                    if (!isValid(visited, board[j][i]))
                    {
                        return false;
                    }
                }
            }

            // check each box
            for (size_t i = 0; i < 9; i += 3)
            {
                for (size_t j = 0; j < 9; j += 3)
                {
                    visited.assign(9, false);
                    for (size_t k = 0; k < 9; ++k)
                    {
                        if (!isValid(visited, board[i + k / 3][j + k % 3]))
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }
    private:
        bool isValid(std::vector<bool>& visited, char ch)
        {
            if (ch == '.')
            {
                return true;
            }

            int num = ch - '0';
            if (num < 1 || num > 9 || visited[num - 1])
            {
                return false;
            }
            visited[num - 1] = true;
            return true;
        }
};

void testIsValidSudoku()
{
    char sodoku[][9] =
    {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Matrix board;
    for (int i = 0; i < 9; ++i)
    {
        board.push_back(std::vector<char>(std::begin(sodoku[i]), std::end(sodoku[i])));
    }

    Solution s;
    assert(s.isValidSudoku(board) == true);
}

int main()
{
    testIsValidSudoku();
    return 0;
}
