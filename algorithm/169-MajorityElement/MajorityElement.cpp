// Source: https://leetcode.com/problems/majority-element/description/
// Author: Diego Lee
// Date: 2018-07-14
//
// Description:
// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
// You may assume that the array is non-empty and the majority element always exist in the array.
//
// Example 1:
// Input: [3,2,3]
// Output: 3
//
// Example 2:
// Input: [2,2,1,1,1,2,2]
// Output: 2

#include <iostream>
#include <vector>
#include <map>
#include <cassert>

class Solution
{
    public:
        int majorityElement(std::vector<int>& nums)
        {
            std::map<int, int> mapVal2Count;
            int majTimes = nums.size() / 2;
            int majElement = 0;
            for (size_t i = 0; i < nums.size(); ++i)
            {
                int val = nums[i];
                std::map<int, int>::iterator it = mapVal2Count.find(val);
                if (it == mapVal2Count.end())
                {
                    it = mapVal2Count.insert(std::make_pair(val, 0)).first;
                }
                if (++it->second > majTimes)
                {
                    majElement = val;
                    break;
                }
            }
            return majElement;
        }
};

void testMajorityElement()
{
    int A1[] = {3,2,3};
    int A2[] = {2,2,1,1,1,2,2};
    std::vector<int> num1(std::begin(A1), std::end(A1));
    std::vector<int> num2(std::begin(A2), std::end(A2));
    assert(Solution().majorityElement(num1) == 3);
    assert(Solution().majorityElement(num2) == 2);
}

int main()
{
    testMajorityElement();
    return 0;
}
