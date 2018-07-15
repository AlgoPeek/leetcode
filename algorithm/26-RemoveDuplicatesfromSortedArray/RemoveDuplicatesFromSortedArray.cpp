// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
// Author: Diego Lee
// Date: 2018-07-15
//
// Description:
// Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
//
// Example 1:
// Given nums = [1,1,2],
// Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
// It doesn't matter what you leave beyond the returned length.
//
// Example 2:
// Given nums = [0,0,1,1,1,2,2,3,3,4],
// Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
// It doesn't matter what values are set beyond the returned length.
// Clarification:
// Confused why the returned value is an integer but your answer is an array?
// Note that the input array is passed in by reference, which means modification to the input array will be known to the caller as well.
// Internally you can think of this:
//
// //nums is passed in by reference. (i.e., without making a copy)
// int len = removeDuplicates(nums);
//
// //any modification to nums in your function would be known by the caller.
// //using the length returned by your function, it prints the first len elements.
// for (int i = 0; i < len; i++) {
//     print(nums[i]);
// }

#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
    public:
        int removeDuplicates(std::vector<int>& nums);
};

int Solution::removeDuplicates(std::vector<int>& nums)
{
    if (nums.size() <= 1)
    {
        return nums.size();
    }

    int pos = 0;
    for (size_t i = 0; i < nums.size() - 1; ++i)
    {
        if (nums[i] != nums[i + 1])
        {
            nums[++pos] = nums[i + 1];
        }
    }
    return pos + 1;
}

void testRemoveDuplicates()
{
    int A[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    std::vector<int> nums(A, A + sizeof(A) / sizeof(int));
    int len = Solution().removeDuplicates(nums);

    std::for_each(nums.begin(), nums.end(), [&](int v){
            std::cout << v << " ";
        });
    std::cout << std::endl;
    std::cout << len << std::endl;
    assert(len == 5);

    int R[] = {0, 1, 2, 3, 4};
    for (int i = 0; i < len; ++i)
    {
        assert(nums[i] == R[i]);
    }
}

int main(void)
{
    testRemoveDuplicates();
    return 0;
}
