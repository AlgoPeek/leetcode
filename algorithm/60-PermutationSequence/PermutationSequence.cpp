// Source: https://leetcode.com/problems/permutation-sequence/description/
// Author: Diego Lee
// Date: 2018-07-26
//
// Description:
// The set [1,2,3,...,n] contains a total of n! unique permutations.
// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
//
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.
//
// Note:
//
// Given n will be between 1 and 9 inclusive.
// Given k will be between 1 and n! inclusive.
// Example 1:
//
// Input: n = 3, k = 3
// Output: "213"
// Example 2:
//
// Input: n = 4, k = 9
// Output: "2314"

#include <iostream>
#include <string>
#include <cassert>
#include <sstream>
#include <vector>

class Solution
{
    public:
        std::string getPermutation(int n, int k)
        {
            std::vector<int> factorial(n + 1);
            std::vector<int> nums(n);
            int sum = 1;
            factorial[0] = 1;
            for (int i = 1; i <= n; ++i)
            {
                sum *= i;
                factorial[i] = sum;
                nums[i - 1] = i;
            }

            std::string result;
            k -= 1;
            for (int i = 1; i <= n; ++i)
            {
                int j = k / factorial[n - i];
                result.append(intToStr(nums[j]));
                nums.erase(nums.begin() + j);
                k -= j * factorial[n - i];
            }
            return result;
        }

        std::string intToStr(int n)
        {
            std::stringstream ss;
            ss << n;
            return ss.str();
        }
};

void testGetPermutation()
{
    Solution s;
    assert(s.getPermutation(3, 3) == std::string("213"));
}

int main()
{
    testGetPermutation();
    return 0;
}

