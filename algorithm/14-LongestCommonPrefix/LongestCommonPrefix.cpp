// Source: https://leetcode.com/problems/longest-common-prefix/description/
// Author: Diego Lee
// Date: 2018-07-13
//
// Description:
// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".
//
// Example 1:
// Input: ["flower","flow","flight"]
// Output: "fl"
//
// Example 2:
// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
//
// Note:
// All given inputs are in lowercase letters a-z.

#include <iostream>
#include <assert.h>
#include <string>
#include <vector>
#include <limits.h>

class Solution
{
    public:
        std::string longestCommonPrefix(std::vector<std::string>& strs)
        {
            if (strs.empty())
            {
                return "";
            }
            if (strs.size() == 1)
            {
                return strs[0];
            }

            size_t minsize = INT_MAX;
            for (size_t i = 0; i < strs.size(); ++i)
            {
                if (strs[i].size() < minsize) {
                    minsize = strs[i].size();
                }
            }

            std::string comPre;
            for (size_t i = 0; i < minsize; ++i)
            {
                char ch = strs[0][i];
                for (size_t j = 1; j < strs.size(); ++j)
                {
                    if (strs[j][i] != ch)
                    {
                        goto __end;
                    }
                }
                comPre.push_back(ch);
            }

            __end:
            return comPre;
        }
};

void testLongestCommonPrefix()
{
    Solution s;
    std::vector<std::string> strs;
    strs.push_back("1234");
    strs.push_back("123");
    strs.push_back("12345");
    strs.push_back("12");
    std::string r = s.longestCommonPrefix(strs);
    assert(r == "12");
}

int main()
{
    testLongestCommonPrefix();
    return 0;
}
