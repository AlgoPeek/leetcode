// Source: https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
// Author: Diego Lee
// Date: 2018-07-21
//
// Description:
// You are given a string, s, and a list of words, words, that are all of the same length.
// Find all starting indices of substring(s) in s that is a concatenation of each word in
//  words exactly once and without any intervening characters.
//
//Example 1:
//
//Input:
//  s = "barfoothefoobarman",
//  words = ["foo","bar"]
//Output: [0,9]
//Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
//The output order does not matter, returning [9,0] is fine too.

#include <iostream>
#include <unordered_map>
#include <string>
#include <cassert>
#include <vector>

class Solution
{
    public:
        std::vector<int> findSubstring(std::string s, std::vector<std::string>& words)
        {
            std::vector<int> result;
            if (s.empty() || words.empty())
            {
                return result;
            }

            std::unordered_map<std::string, int> dict;
            for (auto word : words)
            {
                dict[word]++;
            }

            size_t wl = words[0].size();
            size_t sl = words.size() * wl;
            for (size_t i = 0; i < wl; ++i)
            {
                size_t start = i;
                std::unordered_map<std::string, int> tdict;
                for (size_t j = i; j + wl <= s.size(); j += wl)
                {
                    std::string word = s.substr(j, wl);
                    // std::cout << "j=" << j << ", [" << word << "]" << std::endl;
                    if (dict.find(word) != dict.end())
                    {
                        // word is in the dict
                        if (tdict[word] < dict[word])
                        {
                            // increase word count
                            ++tdict[word];

                            if (j - start + wl >= sl)
                            {
                                // find one result
                                // std::cout << "push one, start=" << start << ", j=" << j << std::endl;
                                result.push_back(start);
                                --tdict[s.substr(start, wl)];
                                start += wl;
                            }
                        }
                        else
                        {
                            // increase word count
                            ++tdict[word];

                            // word count exceed the limit
                            for (int k = start; k < j; k += wl)
                            {
                                std::string tword = s.substr(k, wl);
                                --tdict[tword];
                                if (tword == word)
                                {
                                    start = k + wl;
                                    break;
                                }
                            }
                        }
                    }
                    else
                    {
                        // reset
                        tdict.clear();
                        start = j + wl;
                    }
                }
            }
            return result;
        }
};

void testFindSubstring()
{
    std::vector<std::string> words;
    words.push_back("foo");
    words.push_back("bar");

    Solution s;
    int R1[] = {0, 9};
    assert(s.findSubstring("barfoothefoobarman", words) == std::vector<int>(std::begin(R1), std::end(R1)));

    int R2[] = {6, 9, 12};
    words.clear();
    words.push_back("bar");
    words.push_back("foo");
    words.push_back("the");
    assert(s.findSubstring("barfoofoobarthefoobarman", words) == std::vector<int>(std::begin(R2), std::end(R2)));

    words.clear();
    words.push_back("word");
    words.push_back("good");
    words.push_back("best");
    words.push_back("word");
    assert(s.findSubstring("wordgoodgoodgoodbestword", words) == std::vector<int>());

    words.clear();
    words.push_back("fooo");
    words.push_back("barr");
    words.push_back("wing");
    words.push_back("ding");
    words.push_back("wing");
    assert(s.findSubstring("lingmindraboofooowingdingbarrwingmonkeypoundcake", words) == std::vector<int>(1, 13));

    words.clear();
    words.push_back("ab");
    words.push_back("ba");
    words.push_back("ba");
    assert(s.findSubstring("ababaab", words) == std::vector<int>(1, 1));
}

int main()
{
    testFindSubstring();
    return 0;
}
