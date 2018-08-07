// Source: https://leetcode.com/problems/contains-duplicate-ii/description/
// Author: Diego Lee
// Date: 2018-08-07
//
// Description:
//
// Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
//
// Example 1:
//
// Input: nums = [1,2,3,1], k = 3
// Output: true
// Example 2:
//
// Input: nums = [1,0,1,1], k = 1
// Output: true
// Example 3:
//
// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false

#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>

typedef std::pair<int, int> Index2DistancePair;

class Solution
{
    public:
        bool containsNearbyDuplicate(std::vector<int>& nums, int k)
        {
            std::unordered_map<int, Index2DistancePair> hash;
            for (size_t i = 0; i < nums.size(); ++i)
            {
                int curr = nums[i];
                if (hash.find(curr) == hash.end())
                {
                    hash[curr] = std::make_pair(i, 0);
                }
                else
                {
                    Index2DistancePair& i2d = hash[curr];
                    i2d.second = i - i2d.first;
                    i2d.first = i;
                    if (i2d.second <= k)
                    {
                        return true;
                    }
                }
            }
            return false;
        }
};

void testContainsNearByDuplicate()
{
    int A1[] = {1,2,3,1};
    int A2[] = {1,0,1,1};
    int A3[] = {1,2,3,1,2,3};
    std::vector<int> nums1(std::begin(A1), std::end(A1));
    std::vector<int> nums2(std::begin(A2), std::end(A2));
    std::vector<int> nums3(std::begin(A3), std::end(A3));

    Solution s;
    assert(s.containsNearbyDuplicate(nums1, 3) == true);
    assert(s.containsNearbyDuplicate(nums2, 1) == true);
    assert(s.containsNearbyDuplicate(nums3, 2) == false);
}

int main()
{
    testContainsNearByDuplicate();
    return 0;
}
