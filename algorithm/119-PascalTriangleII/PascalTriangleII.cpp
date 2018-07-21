// Source: https://leetcode.com/problems/pascals-triangle-ii/description/
// Author: Diego Lee
// Date: 2018-07-21
//
// Description:
// Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
// Note that the row index starts from 0.
// In Pascal's triangle, each number is the sum of the two numbers directly above it.
// Example:
// Input: 3
// Output: [1,3,3,1]
// Follow up:
// Could you optimize your algorithm to use only O(k) extra space?

#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
    public:
        std::vector<int> getRow(int rowIndex)
        {
            if (rowIndex == 0)
            {
                return std::vector<int>(1, 1);
            }
            else
            {
                std::vector<int> result(2, 1);
                for (int i = 2; i <= rowIndex; ++i)
                {
                    std::vector<int> prev;
                    result.swap(prev);

                    result.push_back(1);
                    for (int j = 0; j < prev.size() - 1; ++j)
                    {
                        result.push_back(prev[j] + prev[j + 1]);
                    }
                    result.push_back(1);
                }
                return result;
            }
        }
};

void testGetRow()
{
    int R[] = {1, 3, 3, 1};
    Solution s;
    assert(s.getRow(3) == std::vector<int>(std::begin(R), std::end(R)));
}

int main()
{
    testGetRow();
    return 0;
}
