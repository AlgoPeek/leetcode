// Source: https://leetcode.com/problems/count-and-say/description/
// Author: Diego Lee
// Date: 2018-07-23
//
// Description:
// The count-and-say sequence is the sequence of integers with the first five terms as following:
// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth term of the count-and-say sequence.
//
// Note: Each term of the sequence of integers will be represented as a string.
//
// Example 1:
// Input: 1
// Output: "1"
//
// Example 2:
// Input: 4
// Output: "1211"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>

class Solution
{
    public:
        std::string countAndSay(int n)
        {
            if (n == 0)
            {
                return "";
            }
            if (n == 1)
            {
                return "1";
            }

            std::vector<int> v;
            v.push_back(1);
            for (int i = 2; i <= n; ++i)
            {
                v = calNext(v);
            }
            return vecToStr(v);
        }

    private:
        std::vector<int> calNext(const std::vector<int>& v)
        {
            std::vector<int> vecSay;
            if (v.empty())
            {
                return vecSay;
            }

            int val = v[0];
            int cnt = 1;
            for (size_t i = 1; i < v.size(); ++i)
            {
                if (v[i] == val)
                {
                    ++cnt;
                }
                else
                {
                    vecSay.push_back(cnt);
                    vecSay.push_back(val);
                    val = v[i];
                    cnt = 1;
                }
            }
            vecSay.push_back(cnt);
            vecSay.push_back(val);
            return vecSay;
        }

        std::string vecToStr(const std::vector<int>& v)
        {
            std::stringstream ss;
            for (size_t i = 0; i < v.size(); ++i)
            {
                ss << v[i];
            }
            return ss.str();
        }
};

void testCountAndSay()
{
    Solution s;
    assert(s.countAndSay(1) == "1");
    assert(s.countAndSay(2) == "11");
    assert(s.countAndSay(3) == "21");
    assert(s.countAndSay(4) == "1211");
    assert(s.countAndSay(5) == "111221");
}

int main(void)
{
    testCountAndSay();
    return 0;
}
