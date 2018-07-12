// Source: https://leetcode.com/problems/container-with-most-water/description/
// Author: Diego Lee
// Date: 2018-07-12
//
// Description:
// Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
// n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
// Find two lines, which together with x-axis forms a container, such that the container contains the most water.
//
// Note: You may not slant the container and n is at least 2.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define countof(A) (sizeof A / sizeof A[0])

class Solution
{
public:
    int maxArea(std::vector<int>& height)
    {
        int area = 0;
        int left = 0;
        int right = static_cast<int>(height.size()) - 1;
        while (left < right)
        {
            int w = right - left;
            int h = std::min(height[left], height[right]);
            area = std::max(area, w * h);
            if (height[left] < height[right])
            {
                ++left;
            }
            else
            {
                --right;
            }
        }
        return area;
    }
private:
    int maxAreaByBruteForce(std::vector<int>& height)
    {
        int area = 0;
        for (size_t i = 0; i < height.size(); ++i)
        {
            for (size_t j = i + 1; j < height.size(); ++j)
            {
                area = std::max(area, static_cast<int>((j - i)) * std::min(height[i], height[j]));
            }
        }
        return area;
    }
};

void testMaxArea()
{
    int A[] = {1, 2, 1, 3};
    std::vector<int> height(A, A + countof(A));
    int result = Solution().maxArea(height);
    assert(result == 4);
}

int main()
{
    testMaxArea();
    return 0;
}
