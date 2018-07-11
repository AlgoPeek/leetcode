// Source: https://leetcode.com/problems/add-binary/description/
// Author: Diego Lee
// Date: 2018-07-11
//
// Description:
// Given two binary strings, return their sum (also a binary string).
// The input strings are both non-empty and contains only characters 1 or 0.
//
// Example 1:
// Input: a = "11", b = "1"
// Output: "100"
//
// Example 2:
// Input: a = "1010", b = "1011"
// Output: "10101"
//

#include <iostream>
#include <string>
#include <cassert>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string result;
        int carry = 0;
        int i = static_cast<int>(a.size()) - 1;
        int j = static_cast<int>(b.size()) - 1;
        while (i >= 0 || j >= 0 || carry > 0)
        {
            int s = 0;
            if (i >= 0)
            {
                s += a[i--] - '0';
            }
            if (j >= 0)
            {
                s += b[j--] - '0';
            }
            s += carry;
            carry = s / 2;
            s %= 2;
            result.push_back(s + '0');
        }
        reverseString(result);
        return result;
    }
private:
    void reverseString(std::string& str)
    {
        int left = 0;
        int right = static_cast<int>(str.size()) - 1;
        while (left < right)
        {
            std::swap(str[left++], str[right--]);
        }
    }
};

void testAddBinary()
{
    Solution s;

    std::string a = "11";
    std::string b = "1";
    assert(s.addBinary(a, b) == std::string("100"));

    a = "1010";
    b= "1011";
    assert(s.addBinary(a, b) == std::string("10101"));
}

int main()
{
    testAddBinary();
    return 0;
}
