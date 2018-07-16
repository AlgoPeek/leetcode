// Source: https://leetcode.com/problems/next-permutation/description/
// Author: Diego Lee
// Date: 2018-07-17
//
// Description:
// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
// The replacement must be in-place and use only constant extra memory.
// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

#include <iostream>
#include <vector>
#include <cassert>

class Solution
{
    public:
        void nextPermutation(std::vector<int>& nums)
        {
            int i = static_cast<int>(nums.size()) - 1;
            while (i > 0)
            {
                if (nums[i - 1] < nums[i])
                {
                    // find first j satisfy nums[j] > nums[i-1]
                    for (int j = static_cast<int>(nums.size()) - 1; j >= i; --j)
                    {
                        if (nums[j] > nums[i-1])
                        {
                            std::swap(nums[i-1], nums[j]);
                            reverseNums(nums, i);
                            return;
                        }
                    }
                }
                --i;
            }
            reverseNums(nums, 0);
        }
    private:
        void reverseNums(std::vector<int>& nums, int start)
        {
            int left = start;
            int right = static_cast<int>(nums.size()) - 1;
            while (left < right)
            {
                std::swap(nums[left++], nums[right--]);
            }
        }
};

void testNextPermutation()
{
    int A1[] = {1, 2, 3};
    int A2[] = {3, 2, 1};
    int A3[] = {1, 1, 5};
    int A4[] = {1, 1};
    int R1[] = {1, 3, 2};
    int R2[] = {1, 2, 3};
    int R3[] = {1, 5, 1};
    int R4[] = {1, 1};
    std::vector<int> nums1(std::begin(A1), std::end(A1));
    std::vector<int> nums2(std::begin(A2), std::end(A2));
    std::vector<int> nums3(std::begin(A3), std::end(A3));
    std::vector<int> nums4(std::begin(A4), std::end(A4));

    Solution s;
    s.nextPermutation(nums1);
    s.nextPermutation(nums2);
    s.nextPermutation(nums3);
    s.nextPermutation(nums4);
    assert(nums1 == std::vector<int>(std::begin(R1), std::end(R1)));
    assert(nums2 == std::vector<int>(std::begin(R2), std::end(R2)));
    assert(nums3 == std::vector<int>(std::begin(R3), std::end(R3)));
    assert(nums4 == std::vector<int>(std::begin(R4), std::end(R4)));
}

int main()
{
    testNextPermutation();
    return 0;
}


