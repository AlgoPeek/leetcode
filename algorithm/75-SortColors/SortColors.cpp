// Source: https://leetcode.com/problems/sort-colors/description/
// Author: Diego Lee
// Date: 2018-08-11
//
// Description:
// Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//
// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//
// Note: You are not suppose to use the library's sort function for this problem.
//
// Example:
//
// Input: [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Follow up:
//
// A rather straight forward solution is a two-pass algorithm using counting sort.
// First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
// Could you come up with a one-pass algorithm using only constant space?

#include <vector>
#include <iostream>

enum
{
    red = 0,
    white = 1,
    blue = 2
};
class Solution {
    public:
        void sortColors(std::vector<int>& nums)
        {
            if (nums.empty())
            {
                return;
            }

            int redcnt = 0;
            int whitecnt = 0;
            int bluecnt = 0;
            for (int i = 0; i < nums.size(); ++i)
            {
                if (nums[i] == red)
                {
                    ++redcnt;
                }
                else if (nums[i] == white)
                {
                    ++whitecnt;
                }
                else
                {
                    ++bluecnt;
                }
            }

            for (int i = 0; i < redcnt; ++i)
            {
                nums[i] = red;
            }
            for (int i = 0; i < whitecnt; ++i)
            {
                nums[i + redcnt] = white;
            }
            for (int i = 0; i < bluecnt; ++i)
            {
                nums[i + redcnt + whitecnt] = blue;
            }
        }
};

void testSortColors()
{
    int A[] = {2,0,2,1,1,0};
    int R[] = {0,0,1,1,2,2};
    std::vector<int> nums(std::begin(A), std::end(A));

    Solution s;
    s.sortColors(nums);
    assert(nums == std::vector<int>(std::begin(R), std::end(R)));
}

int main()
{
    testSortColors();
    return 0;
}
