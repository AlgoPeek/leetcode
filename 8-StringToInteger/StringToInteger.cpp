// Source: https://leetcode.com/problems/string-to-integer-atoi/description/
// Author: Diego Lee
// Date: 2018-07-10
//
// Descrition:
// Implement atoi which converts a string to an integer.
// The function first discards as many whitespace characters as necessary until the first
// non-whitespace character is found. Then, starting from this character, takes an optional
// initial plus or minus sign followed by as many numerical digits as possible, and interprets
// them as a numerical value.
//
// The string can contain additional characters after those that form the integral number,
// which are ignored and have no effect on the behavior of this function.
//
// If the first sequence of non-whitespace characters in str is not a valid integral number,
// or if no such sequence exists because either str is empty or it contains only whitespace
// cores characters, no conversion is performed.
//
// If no valid conversion could be performed, a zero value is returned.
//
// Note:
// Only the space character ' ' is considered as whitespace character.
// Assume we are dealing with an environment which could only store integers within the 32-bit
// signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable
// values, INT_MAX (2^31 − 1) or INT_MIN (−2^31) is returned.
//
// Example 1:
// Input: "42"
// Output: 42
//
// Example 2:
// Input: "   -42"
// Output: -42
// Explanation: The first non-whitespace character is '-', which is the minus sign.
// Then take as many numerical digits as possible, which gets 42.
//
// Example 3:
// Input: "4193 with words"
// Output: 4193
// Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
//
// Example 4:
// Input: "words and 987"
// Output: 0
// Explanation: The first non-whitespace character is 'w', which is not a numerical
// digit or a +/- sign. Therefore no valid conversion could be performed.
//
// Example 5:
// Input: "-91283472332"
// Output: -2147483648
// Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
// Thefore INT_MIN (−2^31) is returned.
//

#include <assert.h>
#include <iostream>
#include <string>
#include <limits.h>
#include <algorithm>

class Solution {
    public:
        int atoi(const std::string& str) {
            size_t pos = 0;
            while (pos < str.size() && str[pos] == ' ') {
                ++pos;
            }
            std::string _str = str.substr(pos);
            if (_str.empty()) {
                return 0;
            }

            char ch = _str[0];
            size_t i = 0;
            int sign = 1;
            if (ch == '+') {
                sign = 1;
                ++i;
            }
            else if (ch == '-'){
                sign = -1;
                ++i;
            }

            double r = 0;
            for (; i < _str.size() && isDigit(_str[i]); ++i) {
                r = r * 10  + _str[i] - '0';
            }
            r *= sign;
            r = std::min(r, (double)INT_MAX);
            r = std::max(r, (double)INT_MIN);
            return (int)r;
        }

    private:
        bool isDigit(char ch) {
            return ch >= '0' && ch <= '9';
        }
};

void testAtoi() {
    Solution s;
    int r = s.atoi("123");
    assert(123 == r);

    r = s.atoi("0");
    assert(0 == r);

    r = s.atoi("-123");
    assert(-123 == r);

    r = s.atoi("  +123");
    assert(123 == r);

    r = s.atoi("+-2");
    assert(0 == r);

    r = s.atoi("2147483648");
    assert(INT_MAX == r);

    r = s.atoi("-2147483648");
    assert(INT_MIN == r);

    r = s.atoi("-0012a42");
    //	std::cout << r << std::endl;
    assert(-12 == r);
}

int main() {
    testAtoi();
    return 0;
}
