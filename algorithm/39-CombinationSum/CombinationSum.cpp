// Source: https://leetcode.com/problems/combination-sum/description/
// Author: Diego Lee
// Date: 2018-07-17
//
// Description:
// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
// The same repeated number may be chosen from candidates unlimited number of times.
//
// Note:
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
//
// Example 1:
//
// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
//
// Example 2:
// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]

#include <iostream>
#include <vector>
#include <cassert>

#define countof(A) (sizeof A / sizeof A[0])
#define MAKE_VECTOR(A) std::vector<int>(std::begin(A), std::end(A))

typedef std::vector<std::vector<int>> Matrix;

class Solution
{
    public:
        Matrix combinationSum(std::vector<int>& candidates, int target)
        {
            Matrix result;
            std::vector<int> curr;
            combinationSumHelp(candidates, 0, target, curr, result);
            return result;
        }

        void combinationSumHelp(std::vector<int>& candidates, int i, int target,
            std::vector<int>& curr, Matrix& result)
        {
            if (i >= candidates.size())
            {
                return;
            }

            if (candidates[i] == target)
            {
                result.push_back(curr);
                result.back().push_back(candidates[i]);
            }
            else if (candidates[i] < target)
            {
                curr.push_back(candidates[i]);
                combinationSumHelp(candidates, i, target - candidates[i], curr, result);
                curr.pop_back();
            }
            combinationSumHelp(candidates, i + 1, target, curr, result);
        }
};

void testCombinationSum()
{
    int A1[] = {2, 3, 6, 7};
    int R10[] = {2, 2, 3};
    int R11[] = {7};
    Matrix expire1;
    expire1.push_back(MAKE_VECTOR(R10));
    expire1.push_back(MAKE_VECTOR(R11));

    Solution s;
    std::vector<int> candidates = MAKE_VECTOR(A1);
    assert(s.combinationSum(candidates, 7) == expire1);

    int A2[] = {2, 3, 5};
    int R20[] = {2, 2, 2, 2};
    int R21[] = {2, 3, 3};
    int R22[] = {3, 5};
    Matrix expire2;
    expire2.push_back(MAKE_VECTOR(R20));
    expire2.push_back(MAKE_VECTOR(R21));
    expire2.push_back(MAKE_VECTOR(R22));
    candidates = MAKE_VECTOR(A2);
    assert(s.combinationSum(candidates, 8) == expire2);
}

int main()
{
    testCombinationSum();
    return 0;
}
