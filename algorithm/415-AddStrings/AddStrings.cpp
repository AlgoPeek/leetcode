// Source: https://leetcode.com/problems/add-strings/description/
// Author: Diego Lee
// Date: 2018-08-18
//
// Description:
// Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
//
// Note:
//
// The length of both num1 and num2 is < 5100.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.

#include <iostream>
#include <vector>
#include <string>

class Solution
{
    public:
        std::string addStrings(std::string num1, std::string num2)
        {
            std::string result;
            int i = num1.size() - 1;
            int j = num2.size() - 1;
            int carry = 0;
            while (i >= 0 || j >= 0 || carry > 0)
            {
                int s = carry;
                if (i >= 0)
                {
                    s += num1[i--] - '0';
                }
                if (j >= 0)
                {
                    s += num2[j--] - '0';
                }
                carry = s / 10;
                s %= 10;
                result.push_back('0' + s);
            }
            return reverseString(result);
        }

        std::string reverseString(std::string str)
        {
            int left = 0;
            int right = str.size() - 1;
            while (left < right)
            {
                std::swap(str[left++], str[right--]);
            }
            return str;
        }
};

void testAddStrings()
{
    Solution s;
    std::string result = s.addStrings("1", "9");
    assert(result == "10");
    result = s.addStrings("0", "0");
    assert(result == "0");
}

int main()
{
    testAddStrings();
    return 0;
}
