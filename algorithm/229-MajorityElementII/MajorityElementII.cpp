// Source: https://leetcode.com/problems/majority-element-ii/description/
// Author: Diego Lee
// Date: 2018-07-14
//
// Description:
// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
// Note: The algorithm should run in linear time and in O(1) space.
//
// Example 1:
// Input: [3,2,3]
// Output: [3]
//
// Example 2:
// Input: [1,1,1,3,3,2,2,2]
// Output: [1,2]

#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
    public:
        std::vector<int> majorityElement(std::vector<int>& nums)
        {
            int maj1 = 0, cnt1 = 0;
            int maj2 = 0, cnt2 = 0;
            for (auto n : nums)
            {
                if (n == maj1)
                {
                    ++cnt1;
                }
                else if (n == maj2)
                {
                    ++cnt2;
                }
                else if (cnt1 == 0)
                {
                    maj1 = n;
                    cnt1 = 1;
                }
                else if (cnt2 == 0)
                {
                    maj2 = n;
                    cnt2 = 1;
                }
                else
                {
                    --cnt1;
                    --cnt2;
                }
            }

            // recheck
            cnt1 = 0;
            cnt2 = 0;
            for (auto n : nums)
            {
                if (n == maj1)
                {
                    ++cnt1;
                }
                if (n == maj2)
                {
                    ++cnt2;
                }
            }

            std::vector<int> result;
            if (cnt1 > nums.size() / 3)
            {
                result.push_back(maj1);
            }
            if (cnt2 > nums.size() / 3)
            {
                result.push_back(maj2);
            }
            return result;
        }
};

void testMajorityElement()
{
    int A1[] = {3,2,3};
    int A2[] = {1,1,1,3,3,2,2,2};
    int A3[] = {1,1,1,2,3,4,5,6};
    std::vector<int> num1(std::begin(A1), std::end(A1));
    std::vector<int> num2(std::begin(A2), std::end(A2));
    std::vector<int> num3(std::begin(A3), std::end(A3));

    Solution s;
    std::vector<int> result1 = s.majorityElement(num1);
    assert(result1.size() == 1 && result1[0] == 3);
    std::vector<int> result2 = s.majorityElement(num2);
    assert(result2.size() == 2 && result2[0] == 1 && result2[1] == 2);
    std::vector<int> result3 = s.majorityElement(num3);
    assert(result3.size() == 1 && result3[0] == 1);
}

int main()
{
    testMajorityElement();
    return 0;
}
