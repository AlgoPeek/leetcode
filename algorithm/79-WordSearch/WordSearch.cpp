// Source: https://leetcode.com/problems/word-search/description/
// Author: Diego Lee
// Date: 2018-08-17
//
// Description:
// Given a 2D board and a word, find if the word exists in the grid.
//
// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
//
// Example:
//
// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]
//
// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

#define countof(A) (sizeof A / sizeof(A[0]))

class Solution
{
    public:
        bool exist(std::vector<std::vector<char>>& board, std::string word)
        {
            if (board.empty() || word.empty())
            {
                return false;
            }

            std::vector<std::vector<bool>> visit;
            for (int i = 0; i < board.size(); ++i)
            {
                visit.push_back(std::vector<bool>(board[i].size(), false));
            }
            for (int i = 0; i < board.size(); ++i)
            {
                for (int j = 0; j < board[i].size(); ++j)
                {
                    if (existHelp(board, visit, i, j, word, 0))
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        bool existHelp(std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& visit,
                int i, int j, const std::string& word, int k)
        {
            if (k >= word.size())
            {
                return true;
            }

            int n = board.size();
            int m = board[0].size();
            if (i < 0 || i >= n || j < 0 || j >= m)
            {
                return false;
            }
            if (visit[i][j] == true)
            {
                return false;
            }
            if (board[i][j] != word[k])
            {
                return false;
            }

            // std::cout << "visit(" << i << "," << j << "), - " << board[i][j] << std::endl;
            visit[i][j] = true;
            bool bExist = existHelp(board, visit, i, j + 1, word, k + 1)
                || existHelp(board, visit, i + 1, j, word, k + 1)
                || existHelp(board, visit, i - 1, j, word, k + 1)
                || existHelp(board, visit, i, j - 1, word, k + 1);
            visit[i][j] = false;
            return bExist;
        }
};

void testExist()
{
    char map[][4] =
    {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    std::vector<std::vector<char>> board;
    for (int i = 0; i < countof(map); ++i)
    {
        board.push_back(std::vector<char>(std::begin(map[i]), std::end(map[i])));
    }

    Solution s;
    assert(s.exist(board, std::string("ABCCED")) == true);
    assert(s.exist(board, std::string("SEE")) == true);
    assert(s.exist(board, std::string("ABCB")) == false);
}

int main()
{
    testExist();
    return 0;
}
