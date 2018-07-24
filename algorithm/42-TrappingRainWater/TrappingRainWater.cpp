// Source: https://leetcode.com/problems/trapping-rain-water/description/
// Author: Diego Lee
// Date: 2018-07-24
//
// Description:
// Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it is able to trap after raining.
//
// Example:
// Input: [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6

#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
    public:
        int trap(const std::vector<int>& height)
        {
            return trapByDynamicProgramming(height);
        }

        int trapByBruteForce(const std::vector<int>& height)
        {
            int result = 0;
            int size = static_cast<int>(height.size());
            for (int i = 1; i < size - 1; ++i)
            {
                int maxleft = 0;
                int maxright = 0;
                for (int j = i; j >= 0; --j)
                {
                    maxleft = std::max(maxleft, height[j]);
                }
                for (int k = i; k < size; ++k)
                {
                    maxright = std::max(maxright, height[k]);
                }
                result += std::min(maxleft, maxright) - height[i];
            }
            return result;
        }

        int trapByDynamicProgramming(const std::vector<int>& height)
        {
            if (height.empty())
            {
                return 0;
            }

            int result = 0;
            int size = height.size();
            std::vector<int> max_left(size);
            std::vector<int> max_right(size);
            max_left[0] = height[0];
            for (int i = 1; i < size; ++i)
            {
                max_left[i] = std::max(height[i], max_left[i - 1]);
            }
            max_right[size - 1] = height[size - 1];
            for (int j = size - 2; j >= 0; --j)
            {
                max_right[j] = std::max(height[j], max_right[j + 1]);
            }
            for (int k = 1; k < size - 1; ++k)
            {
                result += std::min(max_left[k], max_right[k]) - height[k];
            }
            return result;
        }
};

void testTrap()
{
    int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    std::vector<int> height(std::begin(A), std::end(A));
    Solution s;
    assert(s.trap(height) == 6);
}

int main()
{
    testTrap();
    return 0;
}
