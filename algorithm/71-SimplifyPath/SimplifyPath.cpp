// Source: https://leetcode.com/problems/simplify-path/description/
// Author: Diego Lee
// Date: 2018-07-71
// Description:
//
// Given an absolute path for a file (Unix-style), simplify it.
//
// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"
//
// Corner Cases:
//
// Did you consider the case where path = "/../"?
// In this case, you should return "/".
// Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
// In this case, you should ignore redundant slashes and return "/home/foo".

#include <assert.h>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

std::vector<std::string> split(const std::string& src, char delim)
{
    std::stringstream is(src);
    std::string seg;
    std::vector<std::string> segs;
    while (std::getline(is, seg, delim))
    {
        segs.push_back(seg);
    }
    return segs;
}

class Solution
{
    public:
        std::string simplifyPath(const std::string& path)
        {
            std::vector<std::string> tokens = split(path, '/');
            std::vector<std::string> simpleTokens;

            for (size_t i = 0; i < tokens.size(); ++i)
            {
                std::string token = tokens[i];
                if (token == "." || token == "")
                {
                    continue;
                }
                else if (token == "..")
                {
                    if (!simpleTokens.empty())
                    {
                        simpleTokens.pop_back();
                    }
                }
                else
                {
                    simpleTokens.push_back(token);
                }
            }

            std::string simplePath = "/";
            for (size_t i = 0; i < simpleTokens.size(); ++i)
            {
                if (simplePath[simplePath.size() - 1] != '/')
                {
                    simplePath.append("/");
                }
                simplePath.append(simpleTokens[i]);
            }
            return simplePath;
        }
};

void testSplit()
{
    std::string src = "/home/";
    std::vector<std::string> segs = split(src, '/');
    assert(segs.size() == 2);
    assert(segs[0] == "");
    assert(segs[1] == "home");
}

void testSimplifyPath()
{
    Solution s;

    std::string result;
    std::string path = "/home/";
    result = s.simplifyPath(path);
    assert(result == "/home");

    path = "/a/./b/../../c/";
    result = s.simplifyPath(path);
    assert(result == "/c");

    path = "/home/../../../";
    result = s.simplifyPath(path);
    assert(result == "/");

    path = "/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///";
    result = s.simplifyPath(path);
    assert(result == "/e/f/g");
}

int main()
{
    testSplit();
    testSimplifyPath();
    return 0;
}
