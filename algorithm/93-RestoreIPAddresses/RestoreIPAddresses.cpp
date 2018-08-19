// Source: https://leetcode.com/problems/restore-ip-addresses/description/
// Author: Diego Lee
// Date: 2018-08-19
//
// Description:
// Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//
// Example:
//
// Input: "25525511135"
// Output: ["255.255.11.135", "255.255.111.35"]

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

class Solution
{
    public:
        std::vector<std::string> restoreIpAddresses(std::string s)
        {
            std::vector<std::string> result;
            std::vector<std::string> curr;
            restoreIpAddresses(s, 0, curr, result);
            return result;
        }

        void restoreIpAddresses(const std::string& s, int i, std::vector<std::string>& curr,
                std::vector<std::string>& result)
        {
            if (curr.size() >= 4)
            {
                // printVector(curr);
                if (i >= s.size())
                {
                    std::string ip = curr[0];
                    for (int i = 1; i < 4; ++i)
                    {
                        ip.append(".");
                        ip.append(curr[i]);
                    }
                    result.push_back(ip);
                }
                return;
            }

            for (int cnt = 1; (cnt <= 3) && (i + cnt <= s.size()); ++cnt)
            {
                std::string part = s.substr(i, cnt);
                if (!isValid(part))
                {
                    continue;
                }

                curr.push_back(part);
                restoreIpAddresses(s, i + cnt, curr, result);
                curr.pop_back();
            }
        }

        bool isValid(const std::string& part)
        {
            if (part.empty() || part.size() > 3)
            {
                return false;
            }

            bool result = false;
            int seg = atoi(part.c_str());
            if (part.size() == 1)
            {
                result = (seg >= 0 && seg <= 9);
            }
            else if (part.size() == 2)
            {
                result = (seg >= 10 && seg <= 99);
            }
            else if (part.size() == 3)
            {
                result = (seg >= 100 && seg <= 255);
            }
            return result;
        }

        void printVector(const std::vector<std::string>& vec)
        {
            for (std::string str : vec)
            {
                std::cout << str << " ";
            }
            std::cout << std::endl;
        }
};

void testRestoreIpAddresses()
{
    Solution s;
    std::vector<std::string> result = s.restoreIpAddresses("25525511135");
    assert(result.size() == 2);
    assert(result[0] == std::string("255.255.11.135"));
    assert(result[1] == std::string("255.255.111.35"));
}

int main()
{
    testRestoreIpAddresses();
    return 0;
}
