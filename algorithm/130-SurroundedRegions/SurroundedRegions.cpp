// Source: https://leetcode.com/problems/surrounded-regions/description/
// Author: Diego Lee
// Date: 2018-10-14
//
// Description:
//
// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
//
// A region is captured by flipping all 'O's into 'X's in that surrounded region.
//
// Example:
//
// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:
//
// X X X X
// X X X X
// X X X X
// X O X X
// Explanation:
//
// Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

#include <iostream>
#include <vector>
#include <cassert>

typedef std::vector<std::vector<char>> Board;

#define FLAG_O 'O'
#define FLAG_X 'X'
#define FLAG_1 '1'

void printBoard(const Board& board);

class Solution {
    public:
        void solve(Board& board) {
            if (board.empty()) {
                return;
            }

            int row = board.size();
            int col = board[0].size();
            // traverse left, right boarder
            for (int i = 0; i < row; ++i) {
                if (board[i][0] == FLAG_O) {
                    dfs(i, 1, board);
                }
                if (col > 1 && board[i][col - 1] == FLAG_O) {
                    dfs(i, col - 2, board);
                }
            }

            // traverse top, bottom boarder
            for (int j = 1; j < col - 1; ++j) {
                if (board[0][j] == FLAG_O) {
                    dfs(1, j, board);
                }
                if (row > 1 && board[row - 1][j] == FLAG_O) {
                    dfs(row - 2, j, board);
                }
            }

            for (int i = 1; i < row - 1; ++i) {
                for (int j = 1; j < col - 1; ++j) {
                    if (board[i][j] == FLAG_O) {
                        board[i][j] = FLAG_X;
                    }
                    else if (board[i][j] == FLAG_1) {
                        board[i][j] = FLAG_O;
                    }
                }
            }
        }

        void dfs(int i, int j, Board& board) {
            if (i <= 0
                || j <= 0
                || board.empty()
                || i >= board.size() - 1
                || j >= board[0].size() - 1
                || board[i][j] == FLAG_X
                || board[i][j] == FLAG_1) {
                return;
            }

            board[i][j] = FLAG_1;
            dfs(i+1, j, board);
            dfs(i-1, j, board);
            dfs(i, j+1, board);
            dfs(i, j-1, board);
        }
};

void printBoard(const Board& board) {
    for (auto row : board) {
        for (auto ch : row) {
            std::cout << ch << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void testSolveCase1() {
    Board board;
    board.push_back(std::vector<char>({'X', 'X', 'X', 'X'}));
    board.push_back(std::vector<char>({'X', 'O', 'O', 'X'}));
    board.push_back(std::vector<char>({'X', 'X', 'O', 'X'}));
    board.push_back(std::vector<char>({'X', 'O', 'X', 'X'}));

    Board expected;
    expected.push_back(std::vector<char>({'X', 'X', 'X', 'X'}));
    expected.push_back(std::vector<char>({'X', 'X', 'X', 'X'}));
    expected.push_back(std::vector<char>({'X', 'X', 'X', 'X'}));
    expected.push_back(std::vector<char>({'X', 'O', 'X', 'X'}));

    Solution s;
    s.solve(board);
    // printBoard(board);
    assert(board == expected);
}

void testSolveCase2() {
    Board board;
    board.push_back(std::vector<char>({'O', 'O', 'O'}));
    board.push_back(std::vector<char>({'O', 'O', 'O'}));
    board.push_back(std::vector<char>({'O', 'O', 'O'}));

    Board expected;
    expected.push_back(std::vector<char>({'O', 'O', 'O'}));
    expected.push_back(std::vector<char>({'O', 'O', 'O'}));
    expected.push_back(std::vector<char>({'O', 'O', 'O'}));

    Solution s;
    s.solve(board);
    // printBoard(board);
    assert(board == expected);
}

int main() {
     testSolveCase1();
    testSolveCase2();
    return 0;
}
