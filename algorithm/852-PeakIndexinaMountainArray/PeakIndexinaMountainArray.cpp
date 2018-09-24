// Source: https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
// Author: Diego Lee
// Date: 2018-09-24
//
// Description:
// Let's call an array A a mountain if the following properties hold:
//
// A.length >= 3
// There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
// Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].
//
// Example 1:
//
// Input: [0,1,0]
// Output: 1
// Example 2:
//
// Input: [0,2,1,0]
// Output: 1
// Note:
//
// 3 <= A.length <= 10000
// 0 <= A[i] <= 10^6
// A is a mountain, as defined above.

#include <iostream>
#include <vector>
#include <cassert>

class Solution {
    public:
        int peakIndexInMountainArray(std::vector<int>& A) {
            if (A.size() < 3) {
                return -1;
            }

            int n = A.size();
            int left = 0;
            int right = n - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                // std::cout << "mid=" << mid << std::endl;
                if (mid > 0
                    && mid < n - 1
                    && A[mid] > A[mid - 1]
                    && A[mid] > A[mid + 1]) {
                    return mid;
                }
                else if (mid == 0
                    || A[mid] > A[mid - 1]) {
                    left = mid + 1;
                }
                else if (mid == n - 1
                    || A[mid] > A[mid + 1]) {
                    right = mid - 1;
                }
                else
                {
                    break;
                }
            }
            return -1;
        }
};

void testPeakIndexInMoutainArray() {
    std::vector<int> nums = {0,2,1,0};
    Solution s;
    assert(s.peakIndexInMountainArray(nums) == 1);

    std::vector<int> nums2 = {18,29,38,59,98,100,99,98,90};
    assert(s.peakIndexInMountainArray(nums2) == 5);
}

int main() {
    testPeakIndexInMoutainArray();
    return 0;
}
