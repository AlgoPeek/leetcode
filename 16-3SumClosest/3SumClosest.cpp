// Source: https://leetcode.com/problems/3sum-closest/description/
// Author: Diego Lee
// Date: 2018-07-13
//
// Description:
// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target.
// Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
// Example:
// Given array nums = [-1, 2, 1, -4], and target = 1.
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class Solution
{
    public:
        int threeSumClosest(std::vector<int>& nums, int target)
        {
            // sort array
            std::sort(nums.begin(), nums.end());

            int distance = INT_MAX;
            int result = 0;
            for (size_t i = 0; i < nums.size() - 2; ++i)
            {
                // skip duplication
                if (i > 0 && nums[i] == nums[i - 1])
                {
                    continue;
                }

                int left = i + 1;
                int right = nums.size() - 1;
                // convert 3sum to 2sum problem
                while (left < right)
                {
                    int sum = nums[i] + nums[left] + nums[right];
                    // std::cout << "==>(" << i << "," << left << "," << right << "," << sum << ")"<< std::endl;
                    int dist = sum - target;
                    if (dist == 0)
                    {
                        return target;
                    }
                    else
                    {
                        if (abs(dist) < distance)
                        {
                            distance = abs(dist);
                            result = sum;
                        }

                        if (dist > 0)
                        {
                            // skip duplication
                            while (right > 0 && nums[right] == nums[right - 1])
                            {
                                --right;
                            }

                            // move right pointer
                            --right;
                        }
                        else if (dist < 0)
                        {
                            // skip duplication
                            while (left < nums.size() - 1 && nums[left] == nums[left + 1])
                            {
                                ++left;
                            }
                            // move left pointer
                            ++left;
                        }
                    }
                }
            }
            return result;
        }
};

void testThreeSumClosest()
{
    int A[] = {-1, 2, 1, -4};
    std::vector<int> v(A, A + sizeof(A) / sizeof(int));
    int target = 1;
    assert(Solution().threeSumClosest(v, target) == 2);
}

int main(void)
{
    testThreeSumClosest();
    return 0;
}
