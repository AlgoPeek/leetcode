// Source: https://leetcode.com/problems/median-of-two-sorted-arrays/description/
// Author: Deigo Lee
// Date: 2018-07-10
//
// Description:
// There are two sorted arrays nums1 and nums2 of size m and n respectively.
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//
// Example 1:
// nums1 = [1, 3]
// nums2 = [2]
// The median is 2.0
//
// Example 2:
// nums1 = [1, 2]
// nums2 = [3, 4]
// The median is (2 + 3)/2 = 2.5
//

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

#define countof(A) (sizeof A / sizeof A[0])

using namespace std;

class Solution
{
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
        {
            int m = nums1.size();
            int n = nums2.size();
            if (m > n)
            {
                nums1.swap(nums2);
                std::swap(m, n);
            }

            int left = 0;
            int right = m;
            int half = (m + n + 1) / 2;
            while (left <= right)
            {
                int i = (left + right) / 2;
                int j = half - i;
                if (i < right && nums2[j - 1] > nums1[i])
                {
                    // i is too small
                    left = left + 1;
                }
                else if (i > left && nums1[i - 1] > nums2[j])
                {
                    // i is too big
                    right = right - 1;
                }
                else
                {
                    // find the right i
                    int maxLeft = 0;
                    if (i == 0)
                    {
                        maxLeft = nums2[j - 1];
                    }
                    else if (j == 0)
                    {
                        maxLeft = nums1[i - 1];
                    }
                    else
                    {
                        maxLeft = std::max(nums1[i - 1], nums2[j - 1]);
                    }
                    if ((m + n) % 2 == 1)
                    {
                        return maxLeft;
                    }

                    int minRight = 0;
                    if (i == m)
                    {
                        minRight = nums2[j];
                    }
                    else if (j == n)
                    {
                        minRight = nums1[i];
                    }
                    else
                    {
                        minRight = std::min(nums1[i], nums2[j]);
                    }
                    return (maxLeft + minRight) / 2.0;
                }
            }
            return 0.0;
        }
};

double findMedianSortedArrays(int* A1, int n1, int* A2, int n2)
{
    std::vector<int> nums1(A1, A1 + n1);
    std::vector<int> nums2(A2, A2 + n2);
    return Solution().findMedianSortedArrays(nums1, nums2);
}

int main()
{
    int A1[] = {1, 3};
    int A2[] = {2};
    double result = findMedianSortedArrays(A1, countof(A1), A2, countof(A2));
    assert(2.0 == result);

    int A3[] = {1, 2};
    int A4[] = {3, 4};
    result = findMedianSortedArrays(A3, countof(A3), A4, countof(A4));
    assert(2.5 == result);
    return 0;
}
