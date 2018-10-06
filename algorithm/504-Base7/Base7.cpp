// Source: https://leetcode.com/problems/base-7/description/
// Author: Diego Lee
// Date: 2018-10-06
//
// Desciption:
// Given an integer, return its base 7 string representation.
//
// Example 1:
// Input: 100
// Output: "202"
// Example 2:
// Input: -7
// Output: "-10"
// Note: The input will be in range of [-1e7, 1e7].

#include <iostream>
#include <string>
#include <cassert>

class Solution {
    public:
        std::string convertToBase7(int num) {
            if (num == 0) {
                return "0";
            }

            const int base = 7;
            int sign = (num < 0) ? -1 : 1;
            num = abs(num);

            std::string result;
            while (num > 0) {
                int mod = num % base;
                result.push_back(mod + '0');
                num /= base;
            }
            reverseString(result);
            if (sign == -1) {
                result = "-" + result;
            }
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

void testConvertToBase7() {
    Solution s;
    std::string result = s.convertToBase7(100);
    assert(result == "202");
}

int main() {
    testConvertToBase7();
    return 0;
}
