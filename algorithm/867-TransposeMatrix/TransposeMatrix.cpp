// Source: https://leetcode.com/problems/transpose-matrix/submissions/
// Author: Diego Lee
// Date: 2019-02-13
//
// Description:
// Given a matrix A, return the transpose of A.
//
// The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.
//
//
//
// Example 1:
//
// Input: [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[1,4,7],[2,5,8],[3,6,9]]
// Example 2:
//
// Input: [[1,2,3],[4,5,6]]
// Output: [[1,4],[2,5],[3,6]]
//
//
// Note:
//
// 1 <= A.length <= 1000
// 1 <= A[0].length <= 1000

#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

class Solution {
    public:
        vector<vector<int>> transpose(vector<vector<int>>& A) {
            vector<vector<int>> result;
            if (A.empty()) {
                return result;
            }

            int rowLength = A.size();
            int colLength = A[0].size();
            for (int j = 0; j < colLength; ++j) {
                std::vector<int> rowTrans;
                for (int i = 0; i < rowLength; ++i) {
                    rowTrans.push_back(A[i][j]);
                }
                result.push_back(rowTrans);
            }
            return result;
        }
};

void testTranspose() {
    std::vector<std::vector<int>> A;
    A.push_back(std::vector<int>({1,2,3}));
    A.push_back(std::vector<int>({4,5,6}));
    A.push_back(std::vector<int>({7,8,9}));

    Solution s;
    auto result = s.transpose(A);
    assert(result.size() == 3);
    assert(result[0] == std::vector<int>({1,4,7}));
    assert(result[1] == std::vector<int>({2,5,8}));
    assert(result[2] == std::vector<int>({3,6,9}));
}

int main() {
    testTranspose();
    return 0;
}
