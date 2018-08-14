// Source: https://leetcode.com/problems/subsets/description/
// Author: Diego Lee
// Date: 2018-08-14
//
// Description:
// Given a set of distinct integers, nums, return all possible subsets (the power set).
//
// Note: The solution set must not contain duplicate subsets.
//
// Example:
//
// Input: nums = [1,2,3]
// Output:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

#include <iostream>
#include <vector>
#include <cassert>

typedef std::vector<std::vector<int>> Matrix;

class Solution
{
    public:
        Matrix subsets(std::vector<int>& nums)
        {
            Matrix result;
            result.push_back(std::vector<int>());
            for (int n = 1; n <= nums.size(); ++n)
            {
                std::vector<int> curr;
                subsetsHelp(nums, 0, n, curr, result);
            }
            return result;
        }

        void subsetsHelp(const std::vector<int>& nums, int start, int count, std::vector<int>& curr, Matrix& result)
        {
            if (curr.size() >= count)
            {
                // printVector(curr);
                result.push_back(curr);
                return;
            }

            for (int i = start; i < nums.size(); ++i)
            {
                curr.push_back(nums[i]);
                subsetsHelp(nums, i + 1, count, curr, result);
                curr.pop_back();
            }
        }

        void printVector(const std::vector<int>& vec)
        {
            for (auto i : vec)
            {
                std::cout << i << " ";
            }
            std::cout << std::endl;
        }
};

void testSubsets()
{
    int A[] = {1, 2, 3};
    std::vector<int> nums(std::begin(A), std::end(A));
    int R1[] = {1};
    int R2[] = {2};
    int R3[] = {3};
    int R4[] = {1,2};
    int R5[] = {1,3};
    int R6[] = {2,3};
    int R7[] = {1,2,3};

    Solution s;
    Matrix result = s.subsets(nums);
    assert(result.size() == 8);
    assert(result[0] == std::vector<int>());
    assert(result[1] == std::vector<int>(std::begin(R1), std::end(R1)));
    assert(result[2] == std::vector<int>(std::begin(R2), std::end(R2)));
    assert(result[3] == std::vector<int>(std::begin(R3), std::end(R3)));
    assert(result[4] == std::vector<int>(std::begin(R4), std::end(R4)));
    assert(result[5] == std::vector<int>(std::begin(R5), std::end(R5)));
    assert(result[6] == std::vector<int>(std::begin(R6), std::end(R6)));
    assert(result[7] == std::vector<int>(std::begin(R7), std::end(R7)));
}

int main()
{
    testSubsets();
    return 0;
}
