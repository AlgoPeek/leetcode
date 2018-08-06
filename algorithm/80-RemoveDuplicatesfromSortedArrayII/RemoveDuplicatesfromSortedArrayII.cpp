// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
// Author: Dieogo Lee
// Date: 2018-08-06
//
// Description:
// Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.
//
// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
//
// Example 1:
//
// Given nums = [1,1,1,2,2,3],
//
// Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
//
// It doesn't matter what you leave beyond the returned length.
// Example 2:
//
// Given nums = [0,0,1,1,1,1,2,3,3],
//
// Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.
//
// It doesn't matter what values are set beyond the returned length.
// Clarification:
//
// Confused why the returned value is an integer but your answer is an array?
//
// Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.
//
// Internally you can think of this:
//
// // nums is passed in by reference. (i.e., without making a copy)
// int len = removeDuplicates(nums);
//
// // any modification to nums in your function would be known by the caller.
// // using the length returned by your function, it prints the first len elements.
// for (int i = 0; i < len; i++) {
//     print(nums[i]);
// }

#include <iostream>
#include <vector>
#include <cassert>

#define countof(A) (sizeof A / sizeof A[0])

class Solution
{
    public:
        int removeDuplicates(std::vector<int>& nums)
        {
            if (nums.size() <= 2)
            {
                return nums.size();
            }

            int pos = 1;
            for (int i = 2; i < nums.size(); ++i)
            {
                if (nums[i] != nums[pos]
                    || nums[i] != nums[pos-1])
                {
                    nums[++pos] = nums[i];
                }
            }
            return pos + 1;
        }
};

bool isEqual(int* A1, int* A2, int n)
{
    for (int i = 0; i < n; ++i)
    {
        if(A1[i] != A2[i])
        {
            std::cout <<"i=" << i << ", A1[i]=" << A1[i] << ", A2[i]=" << A2[i] << std::endl;
            return false;
        }
    }
    return true;
}

void printVector(const std::vector<int>& vec)
{
    for (auto i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void testRemoveDuplicates()
{
    int A1[] = {1,1,1,2,2,3};
    int A2[] = {0,0,1,1,1,1,2,3,3};
    int R1[] = {1,1,2,2,3};
    int R2[] = {0,0,1,1,2,3,3};
    std::vector<int> nums1(std::begin(A1), std::end(A1));
    std::vector<int> nums2(std::begin(A2), std::end(A2));

    Solution s;
    int result = s.removeDuplicates(nums1);
    // printVector(nums1);
    assert(result == 5);
    assert(isEqual(nums1.data(), R1, countof(R1)));

    result = s.removeDuplicates(nums2);
    // printVector(nums2);
    assert(result == 7);
    assert(isEqual(nums2.data(), R2, countof(R2)));
}

int main()
{
    testRemoveDuplicates();
    return 0;
}
