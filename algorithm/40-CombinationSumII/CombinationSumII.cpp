// Source: https://leetcode.com/problems/combination-sum-ii/description/
// Author: Diego Lee
// Date: 2018-07-23
//
// Description:
// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
// Each number in candidates may only be used once in the combination.
//
// Note:
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
//
// Example 1:
// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
//
// Example 2:
// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
// ]

#include <iostream>
#include <vector>
#include <cassert>

#define countof(A) (sizeof A / sizeof A[0])

typedef std::vector<std::vector<int>> Matrix;
class Solution
{
    public:
        Matrix combinationSum2(std::vector<int>& candidates, int target)
        {
            // sort
            std::sort(candidates.begin(), candidates.end());

            Matrix result;
            std::vector<int> curr;
            combinationSum2Help(candidates, 0, target, curr, result);
            return result;
        }

        void combinationSum2Help(std::vector<int>& candidates, size_t start, int target, std::vector<int>& curr, Matrix& result)
        {
            if (target < 0)
            {
                // no solution
                return;
            }

            if (target == 0)
            {
                result.push_back(curr);
            }
            else
            {
                for (size_t i = start; i < candidates.size(); ++i)
                {
                    if (i > start && candidates[i] == candidates[i-1])
                    {
                        // skip duplicate
                        continue;
                    }
                    curr.push_back(candidates[i]);
                    combinationSum2Help(candidates, i + 1, target - candidates[i], curr, result);
                    curr.pop_back();
                }
            }
        }
};

void printMatrix(const Matrix& m)
{
    for (size_t i = 0; i < m.size(); ++i)
    {
        std::for_each(m[i].begin(), m[i].end(), [&](int v){
                std::cout << v << " ";
                });
        std::cout << std::endl;
    }
}
void testCombinationSum2()
{
    int A1[] = {10,1,2,7,6,1,5};
    int target1 = 8;
    std::vector<int> candidates1(std::begin(A1), std::end(A1));

    int R10[] = {1, 1, 6};
    int R11[] = {1, 2, 5};
    int R12[] = {1, 7};
    int R13[] = {2, 6};
    Matrix expire1;
    expire1.push_back(std::vector<int>(std::begin(R10), std::end(R10)));
    expire1.push_back(std::vector<int>(std::begin(R11), std::end(R11)));
    expire1.push_back(std::vector<int>(std::begin(R12), std::end(R12)));
    expire1.push_back(std::vector<int>(std::begin(R13), std::end(R13)));

    Solution s;
    Matrix result = s.combinationSum2(candidates1, target1);
    //printMatrix(result);
    assert(result == expire1);
}

int main()
{
    testCombinationSum2();
    return 0;
}
