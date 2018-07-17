// Source: https://leetcode.com/problems/multiply-strings/description/
// Author: Diego Lee
// Date: 2018-07-17
//
// Description:
// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
//
// Example 1:
// Input: num1 = "2", num2 = "3"
// Output: "6"
//
// Example 2:
// Input: num1 = "123", num2 = "456"
// Output: "56088"
//
// Note:
// The length of both num1 and num2 is < 110.
// Both num1 and num2 contain only digits 0-9.
// Both num1 and num2 do not contain any leading zero, except the number 0 itself.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

class Solution
{
    public:
        std::string multiply(std::string num1, std::string num2)
        {
            if (num1.empty() || num2.empty())
            {
                return "";
            }

            std::string result = "0";
            for (int i = 0; i < num1.size(); ++i)
            {
                std::string partResult;
                if (num1[i] != '0')
                {
                    int j = static_cast<int>(num2.size()) - 1;
                    int carry = 0;
                    while (j >= 0 || carry > 0)
                    {
                        int multi = carry;
                        if (j >= 0)
                        {
                            multi += (num1[i] - '0') * (num2[j--] - '0');
                        }
                        carry = multi / 10;
                        multi %= 10;
                        partResult.push_back(multi + '0');
                    }
                }
                else
                {
                    partResult.push_back(num1[i]);
                }

                reverseString(partResult);
                if (partResult != "0")
                {
                    int countZero  = num1.size() - i - 1;
                    while (countZero-- > 0)
                    {
                        partResult.push_back('0');
                    }
                }
                // std::cout << partResult << std::endl;
                result = add(result, partResult);
            }
            return result;
        }

        std::string add(const std::string& num1, const std::string& num2)
        {
            std::string result;
            int carry = 0;
            int i = static_cast<int>(num1.size()) - 1;
            int j = static_cast<int>(num2.size()) - 1;
            while (i >= 0 || j >= 0 || carry > 0)
            {
                int s = 0;
                if (i >= 0)
                {
                    s += num1[i--] - '0';
                }
                if (j >= 0)
                {
                    s += num2[j--] - '0';
                }
                s += carry;
                carry = s / 10;
                s %= 10;
                result.push_back(s + '0');
            }
            reverseString(result);
            return result;
        }

        void reverseString(std::string& str)
        {
            int left = 0;
            int right = static_cast<int>(str.size() - 1);
            while (left < right)
            {
                std::swap(str[left++], str[right--]);
            }
        }
};

void testMultiply()
{
    Solution s;
    assert(s.multiply("2", "3") == std::string("6"));
    assert(s.multiply("123", "456") == std::string("56088"));
    assert(s.multiply("0", "1001") == std::string("0"));
}

int main()
{
    testMultiply();
    return 0;
}
