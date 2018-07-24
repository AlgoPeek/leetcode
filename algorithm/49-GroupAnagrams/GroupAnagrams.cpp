// Source: https://leetcode.com/problems/group-anagrams/description/
// Author: Diego Lee
// Date: 2018-07-24
//
// Description:
// Given an array of strings, group anagrams together.
//
// Example:
// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
//
// Note:
// All inputs will be in lowercase.
// The order of your output does not matter.

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <unordered_map>

typedef std::vector<std::vector<std::string>> Matrix;

class Solution
{
    public:
        Matrix groupAnagrams(std::vector<std::string>& strs)
        {
            std::unordered_map<std::string, std::vector<std::string>> hash;
            for (auto str : strs)
            {
                std::string key = str;
                std::sort(key.begin(), key.end());
                auto it = hash.find(key);
                if (it != hash.end())
                {
                    it->second.push_back(str);
                }
                else
                {
                    std::vector<std::string> vec;
                    vec.push_back(str);
                    hash[key] = vec;
                }
            }

            Matrix result;
            for (auto it : hash)
            {
                result.push_back(it.second);
            }
            return result;
        }
};

void printMatrix(Matrix& matrix)
{
    for (auto strs : matrix)
    {
        for (auto str : strs)
        {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }
}

void testGroupAnagrams()
{
    char words[][4] =
    {
        "eat", "tea", "tan", "ate", "nat", "bat"
    };
    std::vector<std::string> strs(std::begin(words), std::end(words));
    char R0[][4] = {"bat"};
    char R1[][4] = {"tan", "nat"};
    char R2[][4] = {"eat", "tea", "ate"};

    Solution s;
    Matrix result = s.groupAnagrams(strs);
    // printMatrix(result);
    assert(result.size() == 3);
    assert(result[0] == std::vector<std::string>(std::begin(R0), std::end(R0)));
    assert(result[1] == std::vector<std::string>(std::begin(R1), std::end(R1)));
    assert(result[2] == std::vector<std::string>(std::begin(R2), std::end(R2)));
}

int main()
{
    testGroupAnagrams();
    return 0;
}
