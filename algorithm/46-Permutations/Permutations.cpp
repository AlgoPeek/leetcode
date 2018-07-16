// Source: https://leetcode.com/problems/permutations/description/
// Author: Diego Lee

//
// Description:
// Given a collection of distinct integers, return all possible permutations.
//
// Example:
// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

#include <iostream>
#include <cassert>
#include <vector>

#define countof(A) (sizeof A / sizeof A[0])

typedef std::vector<std::vector<int>> Matrix;

class Solution {
    public:
        Matrix permute(std::vector<int>& nums) {
            return permuteHelp(nums, 0);
        }
    private:
        Matrix permuteHelp(std::vector<int>& nums, int start)
        {
            Matrix result;

            int count = static_cast<int>(nums.size());
            if (start >= count)
            {
                return result;
            }

            if (start == count - 1)
            {
                std::vector<int> vec;
                vec.push_back(nums[start]);
                result.push_back(vec);
            }
            else
            {
                for (int i = start; i < static_cast<int>(nums.size()); ++i)
                {
                    std::swap(nums[start], nums[i]);
                    Matrix matrix = permuteHelp(nums, start + 1);
                    for (size_t j = 0; j < matrix.size(); ++j)
                    {
                        std::vector<int> vec(matrix[j].size() + 1);
                        vec[0] = nums[start];
                        std::copy(matrix[j].begin(), matrix[j].end(), vec.begin() + 1);
                        result.push_back(vec);
                    }
                    std::swap(nums[i], nums[start]);
                }
            }
            return result;
        }
};

void testPermute()
{
    int A[] = {1, 2, 3};
    std::vector<int> nums(std::begin(A), std::end(A));
    Matrix result = Solution().permute(nums);

    assert(result.size() == 6);
    int r0[] = {1,2,3};
    int r1[] = {1,3,2};
    int r2[] = {2,1,3};
    int r3[] = {2,3,1};
    int r4[] = {3,2,1};
    int r5[] = {3,1,2};
    assert(result[0] == std::vector<int>(r0, r0 + countof(r0)));
    assert(result[1] == std::vector<int>(r1, r1 + countof(r1)));
    assert(result[2] == std::vector<int>(r2, r2 + countof(r2)));
    assert(result[3] == std::vector<int>(r3, r3 + countof(r3)));
    assert(result[4] == std::vector<int>(r4, r4 + countof(r4)));
    assert(result[5] == std::vector<int>(r5, r5 + countof(r5)));
}

int main()
{
    testPermute();
    return 0;
}
