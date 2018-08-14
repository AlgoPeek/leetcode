// Source: https://leetcode.com/problems/subsets-ii/description/
// Author: Diego Lee
// Date: 2018-08-14
//
// Description:
// Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
//
// Note: The solution set must not contain duplicate subsets.
//
// Example:
//
// Input: [1,2,2]
// Output:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

typedef std::vector<std::vector<int>> Matrix;

class Solution
{
    public:
        Matrix subsetsWithDup(std::vector<int>& nums)
        {
            std::sort(nums.begin(), nums.end());

            Matrix result;
            result.push_back(std::vector<int>());
            for (int n = 1; n <= nums.size(); ++n)
            {
                std::vector<int> curr;
                subsetWithDupHelp(nums, 0, n, curr, result);
            }
            return result;
        }

        void subsetWithDupHelp(const std::vector<int>& nums, int start, int count, std::vector<int>& curr, Matrix& result)
        {
            if (curr.size() >= count)
            {
                // printVector(curr);
                result.push_back(curr);
                return ;
            }

            for (int i = start; i < nums.size(); ++i)
            {
                if (i == start || nums[i] != nums[i-1])
                {
                    curr.push_back(nums[i]);
                    subsetWithDupHelp(nums, i + 1, count, curr, result);
                    curr.pop_back();
                }
            }
        }

        void printVector(const std::vector<int>& vec)
        {
            for (int i : vec)
            {
                std::cout << i << " ";
            }
            std::cout << std::endl;
        }
};

void testSubsetWithDup()
{
    int A[] = {1,2,2};
    std::vector<int> nums(std::begin(A), std::end(A));

    int R1[] = {1};
    int R2[] = {2};
    int R3[] = {1,2};
    int R4[] = {2,2};
    int R5[] = {1,2,2};

    Solution s;
    Matrix result = s.subsetsWithDup(nums);
    assert(result.size() == 6);
    assert(result[0] == std::vector<int>());
    assert(result[1] == std::vector<int>(std::begin(R1), std::end(R1)));
    assert(result[2] == std::vector<int>(std::begin(R2), std::end(R2)));
    assert(result[3] == std::vector<int>(std::begin(R3), std::end(R3)));
    assert(result[4] == std::vector<int>(std::begin(R4), std::end(R4)));
    assert(result[5] == std::vector<int>(std::begin(R5), std::end(R5)));
}

int main()
{
    testSubsetWithDup();
    return 0;
}
