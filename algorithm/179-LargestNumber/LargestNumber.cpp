// Source: https://leetcode.com/problems/largest-number/description/
// Author: Diego Lee
// Date: 2018-08-10
//
// Description:
// Given a list of non negative integers, arrange them such that they form the largest number.
//
// Example 1:
//
// Input: [10,2]
// Output: "210"
// Example 2:
//
// Input: [3,30,34,5,9]
// Output: "9534330"
// Note: The result may be very large, so you need to return a string instead of an integer.

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cassert>

std::string intToString(int n)
{
    std::stringstream ss;
    ss << n;
    return ss.str();
}

bool greaterCmp(const std::string& lhs, const std::string& rhs)
{
    std::string str1 = lhs + rhs;
    std::string str2 = rhs + lhs;
    return str1 > str2;
}

class Solution
{
    public:
        std::string largestNumber(std::vector<int>& nums)
        {
            if (nums.empty())
            {
                return "";
            }

            std::vector<std::string> vec;
            for (int n : nums)
            {
                vec.push_back(intToString(n));
            }

            std::string result;
            std::sort(vec.begin(), vec.end(), greaterCmp);
            if (vec[0][0] == '0')
            {
                return std::string("0");
            }

            for (std::string str : vec)
            {
                result.append(str);
            }
            std::cout << result << std::endl;
            return result;
        }
};

void testLargestNumber()
{
    int A1[] = {10,2};
    int A2[] = {3,30,34,5,9};
    int A3[] = {0,0};
    int A4[] = {824,8247};
    std::vector<int> num1(std::begin(A1), std::end(A1));
    std::vector<int> num2(std::begin(A2), std::end(A2));
    std::vector<int> num3(std::begin(A3), std::end(A3));
    std::vector<int> num4(std::begin(A4), std::end(A4));

    Solution s;
    assert(s.largestNumber(num1) == std::string("210"));
    assert(s.largestNumber(num2) == std::string("9534330"));
    assert(s.largestNumber(num3) == std::string("0"));
    assert(s.largestNumber(num4) == std::string("8248247"));
}

int main()
{
    testLargestNumber();
    return 0;
}
