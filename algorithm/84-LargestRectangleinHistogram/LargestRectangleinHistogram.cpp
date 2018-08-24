// Source: https://leetcode.com/problems/largest-rectangle-in-histogram/description/
// Author: Diego Lee
// Date: 2018-08-24
//
// Description:
// Given n non-negative integers representing the histogram's bar height where the width of
// each bar is 1, find the area of largest rectangle in the histogram.
//
// Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
// The largest rectangle is shown in the shaded area, which has area = 10 unit.
//
// Example:
//
// Input: [2,1,5,6,2,3]
// Output: 10

#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
    public:
        int largestRectangleArea(std::vector<int>& heights)
        {
            if (heights.empty())
            {
                return 0;
            }

            int len = heights.size();
            std::vector<int> lessFromLeft(len); // index of the first bar from left that is lower than current
            std::vector<int> lessFromRight(len);// index of the first bar from right that is lower than current
            lessFromLeft[0] = -1;
            lessFromRight[len - 1] = len;
            for (int i = 1; i < len; ++i)
            {
                int k = i - 1;
                while (k >= 0 && heights[k] >= heights[i])
                {
                    k = lessFromLeft[k];
                }
                lessFromLeft[i] = k;
            }
            for (int i = len - 2; i >= 0; --i)
            {
                int k = i + 1;
                while (k < len && heights[k] >= heights[i])
                {
                    k = lessFromRight[k];
                }
                lessFromRight[i] = k;
            }

            int result = 0;
            for (int i = 0; i < len; ++i)
            {
                result = std::max(result, heights[i] * (lessFromRight[i] - lessFromLeft[i] - 1));
            }
            return result;
        }
};

void testLargestRectangleArea()
{
    int A[] = {2,1,5,6,2,3};
    std::vector<int> nums(std::begin(A), std::end(A));

    Solution s;
    int result = s.largestRectangleArea(nums);
    assert(result == 10);
}

int main()
{
    testLargestRectangleArea();
    return 0;
}
