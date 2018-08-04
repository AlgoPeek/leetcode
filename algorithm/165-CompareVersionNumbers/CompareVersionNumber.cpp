// Source: https://leetcode.com/problems/compare-version-numbers/description/
// Author: Diego Lee
// Date: 2018-08-04
//
// Description:
// Compare two version numbers version1 and version2.
// If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.
//
// You may assume that the version strings are non-empty and contain only digits and the . character.
// The . character does not represent a decimal point and is used to separate number sequences.
// For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
//
// Example 1:
//
// Input: version1 = "0.1", version2 = "1.1"
// Output: -1
// Example 2:
//
// Input: version1 = "1.0.1", version2 = "1"
// Output: 1
// Example 3:
//
// Input: version1 = "7.5.2.4", version2 = "7.5.3"
// Output: -1

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>

std::vector<std::string> split(const std::string& str, char seperator)
{
    std::vector<std::string> segs;
    std::stringstream is(str);
    std::string seg;
    while (std::getline(is, seg, seperator))
    {
        segs.push_back(seg);
    }
    return segs;
}

class Solution
{
    public:
        int compareVersion(const std::string& v1, const std::string& v2)
        {
            std::vector<std::string> segs1 = split(v1, '.');
            std::vector<std::string> segs2 = split(v2, '.');

            size_t size1 = segs1.size();
            size_t size2 = segs2.size();
            size_t minsize = std::min(size1, size2);
            for (size_t i = 0; i < minsize; ++i)
            {
                int i1 = atoi(segs1[i].c_str());
                int i2 = atoi(segs2[i].c_str());
                if (i1 != i2)
                {
                    return i1 > i2 ? 1 : -1;
                }
            }

            for (size_t i = minsize; i < size1; ++i)
            {
                int i1 = atoi(segs1[i].c_str());
                if (i1 != 0) {
                    return 1;
                }
            }
            for (size_t i = minsize; i < size2; ++i)
            {
                int i2 = atoi(segs2[i].c_str());
                if (i2 != 0)
                {
                    return -1;
                }
            }
            return 0;
        }
};

void testSplit()
{
    std::string str = "1.2.3";
    std::vector<std::string> segs = split(str, '.');
    assert(3 == segs.size());
    assert(segs[0] == "1");
    assert(segs[1] == "2");
    assert(segs[2] == "3");
}

void testSolution()
{
    Solution s;

    std::string v1 = "1.2";
    std::string v2 = "1.2.3";
    assert(-1 == s.compareVersion(v1, v2));

    v1 = "0.1";
    v2 = "0.2";
    assert(-1 == s.compareVersion(v1, v2));

    v1 = "0.1";
    v2 = "0.1";
    assert(0 == s.compareVersion(v1, v2));

    v1 = "1";
    v2 = "0";
    assert(1 == s.compareVersion(v1, v2));

    v1 = "01";
    v2 = "1";
    assert(0 == s.compareVersion(v1, v2));

    v1 = "1.0";
    v2 = "1.2";
    assert(-1 == s.compareVersion(v1, v2));

    v1 = "1.2";
    v2 = "1.10";
    assert(-1 == s.compareVersion(v1, v2));

    v1 = "1.0";
    v2 = "1";
    assert(0 == s.compareVersion(v1, v2));
};

int main()
{
    testSplit();
    testSolution();
    return 0;
}
