// Source: https://leetcode.com/problems/permutations-ii/description/
// Author: Diego Lee
// Date: 2018-07-16
//
// Description:
// Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
// Example:
// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]

#include <iostream>
#include <vector>
#include <set>

#define countof(A) (sizeof A / sizeof A[0])

typedef std::vector<std::vector<int>> Matrix;

class Solution
{
    public:
        Matrix permuteUnique(std::vector<int>& nums)
        {
            return permuteUniqueHelp(nums, 0);
        }

        Matrix permuteUniqueHelp(std::vector<int>& nums, int start)
        {
            Matrix result;
            if (start >= nums.size())
            {
                return result;
            }

            if (start == nums.size() - 1)
            {
                std::vector<int> vec(1, nums[start]);
                result.push_back(vec);
                return result;
            }

            std::set<int> s;
            for (int i = start; i < static_cast<int>(nums.size()); ++i)
            {
                if (s.find(nums[i]) != s.end())
                {
                    continue;
                }

                s.insert(nums[i]);
                std::swap(nums[start], nums[i]);
                Matrix matrix = permuteUniqueHelp(nums, start + 1);
                std::swap(nums[i], nums[start]);
                for (size_t j = 0; j < matrix.size(); ++j)
                {
                    matrix[j].push_back(nums[i]);
                    result.push_back(matrix[j]);
                }
            }
            return result;
        }
};

void printMatrix(const Matrix& matrix)
{
    for (size_t i = 0; i < matrix.size(); ++i)
    {
        std::for_each(matrix[i].begin(), matrix[i].end(), [&](int v){
                std::cout << v << " ";
                });
        std::cout << std::endl;
    }
}

void testPermuteUnique(void)
{
    int A[] = {2,2,1,1};
    int R[][4] =
    {
        {1, 1, 2, 2},
        {1, 2, 1, 2},
        {2, 1, 1, 2},
        {1, 2, 2, 1},
        {2, 1, 2, 1},
        {2, 2, 1, 1}
    };
    std::vector<int> nums(std::begin(A), std::end(A));
    Matrix expire;
    for (int i= 0; i < countof(R); ++i)
    {
        expire.push_back(std::vector<int>(std::begin(R[i]), std::end(R[i])));
    }
    Matrix result = Solution().permuteUnique(nums);
    // printMatrix(result);
    assert(result == expire);
}

int main()
{
    testPermuteUnique();
    return 0;
}
