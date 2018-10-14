// Source: https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/
// Author: Diego Lee
// Date: 2010-10-14
//
// Description:
// Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two’s complement method is used.
//
// Note:
//
// All letters in hexadecimal (a-f) must be in lowercase.
// The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise, the first character in the hexadecimal string will not be the zero character.
// The given number is guaranteed to fit within the range of a 32-bit signed integer.
// You must not use any method provided by the library which converts/formats the number to hex directly.
// Example 1:
//
// Input:
// 26
//
// Output:
// "1a"
// Example 2:
//
// Input:
// -1
//
// Output:
// "ffffffff"

#include <iostream>
#include <string>

class Solution {
    public:
        std::string toHex(int num) {
            if (num == 0) {
                return "0";
            }

            const char hash[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
            unsigned n = num;
            std::string result;
            while (n != 0) {
                result.push_back(hash[n & 0x0f]);
                n >>= 4;
            }
            reverseString(result);
            return result;
        }

        void reverseString(std::string& str) {
            int left = 0;
            int right = str.size() - 1;
            while (left < right) {
                std::swap(str[left++], str[right--]);
            }
        }
};

void testToHex(void) {
    Solution s;
    assert(s.toHex(26) == "1a");
    assert(s.toHex(-1) == "ffffffff");
}

int main() {
    testToHex();
    return 0;
}
