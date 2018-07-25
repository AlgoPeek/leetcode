// Source: https://leetcode.com/problems/kth-largest-element-in-an-array/description/
// Author: Diego Lee
// Date: 2018-07-26
//
// Description:
// Find the kth largest element in an unsorted array. Note that it is the kth largest element
// in the sorted order, not the kth distinct element.
//
// Example 1:
// Input: [3,2,1,5,6,4] and k = 2
// Output: 5
//
// Example 2:
// Input: [3,2,3,1,2,4,5,5,6] and k = 4
// Output: 4
//
// Note:
// You may assume k is always valid, 1 ≤ k ≤ array's length.

#include <iostream>
#include <queue>
#include <algorithm>
#include <cassert>
#include <vector>

class Solution
{
    public:
        int findKthLargest(std::vector<int>& nums, int k)
        {
            std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
            for (auto n : nums)
            {
                if (pq.size() < k)
                {
                    pq.push(n);
                }
                else
                {
                    if (n > pq.top())
                    {
                        pq.pop();
                        pq.push(n);
                    }
                }
            }
            return pq.top();
        }
};

void testFindKthLargest()
{
    int A[] = {3, 2, 1, 5, 6, 4};
    std::vector<int> nums(std::begin(A), std::end(A));
    Solution s;
    assert(s.findKthLargest(nums, 2) == 5);
}

int main()
{
    testFindKthLargest();
    return 0;
}
