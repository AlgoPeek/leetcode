// Source: https://leetcode.com/problems/triangle/description/
// Author: Diego Lee
// Date: 2018-09-06
//
// Description:
// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
//
// For example, given the following triangle
//
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
// Note:
//
// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
//

#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
    public:
        int minimumTotal(std::vector<std::vector<int>>& triangle)
        {
            if (triangle.empty() || triangle[0].empty())
            {
                return 0;
            }

            std::vector<int> dp = triangle.back();
            for (int layer = triangle.size() - 2; layer >= 0; --layer)
            {
                for (int i = 0; i <= layer; ++i)
                {
                    // Find the lesser of its two children,
                    // and sum the current value in the triangle with it.
                    dp[i] = std::min(dp[i], dp[i+1]) + triangle[layer][i];
                }
            }
            return dp[0];
        }
};

void testMinimumTotal()
{
    std::vector<std::vector<int>> triangle;
    triangle.push_back(std::vector<int>({2}));
    triangle.push_back(std::vector<int>({3, 4}));
    triangle.push_back(std::vector<int>({6, 5, 7}));
    triangle.push_back(std::vector<int>({4, 1, 8, 3}));

    Solution s;
    int result = s.minimumTotal(triangle);
    std::cout << "result=" << result << std::endl;
    assert(result == 11);
}

int main()
{
    testMinimumTotal();
    return 0;
}
