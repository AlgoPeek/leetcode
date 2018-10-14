// Source: https://leetcode.com/problems/number-of-islands/description/
// Author: Diego Lee
// Date: 2018-10-14
//
// Description:
// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
// Example 1:
//
// Input:
// 11110
// 11010
// 11000
// 00000
//
// Output: 1
// Example 2:
//
// Input:
// 11000
// 11000
// 00100
// 00011
//
// Output: 3

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
    const char FLAG_ISLAND = '1';
    const char FLAG_WATER = '0';
    const char FLAG_VISITED = 'X';
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int count = 0;
        for (size_t i = 0; i < grid.size(); ++i) {
            for (size_t j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == FLAG_ISLAND) {
                    ++count;
                    dfsVisit(i, j, grid);
                }
            }
        }
        return count;
    }

    void dfsVisit(int i, int j, std::vector<std::vector<char>>& grid) {
        if (i < 0
                || j < 0
                || i >= grid.size()
                || j >= grid[0].size()
                || grid[i][j] == FLAG_VISITED
                || grid[i][j] == FLAG_WATER) {
            return;
        }
        if (grid[i][j] == FLAG_ISLAND) {
            grid[i][j] = FLAG_VISITED;
        }
        dfsVisit(i+1, j, grid);
        dfsVisit(i-1, j, grid);
        dfsVisit(i, j+1, grid);
        dfsVisit(i, j-1, grid);
    }
};

void testNumIslandsCase1() {
    std::vector<std::vector<char>> grid;
    grid.push_back(std::vector<char>({'1', '1', '1', '1', '0'}));
    grid.push_back(std::vector<char>({'1', '1', '0', '1', '0'}));
    grid.push_back(std::vector<char>({'1', '1', '0', '0', '0'}));
    grid.push_back(std::vector<char>({'0', '0', '0', '0', '0'}));

    Solution s;
    int result = s.numIslands(grid);
    assert(result == 1);
}

void testNumIslandsCase2() {
    std::vector<std::vector<char>> grid;
    grid.push_back(std::vector<char>({'1','1','1'}));
    grid.push_back(std::vector<char>({'0','1','0'}));
    grid.push_back(std::vector<char>({'1','1','1'}));

    Solution s;
    int result = s.numIslands(grid);
    assert(result == 1);
}

int main() {
    testNumIslandsCase1();
    testNumIslandsCase2();
    return 0;
}
