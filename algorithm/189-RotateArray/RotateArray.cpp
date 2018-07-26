// Source: https://leetcode.com/problems/rotate-array/description/
// Author: Diego Lee
// Date: 2018-07-26
//
// Description:
// Given an array, rotate the array to the right by k steps, where k is non-negative.
//
// Example 1:
//
// Input: [1,2,3,4,5,6,7] and k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
// Example 2:
//
// Input: [-1,-100,3,99] and k = 2
// Output: [3,99,-1,-100]
// Explanation:
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]
// Note:
//
// Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
// Could you do it in-place with O(1) extra space?

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

void printVector(const std::vector<int>& vec);

class Solution
{
    public:
        void rotate(std::vector<int>& nums, int k)
        {
            if (nums.empty())
            {
                return ;
            }

            k %= nums.size();
            if (k == 0)
            {
                return;
            }

            std::vector<int> buffer(k);
            int left = nums.size() - k;
            std::copy(nums.begin() + left, nums.end(), buffer.begin());
            std::copy(nums.begin(), nums.begin() + left, nums.begin() + k);
            std::copy(buffer.begin(), buffer.end(), nums.begin());
        }
};

void printVector(const std::vector<int>& vec)
{
    for (auto v : vec)
    {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

void testRotate()
{
    int A[] = {1,2,3,4,5,6,7};
    int R[] = {5,6,7,1,2,3,4};
    std::vector<int> nums(std::begin(A), std::end(A));

    Solution s;
    s.rotate(nums, 3);
    // printVector(nums);
    assert(nums == std::vector<int>(std::begin(R), std::end(R)));
}

int main()
{
    testRotate();
    return 0;
}
