// Source: https://leetcode.com/problems/contains-duplicate/description/
// Author: Diego Lee
// Date: 2018-07-24
//
// Description:
// Given an array of integers, find if the array contains any duplicates.
// Your function should return true if any value appears at least twice in the array,
// and it should return false if every element is distinct.
//
// Example 1:
// Input: [1,2,3,1]
// Output: true
//
// Example 2:
// Input: [1,2,3,4]
// Output: false
//
// Example 3:
// Input: [1,1,1,3,3,4,3,2,4,2]
// Output: true

#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_set>

class Solution
{
    public:
        bool containsDuplicate(const std::vector<int>& nums)
        {
            bool exits = false;
            std::unordered_set<int> hash;
            for (auto n : nums)
            {
                if (hash.find(n) != hash.end())
                {
                    exits = true;
                    break;
                }
                else
                {
                    hash.insert(n);
                }
            }
            return exits;
        }
};

void testContainsDuplicate()
{
    int A1[] = {1, 2, 3, 1};
    int A2[] = {1, 2, 3, 4};
    Solution s;
    assert(s.containsDuplicate(std::vector<int>(std::begin(A1), std::end(A1))) == true);
    assert(s.containsDuplicate(std::vector<int>(std::begin(A2), std::end(A2))) == false);
}

int main()
{
    testContainsDuplicate();
    return 0;
}

