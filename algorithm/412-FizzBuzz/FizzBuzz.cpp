// Source: https://leetcode.com/problems/fizz-buzz/description/
// Author: Diego Lee
// Date: 2018-08-28
//
// Description:
// Write a program that outputs the string representation of numbers from 1 to n.
//
// But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.
//
// Example:
//
// n = 15,
//
// Return:
// [
//     "1",
//     "2",
//     "Fizz",
//     "4",
//     "Buzz",
//     "Fizz",
//     "7",
//     "8",
//     "Fizz",
//     "Buzz",
//     "11",
//     "Fizz",
//     "13",
//     "14",
//     "FizzBuzz"
// ]

#include <iostream>
#include <sstream>
#include <string>
#include <cassert>
#include <vector>

class Solution
{
    public:
        std::vector<std::string> fizzBuzz(int n)
        {
            std::vector<std::string> result;
            for (int i = 1; i <= n; ++i)
            {
                std::string curr;
                if (i % 3 == 0)
                {
                    curr += "Fizz";
                }
                if (i % 5 == 0)
                {
                    curr += "Buzz";
                }
                if (curr.empty())
                {
                    curr = intToStr(i);
                }
                result.push_back(curr);
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

void testFizzBuzz()
{
    Solution s;
    std::vector<std::string> result = s.fizzBuzz(5);
    assert(result.size() == 5);
    assert(result[0] == "1");
    assert(result[1] == "2");
    assert(result[2] == "Fizz");
    assert(result[3] == "4");
    assert(result[4] == "Buzz");
}

int main()
{
    testFizzBuzz();
    return 0;
}
