// Source: https://leetcode.com/problems/maximal-rectangle/description/
// Author: Diego Lee
// Date: 2018-09-30
//
// Description:
// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
//
// Example:
//
// Input:
// [
//   ["1","0","1","0","0"],
//   ["1","0","1","1","1"],
//   ["1","1","1","1","1"],
//   ["1","0","0","1","0"]
// ]
// Output: 6

#include <iostream>
#include <vector>
#include <cassert>

typedef std::vector<std::vector<char>> Matrix;

class Solution {
    public:
        int maximalRectangle(std::vector<std::vector<char>>& matrix) {
            if (matrix.empty()) {
                return 0;
            }

            int m = matrix.size();
            int n = matrix[0].size();
            std::vector<int> left(n, 0);
            std::vector<int> right(n, n);
            std::vector<int> height(n, 0);
            int maxArea = 0;
            for (int i = 0; i < m; ++i) {
                // compute height
                for (int j = 0; j < n; ++j) {
                    if (matrix[i][j] == '1') {
                        ++height[j];
                    }
                    else {
                        height[j] = 0;
                    }
                }

                // compute left, from left to right
                int curr_left = 0;
                for (int j = 0; j < n; ++j) {
                    if (matrix[i][j] == '1') {
                        left[j] = std::max(left[j], curr_left);
                    }
                    else {
                        left[j] = 0;
                        curr_left = j + 1;
                    }
                }

                // compute right, from right to left
                int curr_right = n;
                for (int j = n - 1; j >= 0; --j) {
                    if (matrix[i][j] == '1') {
                        right[j] = std::min(right[j], curr_right);
                    }
                    else {
                        right[j] = n;
                        curr_right = j;
                    }
                }

                // compute max area
                for (int j = 0; j < n; ++j) {
                    maxArea = std::max(maxArea, (right[j] - left[j]) * height[j]);
                }
            }
            return maxArea;
        }
};


void testMaximalRectangle() {
    Matrix matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    Solution s;
    int result = s.maximalRectangle(matrix);
    assert(result == 6);
}

int main() {
    testMaximalRectangle();
    return 0;
}
