// Source: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
// Author: Diego Lee
// Date: 2018-07-21
//
// Description:
// Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
//
// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
//
// Note:
//
// Your returned answers (both index1 and index2) are not zero-based.
// You may assume that each input would have exactly one solution and you may not use the same element twice.
// Example:
//
// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
//
#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
    public:
        std::vector<int> twoSum(std::vector<int>& numbers, int target)
        {
            std::vector<int> result;
            for (int i = 0; i < numbers.size(); ++i)
            {
                if (numbers[i] <= target)
                {
                    int newTarget = target - numbers[i];
                    int left = i + 1;
                    int right = numbers.size() - 1;
                    while (left <= right)
                    {
                        int mid = left + (right - left) / 2;
                        if (numbers[mid] < newTarget)
                        {
                            left = mid + 1;
                        }
                        else if (numbers[mid] > newTarget)
                        {
                            right = mid - 1;
                        }
                        else
                        {
                            result.push_back(i + 1);
                            result.push_back(mid + 1);
                            return result;
                        }
                    }
                }
                else
                {
                    break;
                }
            }
            return result;
        }
};

void testTwoSum()
{
    int A[] = {2, 7, 11, 15};
    std::vector<int> nums(std::begin(A), std::end(A));
    Solution s;
    std::vector<int> result = s.twoSum(nums, 9);
    assert(result.size() == 2);
    assert(result[0] == 1 && result[1] == 2);
}

int main()
{
    testTwoSum();
    return 0;
}
