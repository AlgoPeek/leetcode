// Source: https://leetcode.com/problems/minimum-window-substring/description/
// Author: Diego Lee
// Date: 2018-08-25
//
// Description:
// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//
// Example:
//
// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"
// Note:
//
// If there is no such window in S that covers all characters in T, return the empty string "".
// If there is such window, you are guaranteed that there will always be only one unique minimum window in S.

#include <iostream>
#include <vector>
#include <string>

class Solution
{
    public:
        std::string minWindow(std::string s, std::string t)
        {
            std::vector<char> map(128);
            for (char c : t)
            {
                ++map[c];
            }

            int counter = t.size();
            int begin = 0, end = 0, head = 0;
            int d = INT_MAX;
            while (end < s.size())
            {
                if (map[s[end++]]-- > 0)
                {
                    --counter;
                }

                // find a valid substr
                // std::cout << "counter=" << counter << ", i=" << end << std::endl;
                while (counter == 0)
                {
                    if (end - begin < d)
                    {
                        d = end - begin;
                        head = begin;
                        // std::cout << "end=" << end << ", begin=" << begin << ", distance=" << distance << std::endl;
                    }

                    // make it invalid
                    if (map[s[begin++]]++ == 0)
                    {
                        ++counter;
                    }
                }
            }
            return (d == INT_MAX) ? "" : s.substr(head, d);
        }
};

void testMinWindow()
{
    Solution s;
    std::string result = s.minWindow("ADOBECODEBANC", "ABC");
    assert(result == std::string("BANC"));
}

int main()
{
    testMinWindow();
    return 0;
}
